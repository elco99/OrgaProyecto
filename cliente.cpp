#include "cliente.h"
#include <iostream>
#include <string.h>
using namespace std;
    
Cliente::Cliente(string Id, char Name[],char Gender,string IdCiudad){
    this -> Id = Id;
    this -> Name = Name;
    this -> Gender = Gender;
    this -> IdCiudad = IdCiudad;    
}
void Cliente::setId(string Id){
    this -> Id = Id;
}

void Cliente::setName(char* Name){
    this -> Name = Name;
}

void Cliente::setGender(char Gender){
    this -> Gender = Gender;
}

void Cliente::setIdCiudad(string IdCiudad){
    this -> IdCiudad = IdCiudad;
}

string Cliente::getId(){
    return Id;
}

char* Cliente::getName(){
    return Name;
}

char Cliente::getGender(){
    return Gender;
}

string Cliente::setIdCiudad(){
    return IdCiudad;
}