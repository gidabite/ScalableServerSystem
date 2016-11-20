/*
 * ClientObject.cpp
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#include "ClientObject.h"
#include "../GameObject/BaseObject.h"
ClientObject::ClientObject(){

}

void ClientObject::AssociatedWhitObject(BaseObject* obj){
	this->obj = obj;
}

void ClientObject::setNetworkId(uint32_t networkID){
	this->mNetworkId = networkID;
}
void ClientObject::addInputState(InputState ins){
	this->mInput.push_back(ins);
}
ClientObject::~ClientObject() {
	// TODO Auto-generated destructor stub
}

