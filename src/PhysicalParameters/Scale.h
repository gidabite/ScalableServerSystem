/*
 * Scale.h
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#ifndef PHYSICALPARAMETERS_SCALE_H_
#define PHYSICALPARAMETERS_SCALE_H_

#include "Axis.h"

class Scale: public Axis {
public:
	Scale();
	Scale(double x, double y, double z);
	void operator=(Scale sc);
	void operator=(Vector3 sc);
	virtual ~Scale();
};

#endif /* PHYSICALPARAMETERS_SCALE_H_ */
