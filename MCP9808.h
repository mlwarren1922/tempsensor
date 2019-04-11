/*
 * MCP9808.h
 *
 *  Created on: Apr 6, 2019
 *      Author: engineer
 */

#ifndef MCP9808_H_
#define MCP9808_H_

#include <iostream>
#include <string>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/ioctl.h>

using namespace std;

#define reg_resolution	0b1000
#define reg_DevID		0b0111
#define reg_ManufID		0b0110
#define reg_temp		0b0101
#define reg_config		0b0001

#define DevID			0x0400
#define ManfID			0x0054

class MCP9808 {
protected:
	int file;
	char filename[20];
	char buffer[2];
	int sensor_address;
public:
	MCP9808(string filename, int address);
	virtual ~MCP9808();
	int readFromTempSensor(int reg_addr);
	int getDeviceID();
	double getTemperature();
};

#endif /* MCP9808_H_ */
