/*
 * Position.h
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#ifndef PHYSICALPARAMETERS_POSITION_H_
#define PHYSICALPARAMETERS_POSITION_H_

#include "Axis.h"
#include "Vector3.h"

class Position: public Axis {
public:
	Position();
	Position(double x, double y, double z);
	void operator=(Position pos);
	void operator=(Vector3 pos);
	bool operator==(const Position pos) const;

	virtual ~Position();
};

#endif /* PHYSICALPARAMETERS_POSITION_H_ */
