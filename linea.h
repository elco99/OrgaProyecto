#pragma once
#include <cstring>

using namespace std;

class Linea{
	int Id;
	char* Numero; 
public:
	Linea(int, char[]);
	char* getNumero();
	int getId();
	void setNumero(char*);
	void setId(int);
};