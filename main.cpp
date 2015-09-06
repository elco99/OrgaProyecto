#include <iostream>
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
const int HeaderSize = sizeof(int) + sizeof(int) + sizeof(bool);

int main(int argc, char* argv[]){

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
	ifstream file("Ciudad.txt");
	ofstream outputFile("Ciudades.bin");
	int rrn=-1, recordNumber = 0;
	bool indexFlag = 0;
	outputFile.write( reinterpret_cast<char*>(&rrn), sizeof(int) );
	outputFile.write( reinterpret_cast<char*>(&recordNumber), sizeof(int) );
	outputFile.write( reinterpret_cast<char*>(&indexFlag), sizeof(bool)  );

	while(true){
		if(file.eof())
			break;
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
		bool CadenaVacia = true;
		for (int i = 0; i < sizeof(IdCiudad); ++i)
		{
			if(IdCiudad[i] != '\0' && IdCiudad[i] != ' ')
				CadenaVacia = false;
		}
		if(!CadenaVacia){			
			outputFile.write((char*)IdCiudad, sizeof(IdCiudad));
			outputFile.write((char*)NameCiudad, sizeof(NameCiudad));
			recordNumber++;
	  		outputFile.seekp (sizeof(rrn));
	  		outputFile.write(reinterpret_cast<char*>(&recordNumber), sizeof(recordNumber));
	  		outputFile.seekp(sizeof(int)*2 +1 +(recordNumber*44));
		}
	}	
	file.close();
	outputFile.close();
	//ListCity();
}
void ClientToBinary(){
	ifstream file("Clientes.txt");
	ofstream outputFile("Clientes.bin");
	int rrn=-1, recordNumber = 0;
	bool indexFlag = 0;
	outputFile.write( reinterpret_cast<char*>(&rrn), sizeof(int) );
	outputFile.write( reinterpret_cast<char*>(&recordNumber), sizeof(int) );
	outputFile.write( reinterpret_cast<char*>(&indexFlag), sizeof(bool)  );
	while(true){
		if(file.eof())
			break;
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
		recordNumber++;
  		outputFile.seekp (sizeof(rrn));
  		outputFile.write(reinterpret_cast<char*>(&recordNumber), sizeof(recordNumber));
  		outputFile.seekp(sizeof(int)*2 +1 +(recordNumber*60));
	}	
	file.close();
	outputFile.close();
	//ListClient();
}
void CallToBinary(){
	ifstream file("Llamadas.txt");
	ofstream outputFile("Llamadas.bin");
	int rrn=-1, recordNumber = 0;
	bool indexFlag = 0;
	outputFile.write( reinterpret_cast<char*>(&rrn), sizeof(int) );
	outputFile.write( reinterpret_cast<char*>(&recordNumber), sizeof(int) );
	outputFile.write( reinterpret_cast<char*>(&indexFlag), sizeof(bool)  );
	int Id;
	char Numero[9];
	char FechaInicio[20];
	char FechaFinal[20];
	char NumDestino[9];
	while(true){
		if (file.eof())
			break;
		
		string temp1 = "", temp2 = "",temp3 = "",temp4 = "",temp5 = "";
		getline(file, temp1, ',');
		getline(file, temp2, ',');
		getline(file, temp3, ',');
		getline(file, temp4, ',');
		getline(file, temp5, ',');
		stringstream ss;
		for (int i = 0; i < sizeof(temp1); ++i){
			ss << temp1[i];
		}
		Id = atoi(ss.str().c_str());
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i] = temp2[i];
		}		
		for (int i = 0; i < sizeof(FechaInicio); ++i){
			FechaInicio[i] = temp3[i];
		}
		for (int i = 0; i <  sizeof(FechaFinal); ++i){
			FechaFinal[i] = temp4[i];
		}		
		for (int i = 0; i <  sizeof(NumDestino); ++i){
			NumDestino[i] = temp5[i];
		}
		//cout << temp1 <<" | "<<Numero << " | " << FechaInicio << " | " << FechaFinal << " | " << NumDestino <<endl;
		outputFile.write(reinterpret_cast<char*>(&Id), sizeof(Id));
		outputFile.write((char*)Numero, sizeof(Numero));
		outputFile.write((char*)FechaInicio, sizeof(FechaInicio));
		outputFile.write((char*)FechaFinal, sizeof(FechaFinal));
		outputFile.write((char*)NumDestino, sizeof(NumDestino));
		recordNumber++;
  		outputFile.seekp (sizeof(rrn));
  		outputFile.write(reinterpret_cast<char*>(&recordNumber), sizeof(recordNumber));
  		outputFile.seekp(sizeof(int)*2 +1 +(recordNumber*62));
	}	
	file.close();
	outputFile.close();
	//ListCall();
}