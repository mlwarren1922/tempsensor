/*
 * TEMPMEASUREMENT.h
 *
 *  Created on: Mar 22, 2019
 *      Author: engineer
 */

#include <iostream>

#ifndef TEMPMEASUREMENT_H_
#define TEMPMEASUREMENT_H_

#include <math.h>
#include "MCP9808.h"

//#define TESTMODE

class TEMPMEASUREMENT {
protected:
	double testValues[100];
	int testi;
	double tempMeasurement;
	MCP9808 *tempsensor1;
public:
	TEMPMEASUREMENT();
	virtual ~TEMPMEASUREMENT();
	int createTestValues(void);
	double getTempMeasurement();
};

#endif /* TEMPMEASUREMENT_H_ */
