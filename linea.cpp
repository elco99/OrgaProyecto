#include "linea.h"

Linea::Linea(int Id, char Numero[]):Id(Id),Numero(Numero){

}
char* Linea::getNumero(){
	return Numero;
}
int Linea::getId(){
	return Id;
}
void Linea::setNumero(char* Numero){
	this-> Numero = Numero;
}
void Linea::setId(int Id){
	this-> Id = Id;
}