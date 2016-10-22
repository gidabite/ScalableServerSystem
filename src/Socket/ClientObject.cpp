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

ClientObject::~ClientObject() {
	// TODO Auto-generated destructor stub
}

