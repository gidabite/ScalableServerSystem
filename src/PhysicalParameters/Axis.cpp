/*
 * Axis.cpp
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */
#include "Axis.h"

float Axis::GetX(){
	return this->x;
}

void Axis::SetX(float x){
	this->x= x;
}

float Axis::GetY(){
	return this->y;
}

void Axis::SetY(float y){
	this->y= y;
}

float Axis::GetZ(){
	return this->z;
}

void Axis::SetZ(float z){
	this->z= z;
}

Vector3 Axis::GetVector()
{
	Vector3 temp(this->x, this->y, this->z);
	return temp;
}

void Axis::SetVector(Vector3 vector)
{
	this->x = vector[0];
	this->y = vector[1];
	this->z = vector[2];
}
