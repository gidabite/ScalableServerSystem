/*
 * HandlerComponent.h
 *
 *  Created on: 13.05.2017
 *      Author: gidabite
 */

#ifndef COMPONENTS_HANDLERCOMPONENT_H_
#define COMPONENTS_HANDLERCOMPONENT_H_


#include <thread>
#include "../Socket/ClientObject.h"
#include "../Socket/ClientMeneger.h"

using namespace std;

class HandlerComponent {
public:
	static HandlerComponent& init();
	void go();
	void join();
private:
	thread* m_thr;
	static void run();
	HandlerComponent();
	virtual ~HandlerComponent();

	HandlerComponent(HandlerComponent const&) = delete;
	HandlerComponent& operator= (HandlerComponent const&) = delete;
};

#endif /* COMPONENTS_HANDLERCOMPONENT_H_ */
