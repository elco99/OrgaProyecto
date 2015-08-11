#include "cliente.h"
#include <iostream>
#include <string.h>
using namespace std;
    
Cliente::Cliente(int Id, char Name[],char Gender,int IdCiudad){
    this -> Id = Id;
    this -> Name = Name;
    this -> Gender = Gender;
    this -> IdCiudad = IdCiudad;    
}
void Cliente::setId(int Id){
    this -> Id = Id;
}

void Cliente::setName(char* Name){
    this -> Name = Name;
}

void Cliente::setGender(char Gender){
    this -> Gender = Gender;
}

void Cliente::setIdCiudad(int IdCiudad){
    this -> IdCiudad = IdCiudad;
}

int Cliente::getId(){
    return Id;
}

char* Cliente::getName(){
    return Name;
}

char Cliente::getGender(){
    return Gender;
}

int Cliente::setIdCiudad(){
    return IdCiudad;
}