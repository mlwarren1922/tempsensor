/*
 * TEMPMEASUREMENT.cpp
 *
 *  Created on: Mar 22, 2019
 *      Author: engineer
 */

#include "TEMPMEASUREMENT.h"

using namespace std;

TEMPMEASUREMENT::TEMPMEASUREMENT() {
	cout << "Intializing temperature sensors..." << endl;
#ifdef TESTMODE
	cout << "Initializing test value table..." << endl;
	this->createTestValues();
	testi = 0;
#endif

	tempMeasurement = 0;

}

TEMPMEASUREMENT::~TEMPMEASUREMENT() {
	// TODO Auto-generated destructor stub
}

int TEMPMEASUREMENT::createTestValues(void){
	int i;

	for(i = 0; i <= 100; i++){
		testValues[i] = i;
		cout << "testValue[" << i << "] = " << i<< endl;
	};

	return 0;
}

double TEMPMEASUREMENT::getTempMeasurement(){
	//get temperature measurement
#ifdef TESTMODE
	tempMeasurement = this->testValues[testi];
	cout << "Stored " << this->testValues[testi] << endl;
	testi++;
	if(testi == 100){
		testi = 0;
	}
#endif
	return tempMeasurement;
}
