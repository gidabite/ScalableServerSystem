/*
 * HandlerComponent.cpp
 *
 *  Created on: 13.05.2017
 *      Author: gidabite
 */

#include "HandlerComponent.h"
#include "iostream"

HandlerComponent::HandlerComponent() {

}

void HandlerComponent::go() {
	m_thr = new thread(run);
}

HandlerComponent::~HandlerComponent() {
}

HandlerComponent& HandlerComponent::init(){

	static HandlerComponent InpComp;
	return InpComp;

}

void HandlerComponent::join() {
	m_thr->join();
	delete m_thr;
}

void HandlerComponent::run() {
	//ClientMeneger::init(INET, "192.168.43.215:45678");
	//ClientMeneger cm(INET, "192.168.43.215:45678");//"192.168.1.45:45678");
	cout << "Start Handler Component" << endl;
	while (true) {
		std::unordered_map<uint32_t, ClientObject*> clients = ClientMeneger::init()->getClient();
		for (auto it = clients.begin(); it != clients.end(); it++){
			vector<InputState>* inpSt =  it->second->getInputState();
			while (inpSt->size() != 0){
				switch(inpSt->at(0).getState()){
					case IS_CREATE:{
						it->second->GetObj()->setIsChanged(true);
					}
				}
				inpSt->erase(inpSt->begin());
			}
		}
	}
}

