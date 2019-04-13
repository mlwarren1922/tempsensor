/*
 * TEMPMEASUREMENT.cpp
 *
 *  Created on: Mar 22, 2019
 *      Author: engineer
 */

#include "TEMPMEASUREMENT.h"

using namespace std;

TEMPMEASUREMENT::TEMPMEASUREMENT() {
	string filename = "/dev/i2c-1";
	int tempsensor_addr = 0b0011000;

	cout << "Intializing temperature sensors..." << endl;
	this->tempMeasurement = 0;

	this->tempsensor1 = new MCP9808(filename, tempsensor_addr);

}

TEMPMEASUREMENT::~TEMPMEASUREMENT() {
	delete this->tempsensor1;
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
	tempMeasurement = this->tempsensor1->getTemperature();
	tempMeasurement = (tempMeasurement * 9/5) + 32;
	return tempMeasurement;
}
