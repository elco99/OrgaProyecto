#include <iostream>
#include "llamada.h"
#include "ciudad.h"
#include "linea.h"
#include "cliente.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;
string GenerarId();
string GenerarIdCiudad();
string GenerarTelefono();

int main(int argc, char* argv[]){

	vector <Cliente*> clientes;
	srand(time(0));
	ifstream file("Nombres.txt");
	while(!file.eof()){
		string datoLeido = "";
		stringstream ss;
		ss << getline(file, datoLeido, ',') << getline(file, datoLeido,',');
		char nombre [40] ;
		for (int i = 0; i < ss.str().size(); ++i)
		{
			nombre[i] = (ss.str())[i]; 	
		}
		bool repetido = false;
		while(true){
			string comprobarId = GenerarId();
			int contador = 0;
			while(contador < clientes.size()){
				if(comprobarId.compare(clientes[contador]->getId()) != 0){
					repetido = true;
					break;
				}
				contador++;

			}
			stringstream sstream;
			sstream << getline(file, datoLeido, ','); 
			char gender = (sstream.str())[0];
			if(!repetido){
				clientes.push_back(new Cliente(comprobarId, nombre, gender ,GenerarIdCiudad()) );
				break;
			}
		}
		
	}
	file.close();
	for (int i = 0; i < clientes.size(); ++i)
	{
		cout << clientes[i]->getId ()<< "||" <<  (clientes[i])->getName()<< "////" << i << "///" << clientes.size()<<endl;
	}
	return 0;
}

string GenerarId(){
	string id;
	srand(time(0));
	stringstream ss;
	ss << rand() % 2 << rand() % 10<< rand() % 9<< rand() % 10 << (rand() % 98 + 1900) << (rand() % 90000+10000);
	id  = ss.str();

	return id;
}

string GenerarIdCiudad(){
	string id;
	srand(time(0));
	stringstream ss;
	ss << rand() % 10 << rand() % 10<< rand() % 10<< rand() % 10 ;
	id  = ss.str();
	return id;
}

string GenerarTelefono(){
	string id;
	srand(time(0));
	stringstream ss;
	ss << rand() % 10 << rand() % 10<< rand() % 10<< rand() % 10<< rand() % 10 << rand() % 10<< rand() % 10<< rand() % 10 ;
	id  = ss.str();
	return id;
}
