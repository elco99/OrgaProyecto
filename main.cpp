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