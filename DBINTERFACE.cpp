/*
 * DBINTERFACE.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: engineer
 */

#include "DBINTERFACE.h"


using namespace std;
using namespace pqxx;

DBINTERFACE::DBINTERFACE(string dbname, string username, string password, string addr, string port) {
	this->dbname = dbname;
	this->username = username;
	this->password = password;
	this->addr = addr;
	this->port = port;

	this->databaseConnectString = "dbname=" + dbname + " user=" + username + " password=" + password + " hostaddr=" + addr + " port=" + port;

	conn = new connection(this->databaseConnectString);
	if(conn->is_open()){
		cout << dbname << " database opened successfully..." << endl;
	}
	else {
		cout << "Failed to open database..." << endl;
	}

}

DBINTERFACE::~DBINTERFACE() {
	conn->disconnect();
	delete conn;
}

int DBINTERFACE::addMeasurement(){
	string sqlstatement;
	int index;
	double measurement;

	index = 1;
	measurement = 1.23;

	//check database connection
	if(!conn->is_open()){
		cout << "Failed to open database..." << endl;
		return 1;
	}

	sqlstatement = "INSERT INTO temp (id,temperature) VALUES (" + to_string(index) + ", " + to_string(measurement) + ");";

	work W(*conn);

	W.exec(sqlstatement.c_str());
	W.commit();

	cout << "Measurement recorded..." << endl;

	return 0;
}

