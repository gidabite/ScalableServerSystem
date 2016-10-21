/*
 * Vector3.cpp
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#include "Vector3.h"

Vector3::Vector3(double x, double y, double z){
	this->vector[0] = x;
	this->vector[1] = y;
	this->vector[2] = z;

}
double& Vector3::operator[](int x){
	return this->vector.at(x);
}
Vector3::~Vector3() {
	// TODO Auto-generated destructor stub
}

