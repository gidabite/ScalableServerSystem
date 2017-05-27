/*
 * Rotation.cpp
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#include "Rotation.h"

Rotation::Rotation(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
};
Rotation::Rotation(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
};

void Rotation::operator =(Rotation pos)
{
	this->x = pos.x;
	this->y = pos.y;
	this->z = pos.z;
}

void Rotation::operator =(Vector3 pos)
{
	this->x = pos[0];
	this->y = pos[1];
	this->z = pos[2];
}

bool Rotation::operator ==(Rotation pos) const{
	return (pos.GetX() == x) && (pos.GetY() == y) && (pos.GetZ() == z);
}

Rotation::~Rotation() {
	// TODO Auto-generated destructor stub
}

