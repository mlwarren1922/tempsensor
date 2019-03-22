#include <iostream>
#include <string>
#include "DBINTERFACE.h"

using namespace std;
		
int main(int argc, char** argv){
	if(argc != 2){
		cout << "Usage: tempsensor <database_name>" << endl;
		return 1;
	}
	cout << "Starting temperature measurement system..." << endl;
	
	string dbname = string(argv[1]);
	string username = "postgres";
	string password = "!peanut2";
	string addr = "127.0.0.1";
	string port = "5432";



	DBINTERFACE *dbase = new DBINTERFACE(dbname,username,password,addr,port);
	dbase->addMeasurement();
	
	//delete dbase;

	return 0;
}
