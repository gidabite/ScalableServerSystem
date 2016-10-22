/*
 * GameObject.cpp
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#include "BaseObject.h"

uint32_t BaseObject::classId = 1;

BaseObject::BaseObject(Vector3 pos, Vector3 rot, Vector3 sc){
	this->mPosition = pos;
	this->mRotation = rot;
	this->mScale = sc;
}
BaseObject::BaseObject(Position pos, Rotation rot, Scale sc){
	this->mPosition = pos;
	this->mRotation = rot;
	this->mScale = sc;
}
void BaseObject::Serialize(OutMemoryBitStream& out){
	out.Write(mPosition.x);
	out.Write(mPosition.y);
	out.Write(mPosition.z);
	out.Write(mRotation.x);
	out.Write(mRotation.y);
	out.Write(mRotation.z);
	out.Write(mScale.x);
	out.Write(mScale.y);
	out.Write(mScale.z);
}

BaseObject::~BaseObject() {
	// TODO Auto-generated destructor stub
}

