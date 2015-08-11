#pragma once

using namespace std;

class Ciudad{
	int IdCiudad;
	char[40] NameCiudad; 
public:
	Ciudad(int,char[40]);
	char* getCiudad();
	int getIdCiudad();
	void setCiudad(char[40]);
	void setIdCiudad(int);
};