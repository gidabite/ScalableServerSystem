/*
 * GameObject.h
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#ifndef GAMEOBJECT_BASEOBJECT_H_
#define GAMEOBJECT_BASEOBJECT_H_S

#include "../PhysicalParameters/Position.h";
#include "../PhysicalParameters/Rotation.h";
#include "../PhysicalParameters/Scale.h";
#include "../Socket/OutMemoryBitStream.h"

class BaseObject {
public:
	BaseObject(Vector3 pos, Vector3 rot, Vector3 sc);
	BaseObject(Position pos, Rotation rot, Scale sc);
	virtual void Serialization(OutMemoryBitStream& out);
	virtual ~BaseObject();
private:
	Position position;
	Rotation rotation;
	Scale scale;
};

#endif /* GAMEOBJECT_BASEOBJECT_H_ */
