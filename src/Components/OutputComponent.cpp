/*
 * OutputComponent.cpp
 *
 *  Created on: 13.05.2017
 *      Author: gidabite
 */

#include "OutputComponent.h"

OutputComponent::OutputComponent() {

}

void OutputComponent::go() {
	m_thr = new thread(run);
}

OutputComponent::~OutputComponent() {
}

OutputComponent& OutputComponent::init(){

	static OutputComponent InpComp;
	return InpComp;

}

void OutputComponent::join() {
	m_thr->join();
	delete m_thr;
}

void OutputComponent::run() {
	//ClientMeneger::init(INET, "192.168.43.215:45678");
	//ClientMeneger cm(INET, "192.168.43.215:45678");//"192.168.1.45:45678");
	cout << "Start Output Component" << endl;
	while (true) {
		std::unordered_map<uint32_t, ClientObject*> clients = ClientMeneger::init()->getClient();
		for (auto it = clients.begin(); it != clients.end(); it++){
			Pocket pocket(PT_REPDATA);
			if (it->second->GetObj() && it->second->GetObj()->isIsChanged()){
				pocket.AddObject(it->second->GetObj());
				ClientMeneger::init()->getSocket()->SendTo(pocket.GetStream().GetBufferPtr(), pocket.GetStream().GetByteLength(), it->second->GetAddress());
				it->second->GetObj()->setIsChanged(false);
			}
		}
	}
}
