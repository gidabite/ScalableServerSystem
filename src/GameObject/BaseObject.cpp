/*
 * GameObject.cpp
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#include "BaseObject.h"

BaseObject::BaseObject(Vector3 pos, Vector3 rot, Vector3 sc){
	this->position = pos;
	this->rotation = rot;
	this->scale = sc;
}
BaseObject::BaseObject(Position pos, Rotation rot, Scale sc){
	this->position = pos;
	this->rotation = rot;
	this->scale = sc;
}
void BaseObject::Serialization(OutMemoryBitStream& out){
	out.Write(position.x);
	out.Write(position.y);
	out.Write(position.z);
	out.Write(rotation.x);
	out.Write(rotation.y);
	out.Write(rotation.z);
	out.Write(scale.x);
	out.Write(scale.y);
	out.Write(scale.z);
}

BaseObject::~BaseObject() {
	// TODO Auto-generated destructor stub
}

