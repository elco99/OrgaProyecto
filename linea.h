#pragma once
#include <cstring>
#include <string>
using namespace std;

class Linea{
	string Id;
	char* Numero; 
public:
	Linea(string, char[]);
	char* getNumero();
	string getId();
	void setNumero(char*);
	void setId(string);
};