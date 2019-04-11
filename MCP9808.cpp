/*
 * MCP9808.cpp
 *
 *  Created on: Apr 6, 2019
 *      Author: engineer
 */

#include "MCP9808.h"

MCP9808::MCP9808(string filename, int address) {
	this->sensor_address = address;
	sprintf(this->filename,filename.c_str());
}

MCP9808::~MCP9808() {
	// TODO Auto-generated destructor stub
}

int MCP9808::readFromTempSensor(int reg_addr){
	int raw_data = 0;
	*this->buffer = {0};

	if((this->file = open(this->filename, O_RDWR)) < 0){
		cout << "Error opening " << filename << "..." << endl;
		return -1;
	}

	if(ioctl(this->file, I2C_SLAVE, this->sensor_address) < 0){
		cout << "Error with ioctl..." << endl;
		return -1;
	}

	this->buffer[0] = reg_addr;
	if(write(this->file,this->buffer,1) != 1){
		cout << "Error writing to i2c..." << endl;
		return -1;
	}
	if(read(this->file,this->buffer,2) != 2){
		cout << "Error reading from i2c..." << endl;
		return -1;
	}

	close(this->file);

	return raw_data;
}

int MCP9808::getDeviceID(){
	int reg = reg_DevID;
	this->readFromTempSensor(reg);

	cout << "Device ID: 0x" << (int)this->buffer[0] << (int)this->buffer[1] << endl;

	return 0;
}

double MCP9808::getTemperature(){
	int reg = reg_temp;
	int sign = 0;
	int value_real = 0;
	double value = 0;

	this->readFromTempSensor(reg);
	sign = buffer[0]&0b00010000;
	sign = sign>>4;

	value_real = ((buffer[0] & 0b00001111)<<4)|((buffer[1] & 0b11110000)>>4);
	if((buffer[1]&0b00001000) == 0b00001000) value += 0.5;
	if((buffer[1]&0b00000100) == 0b00000100) value += 0.25;
	//if(buffer[1]&0b00000010 == 0b00000010) value += 0.125;
	//if(buffer[1]&0b00000001 == 0b00000001) value += 0.0625;

	value += value_real;
	if(sign == 1) value = value*(-1);

	return value;
}
