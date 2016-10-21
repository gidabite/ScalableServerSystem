/*
 * Vector3.h
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#ifndef PHYSICALPARAMETERS_VECTOR3_H_
#define PHYSICALPARAMETERS_VECTOR3_H_
#include "vector"

class Vector3 {
public:
	Vector3(double x, double y, double z);
	double& operator[](int x);
	virtual ~Vector3();
private:
	std::vector<double> vector;
};

#endif /* PHYSICALPARAMETERS_VECTOR3_H_ */
