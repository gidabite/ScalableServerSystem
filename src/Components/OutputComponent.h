/*
 * OutputComponent.h
 *
 *  Created on: 13.05.2017
 *      Author: gidabite
 */

#ifndef COMPONENTS_OUTPUTCOMPONENT_H_
#define COMPONENTS_OUTPUTCOMPONENT_H_

#include <thread>
#include "../Socket/SocketUtil.h"
#include "../Socket/UDPSocket.h"
#include "../Socket/SocketAddressFactory.h"
#include "../Socket/Pocket.h"
#include "../Socket/ClientObject.h"
#include "../Socket/ClientMeneger.h"

class OutputComponent {

public:
	static OutputComponent& init();
	void go();
	void join();
private:
	thread* m_thr;
	static void run();
	OutputComponent();
	virtual ~OutputComponent();

	OutputComponent(OutputComponent const&) = delete;
	OutputComponent& operator= (OutputComponent const&) = delete;
};

#endif /* COMPONENTS_OUTPUTCOMPONENT_H_ */
