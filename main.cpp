#include <iostream>
#include "llamada.h"
#include "ciudad.h"
#include "linea.h"
#include "cliente.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

string GenerarId();
string GenerarIdCiudad();
string GenerarTelefono();

int main(int argc, char* argv[]){
	srand(time(0));
	cout<< GenerarId()<<endl;
	return 0;
}

string GenerarId(){
	string id;
	srand(time(0));
	stringstream ko;
	ko << rand() % 2 << rand() % 10<< rand() % 9<< rand() % 10 << (rand() % 98 + 1900) << (rand() % 90000+10000);
	id  = ko.str();
	
	return id;
}

string GenerarIdCiudad(){
	string id;
	srand(time(0));
	stringstream ko;
	ko << rand() % 10 << rand() % 10<< rand() % 10<< rand() % 10 ;
	id  = ko.str();
	return id;
}

string GenerarTelefono(){
	string id;
	srand(time(0));
	stringstream ko;
	ko << rand() % 10 << rand() % 10<< rand() % 10<< rand() % 10<< rand() % 10 << rand() % 10<< rand() % 10<< rand() % 10 ;
	id  = ko.str();
	return id;
}