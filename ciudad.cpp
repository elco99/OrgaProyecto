#include "ciudad.h"

Ciudad::Ciudad(int IdCiudad,char[40] NameCiudad){
	this->IdCiudad = IdCiudad;
	this->NameCiudad = NameCiudad;
}
char* Ciudad::getNameCiudad(){
	return NameCiudad;
}
int Ciudad::getIdCiudad(){
	return IdCiudad;
}
void Ciudad::setNameCiudad(char[40] NameCiudad){
	this->NameCiudad = Nameciudad;
}
void Ciudad::setIdCiudad(int IdCiudad){
	this->IdCiudad = IdCiudad;
}