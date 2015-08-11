#include "ciudad.h"
#include <cstring>

Ciudad::Ciudad(int IdCiudad,char NameCiudad[]):IdCiudad(IdCiudad),NameCiudad(NameCiudad){

}
char* Ciudad::getNameCiudad(){
	return NameCiudad;
}
int Ciudad::getIdCiudad(){
	return IdCiudad;
}
void Ciudad::setNameCiudad(char* NameCiudad){
	this->NameCiudad = NameCiudad;
}
void Ciudad::setIdCiudad(int IdCiudad){
	this->IdCiudad = IdCiudad;
}