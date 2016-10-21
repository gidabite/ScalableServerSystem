/*
 * Position.cpp
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#include "Position.h"

Position::Position(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
};
Position::Position(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
};

void Position::operator =(Position pos)
{
	this->x = pos.x;
	this->y = pos.y;
	this->z = pos.z;
}

void Position::operator =(Vector3 pos)
{
	this->x = pos[0];
	this->y = pos[1];
	this->z = pos[2];
}

Position::~Position() {
	// TODO Auto-generated destructor stub
}

