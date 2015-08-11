#pragma once
#include <string>
using namespace std;

class Ciudad{
	string IdCiudad;
	char* NameCiudad; 
public:
	Ciudad(string, char[]);
	char* getNameCiudad();
	string getIdCiudad();
	void setNameCiudad(char*);
	void setIdCiudad(string);
};