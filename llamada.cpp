#include "llamada.h"
#include <iostream>
#include <string.h>
using namespace std;
    
Llamada::Llamada(string Numero, double FechaInicio, double FechaFinal, string IdCiudad){
    this -> Numero = Numero;
    this -> FechaInicio = FechaInicio;
    this -> FechaFinal = FechaFinal;
    this -> IdCiudad = IdCiudad;   
}

void Llamada::setNumero(string Numero){
    this -> Numero = Numero;
}

void Llamada::setFechaInicio(double FechaInicio){
    this -> FechaInicio = FechaInicio;
}

void Llamada::setFechaFinal(double FechaFinal){
    this -> FechaFinal = FechaFinal;
}

void Llamada::setIdCiudad(string IdCiudad){
    this -> IdCiudad = IdCiudad;
}

string Llamada::getNumero(){
    return Numero;
}

double Llamada::getFechaInicio(){
    return FechaInicio;
}

double Llamada::getFechaFinal(){
    return FechaFinal;
}

string Llamada::setIdCiudad(){
    return IdCiudad;
}
