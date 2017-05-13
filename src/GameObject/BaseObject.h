/*
 * GameObject.h
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#ifndef GAMEOBJECT_BASEOBJECT_H_
#define GAMEOBJECT_BASEOBJECT_H_S

#include "../PhysicalParameters/Position.h"
#include "../PhysicalParameters/Rotation.h"
#include "../PhysicalParameters/Scale.h"
#include "../Socket/OutMemoryBitStream.h"



class BaseObject {
public:
	static uint32_t classId;
	BaseObject(Vector3 pos, Vector3 rot, Vector3 sc);
	BaseObject(Position pos, Rotation rot, Scale sc);
	virtual void Serialize(OutMemoryBitStream& out);
	virtual ~BaseObject();

	bool isIsChanged() const {
		return isChanged;
	}

	void setIsChanged(bool isChanged) {
		this->isChanged = isChanged;
	}

private:
	Position mPosition;
	Rotation mRotation;
	Scale mScale;
	bool isChanged = false;

};

#endif /* GAMEOBJECT_BASEOBJECT_H_ */
