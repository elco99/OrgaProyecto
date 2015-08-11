#pragma once

using namespace std;

class Ciudad{
	int IdCiudad;
	char* NameCiudad; 
public:
	Ciudad(int, char[]);
	char* getNameCiudad();
	int getIdCiudad();
	void setNameCiudad(char*);
	void setIdCiudad(int);
};