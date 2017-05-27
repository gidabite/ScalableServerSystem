/*
 * HandlerComponent.cpp
 *
 *  Created on: 13.05.2017
 *      Author: gidabite
 */

#include "HandlerComponent.h"
#include "iostream"

bool HandlerComponent::isRun = true;

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
	while (isRun) {
		std::unordered_map<uint32_t, ClientObject*> clients = ClientMeneger::init()->getClient();
		for (auto it = clients.begin(); it != clients.end(); it++){
			if (it->second != nullptr){
				while (it->second->isBlock) {usleep(2000);};
				it->second->isBlock = true;

				vector<InputState>* inpSt =  it->second->getInputState();

				for (auto itSt= inpSt->begin(); itSt != inpSt->end(); itSt++){
						switch(itSt->getState()){
							case IS_CREATE:{
								it->second->GetObj()->setIsChanged(true);
								break;
							}
							case IS_CHANGE:{
								if (!(it->second->GetObj()->getPosition() == itSt->getPos()) || !(it->second->GetObj()->getRotation()== itSt->getRot())  || !(it->second->GetObj()->getScale() == itSt->getSc())) {
									it->second->GetObj()->setPosition(itSt->getPos());
									it->second->GetObj()->setRotation(itSt->getRot());
									it->second->GetObj()->setScale(itSt->getSc());
									it->second->GetObj()->setIsChanged(true);
								}
								break;
							}
						}

				}
				inpSt->clear();

				it->second->isBlock = false;
			}
		}
	}
	return;
}

void HandlerComponent::Cancel() {
	isRun = false;
}
