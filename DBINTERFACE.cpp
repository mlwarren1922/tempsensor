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

int DBINTERFACE::addMeasurementDB(double measurement){
	string sqlstatement;

	//check database connection
	if(!conn->is_open()){

		//try to open connection to database
		conn = new connection(this->databaseConnectString);
		if(!conn->is_open()){
			cout << "Unable to connect to database..." << endl;
			return 1;
		}
	}

	sqlstatement = "INSERT INTO temp (date, temperature) VALUES (NOW(), " + to_string(measurement) + ");";
	//sqlstatement = "INSERT INTO temp (date, temperature) VALUES (NOW(),1.2345);";

	work W(*conn);

	W.exec(sqlstatement.c_str());
	W.commit();

	return 0;
}


