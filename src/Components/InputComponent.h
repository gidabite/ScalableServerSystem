/*
 * InputComponent.h
 *
 *  Created on: 17.02.2017
 *      Author: gidabite
 */

#ifndef COMPONENTS_INPUTCOMPONENT_H_
#define COMPONENTS_INPUTCOMPONENT_H_

#include <thread>
#include "../Socket/SocketUtil.h"
#include "../Socket/UDPSocket.h"
#include "../Socket/SocketAddressFactory.h"
#include "../Socket/Pocket.h"
#include "../Socket/ClientObject.h"
#include "../Socket/ClientMeneger.h"

using namespace std;

class InputComponent {
public:

	static InputComponent& init();
	void go();
	void join();
private:
	thread* m_thr;
	static void run();
	InputComponent();
	virtual ~InputComponent();

	InputComponent(InputComponent const&) = delete;
	InputComponent& operator= (InputComponent const&) = delete;
};

#endif /* COMPONENTS_INPUTCOMPONENT_H_ */
