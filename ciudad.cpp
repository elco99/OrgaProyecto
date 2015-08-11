#include "ciudad.h"
#include <cstring>

Ciudad::Ciudad(string IdCiudad,char NameCiudad[]):IdCiudad(IdCiudad),NameCiudad(NameCiudad){

}
char* Ciudad::getNameCiudad(){
	return NameCiudad;
}
string Ciudad::getIdCiudad(){
	return IdCiudad;
}
void Ciudad::setNameCiudad(char* NameCiudad){
	this->NameCiudad = NameCiudad;
}
void Ciudad::setIdCiudad(string IdCiudad){
	this->IdCiudad = IdCiudad;
}