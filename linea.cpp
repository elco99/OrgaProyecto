#include "linea.h"

Linea::Linea(string Id, char Numero[]):Id(Id),Numero(Numero){

}
char* Linea::getNumero(){
	return Numero;
}
string Linea::getId(){
	return Id;
}
void Linea::setNumero(char* Numero){
	this-> Numero = Numero;
}
void Linea::setId(string Id){
	this-> Id = Id;
}