/*
 * axis.h
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#ifndef PHYSICALPARAMETERS_AXIS_H_
#define PHYSICALPARAMETERS_AXIS_H_
#include "Vector3.h"

class Axis{
public:
	float 	GetX();
	void	SetX(float x);

	float 	GetY();
	void	SetY(float y);

	float 	GetZ();
	void	SetZ(float z);

	Vector3 GetVector();
	void	SetVector(Vector3 vector);
public:
	float x;
	float y;
	float z;
};


#endif /* PHYSICALPARAMETERS_AXIS_H_ */
