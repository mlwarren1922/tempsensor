#include <iostream>
#include <string>
#include "DBINTERFACE.h"
#include <unistd.h>
#include "TEMPMEASUREMENT.h"
#include "MCP9808.h"

using namespace std;
		
int main(int argc, char** argv){
	if(argc != 2){
		cout << "Usage: tempsensor <database_name>" << endl;
		return 1;
	}
	cout << "Starting temperature measurement system..." << endl;
	
	string dbname = string(argv[1]);
	string username = "postgres";
	string password = "@#$%$%!";
	string addr = "127.0.0.1";
	string port = "5432";


	double measurement = 1.2345;


	DBINTERFACE *dbase = new DBINTERFACE(dbname,username,password,addr,port);
	TEMPMEASUREMENT *temp = new TEMPMEASUREMENT();

	while(1){
		measurement = temp->getTempMeasurement();
		cout << "Temp: " << measurement << "f" << endl;
		dbase->addMeasurementDB(measurement);
		sleep(600);
	}


	delete dbase;
	delete temp;

	return 0;
}
