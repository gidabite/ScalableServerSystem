/*
 * OutputComponent.cpp
 *
 *  Created on: 13.05.2017
 *      Author: gidabite
 */

#include "OutputComponent.h"

bool OutputComponent::isRun = true;

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
	while (isRun) {
		std::unordered_map<uint32_t, ClientObject*> clients = ClientMeneger::init()->getClient();


		Pocket forNewClients(PocketType::PT_REPDATA);
		for (auto it = clients.begin(); it != clients.end(); it++){
			if (it->second != nullptr){
				if (it->second->GetObj()){
					forNewClients.AddObject(it->second->GetObj());
					//ClientMeneger::init()->getSocket()->SendTo(pocket.GetStream().GetBufferPtr(), pocket.GetStream().GetByteLength(), it->second->GetAddress());
				}
			}
		}
		for (auto it = clients.begin(); it != clients.end(); it++){
			if (it->second != nullptr){
				if (it->second->isJustCreated){
					Pocket pocket(PocketType::PT_WELC);
					if (it->second->GetObj()){
						pocket.AddObject(it->second->GetObj());
						ClientMeneger::init()->getSocket()->SendTo(pocket.GetStream().GetBufferPtr(), pocket.GetStream().GetByteLength(), it->second->GetAddress());
					}
					ClientMeneger::init()->getSocket()->SendTo(forNewClients.GetStream().GetBufferPtr(), forNewClients.GetStream().GetByteLength(), it->second->GetAddress());
				}
			}
		}


		Pocket forOldClients(PocketType::PT_REPDATA);
		int count = 0;
		for (auto it = clients.begin(); it != clients.end(); it++){
			if (it->second != nullptr){
				if (it->second->GetObj() && (it->second->GetObj()->isIsChanged()) || it->second->isJustCreated){
					count++;
					forOldClients.AddObject(it->second->GetObj());
					it->second->GetObj()->setIsChanged(false);
				}
			}
		}
		if (count != 0){
			for (auto it = clients.begin(); it != clients.end(); it++){
				if (it->second != nullptr){
					if (!it->second->isJustCreated)
						ClientMeneger::init()->getSocket()->SendTo(forOldClients.GetStream().GetBufferPtr(), forOldClients.GetStream().GetByteLength(), it->second->GetAddress());
					else it->second->isJustCreated = false;
				}
			}
		}


		//for (auto it = clients.begin(); it != clients.end(); it++){
		//	if (it->second != nullptr){
        //
		//		if (it->second->isJustCreated){
		//			it->second->isJustCreated = false;
		//			Pocket pocket(PocketType::PT_WELC);
		//			if (it->second->GetObj()){
		//				pocket.AddObject(it->second->GetObj());
		//				ClientMeneger::init()->getSocket()->SendTo(pocket.GetStream().GetBufferPtr(), pocket.GetStream().GetByteLength(), it->second->GetAddress());
		//			}
		//		}
		//		for (auto itF = clients.begin(); itF != clients.end(); itF++){
		//			if (itF->second != nullptr && itF != it){
		//				Pocket pocket(PocketType::PT_REPDATA);
		//				if (itF->second->GetObj()){
		//					pocket.AddObject(itF->second->GetObj());
		//					ClientMeneger::init()->getSocket()->SendTo(pocket.GetStream().GetBufferPtr(), pocket.GetStream().GetByteLength(), it->second->GetAddress());
		//				}
		//			}
		//		}
        //
		//	}
		//}
		usleep(1000);
	}
}

void OutputComponent::Cancel() {
	this->isRun = false;
}
