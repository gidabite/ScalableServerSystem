/*
 * InputComponent.cpp
 *
 *  Created on: 17.02.2017
 *      Author: gidabite
 */

#include "InputComponent.h"
#include "iostream"

bool InputComponent::isRun = true;

InputComponent::InputComponent() {

}

void InputComponent::go() {
	m_thr = new thread(run);
}

InputComponent::~InputComponent() {
}

InputComponent& InputComponent::init(){

	static InputComponent InpComp;
	return InpComp;

}

void InputComponent::join() {
	m_thr->join();
	delete m_thr;
}

void InputComponent::run() {
	//ClientMeneger::init(INET, "192.168.43.215:45678");
	//ClientMeneger cm(INET, "192.168.43.215:45678");//"192.168.1.45:45678");
	cout << "Start Input Component" << endl;
	int i = 0;
	while (isRun) {
		//for (int i = 0; i < 15; i ++){
			ClientMeneger::init()->Wait();
		//}
		usleep(30000);
	}
}

void InputComponent::Cancel() {
	this->isRun = false;
}
