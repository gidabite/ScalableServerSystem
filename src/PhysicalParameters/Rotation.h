/*
 * Rotation.h
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#ifndef PHYSICALPARAMETERS_ROTATION_H_
#define PHYSICALPARAMETERS_ROTATION_H_

#include "Axis.h";

class Rotation: public Axis {
public:
	Rotation();
	Rotation(double x, double y, double z);
	void operator=(Rotation rot);
	void operator=(Vector3 rot);
	bool operator==(const Rotation pos) const;
	virtual ~Rotation();
};

#endif /* PHYSICALPARAMETERS_ROTATION_H_ */
