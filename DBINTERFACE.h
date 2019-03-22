/*
 * DBINTERFACE.h
 *
 *  Created on: Mar 13, 2019
 *      Author: engineer
 */

#ifndef DBINTERFACE_H_
#define DBINTERFACE_H_

#include <iostream>
#include <string>
#include <libpq-fe.h>
#include <pqxx/pqxx>

using namespace std;

class DBINTERFACE {
protected:
	string dbname;//string dbname, string username, string password, string addr, string port
	string username;
	string password;
	string addr;
	string port;
	string databaseConnectString;
	pqxx::connection *conn;
public:
	DBINTERFACE(string dbname, string username, string password, string addr, string port);
	virtual ~DBINTERFACE();
	int addMeasurementDB(double measurement);
};

#endif /* DBINTERFACE_H_ */
