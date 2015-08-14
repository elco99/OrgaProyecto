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
#include <string.h>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;
string GenerarId();
string GenerarIdCiudad();
string GenerarTelefono();
void CityToBinary();
void ClientToBinary();
void CallToBinary();
void NumberToBinary();

int main(int argc, char* argv[]){

	vector <Cliente*> clientes;
	srand(time(0));
	CityToBinary();
	ClientToBinary();
	CallToBinary();
	NumberToBinary();	
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
void CityToBinary(){
	ifstream file("CiudadDavid.txt");
	ofstream outputFile("Ciudades.bin");
	while(!file.eof()){
		char IdCiudad[4];
		char NameCiudad[40];
		string temp = "", temp1 = "";
		getline(file, temp, ',');
		getline(file, temp1, ',');
		for (int i = 0; i < 4; ++i){
			IdCiudad[i] = temp[i];
		}		
		for (int i = 0; i < 40; ++i){
			NameCiudad[i] = temp1[i];
		}
		outputFile.write((char*)IdCiudad, sizeof(IdCiudad));
		outputFile.write((char*)NameCiudad, sizeof(NameCiudad));
	}	
	file.close();
	outputFile.close();
	ifstream readFile("Ciudades.bin",ios::binary);
	readFile.seekg(0);
	while(!readFile.eof()){
		char IdCiudad[4];
		char NameCiudad[40];
		readFile.read((char*)IdCiudad, sizeof(IdCiudad));
		readFile.read((char*)NameCiudad, sizeof(NameCiudad));

	}
	readFile.close();
}
void ClientToBinary(){
	ifstream file("ClientesDavid.txt");
	ofstream outputFile("Clientes.bin");
	while(!file.eof()){
		char IdClient[14];
		char NameClient[40];
		char Gender[2];
		char IdCiudad[4];
		string temp1 = "", temp2 = "",temp3 = "",temp4 = "";
		getline(file, temp1, ',');
		getline(file, temp2, ',');
		getline(file, temp3, ',');
		getline(file, temp4, ',');
		for (int i = 0; i < 14; ++i){
			IdClient[i] = temp1[i];
		}		
		for (int i = 0; i < 40; ++i){
			NameClient[i] = temp2[i];
		}
		for (int i = 0; i < 2; ++i){
			Gender[i] = temp3[i];
		}		
		for (int i = 0; i < 4; ++i){
			IdCiudad[i] = temp4[i];
		}
		outputFile.write((char*)IdClient, sizeof(IdClient));
		outputFile.write((char*)NameClient, sizeof(NameClient));
		outputFile.write((char*)Gender, sizeof(Gender));
		outputFile.write((char*)IdCiudad, sizeof(IdCiudad));
	}	
	file.close();
	outputFile.close();
	ifstream readFile("Clientes.bin",ios::binary);
	readFile.seekg(0);
	while(!readFile.eof()){
		char IdClient[14];
		char NameClient[40];
		char Gender[2];
		char IdCiudad[4];
		readFile.read((char*)IdClient, sizeof(IdClient));
		readFile.read((char*)NameClient, sizeof(NameClient));
		readFile.read((char*)Gender, sizeof(Gender));
		readFile.read((char*)IdCiudad, sizeof(IdCiudad));
		cout <<IdClient << " | " << NameClient << " | " << Gender << " | " << IdCiudad <<endl;

	}
	readFile.close();
}

void CallToBinary(){
	ifstream file("LlamadasDavid.txt");
	ofstream outputFile("Llamadas.bin");
	while(!file.eof()){
		char Numero[9];
		char FechaInicio[20];
		char FechaFinal[20];
		char IdCiudad[4];
		string temp1 = "", temp2 = "",temp3 = "",temp4 = "";
		getline(file, temp1, ',');
		getline(file, temp2, ',');
		getline(file, temp3, ',');
		getline(file, temp4, ',');
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i] = temp1[i];
		}		
		for (int i = 0; i < sizeof(FechaInicio); ++i){
			FechaInicio[i] = temp2[i];
		}
		for (int i = 0; i <  sizeof(FechaFinal); ++i){
			FechaFinal[i] = temp3[i];
		}		
		for (int i = 0; i <  sizeof(IdCiudad); ++i){
			IdCiudad[i] = temp4[i];
		}
		outputFile.write((char*)Numero, sizeof(Numero));
		outputFile.write((char*)FechaInicio, sizeof(FechaInicio));
		outputFile.write((char*)FechaFinal, sizeof(FechaFinal));
		outputFile.write((char*)IdCiudad, sizeof(IdCiudad));
	}	
	file.close();
	outputFile.close();
	ifstream readFile("Llamadas.bin",ios::binary);
	readFile.seekg(0);
	while(!readFile.eof()){
		char Numero[9];
		char FechaInicio[20];
		char FechaFinal[20];
		char IdCiudad[4];
		readFile.read((char*)Numero, sizeof(Numero));
		readFile.read((char*)FechaInicio, sizeof(FechaInicio));
		readFile.read((char*)FechaFinal, sizeof(FechaFinal));
		readFile.read((char*)IdCiudad, sizeof(IdCiudad));
		cout <<Numero << " | " << FechaInicio << " | " << FechaFinal << " | " << IdCiudad <<endl;

	}
	readFile.close();
}
void NumberToBinary(){
	ifstream file("NumeroDavid.txt");
	ofstream outputFile("Numeros.bin");
	while(!file.eof()){
		char Numero[9];
		char Id[14];
		string temp = "", temp1 = "";
		getline(file, temp, ',');
		getline(file, temp1, ',');
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i] = temp[i];
		}		
		for (int i = 0; i < sizeof(Id); ++i){
			Id[i] = temp1[i];
		}
		outputFile.write((char*)Numero, sizeof(Numero));
		outputFile.write((char*)Id, sizeof(Id));
	}	
	file.close();
	outputFile.close();
	ifstream readFile("Numeros.bin",ios::binary);
	readFile.seekg(0);
	while(!readFile.eof()){
		char Numero[9];
		char Id[14];
		readFile.read((char*)Numero, sizeof(Numero));
		readFile.read((char*)Id, sizeof(Id));
		cout <<Numero << " | " << Id << endl;

	}
	readFile.close();
}