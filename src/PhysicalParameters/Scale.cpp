/*
 * Scale.cpp
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#include "Scale.h"

Scale::Scale(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
};
Scale::Scale(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
};

void Scale::operator =(Scale pos)
{
	this->x = pos.x;
	this->y = pos.y;
	this->z = pos.z;
}

void Scale::operator =(Vector3 pos)
{
	this->x = pos[0];
	this->y = pos[1];
	this->z = pos[2];
}

Scale::~Scale() {
	// TODO Auto-generated destructor stub
}

