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
void NumberToBinary();
void IndexCity();
void IndexClient();
void IndexNumber();
void borrarCity( int );
int PosicionIngresoOrdenadoAlIndice(vector<string>,  int);
int PosicionIngresoOrdenadoAlIndiceLong(vector<string>, unsigned long );
const int HeaderSize = sizeof(int) + sizeof(int) + sizeof(bool);
vector<string> indexCityRRN;
vector<string> indexCityKey;
vector<string> indexClientKey;
vector<string> indexClientRRN;
vector<string> indexNumberRRN;
vector<string> indexNumberKey;

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
void NumberToBinary(){
	ifstream file("Numero.txt");
	ofstream outputFile("Numeros.bin");
	int rrn=-1, recordNumber = 0;
	bool indexFlag = 0;
	outputFile.write( reinterpret_cast<char*>(&rrn), sizeof(int) );
	outputFile.write( reinterpret_cast<char*>(&recordNumber), sizeof(int) );
	outputFile.write( reinterpret_cast<char*>(&indexFlag), sizeof(bool)  );
	while(true){
		if(file.eof())
			break;
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
		recordNumber++;
  		outputFile.seekp (sizeof(rrn));
  		outputFile.write(reinterpret_cast<char*>(&recordNumber), sizeof(recordNumber));
  		outputFile.seekp(sizeof(int)*2 +1 +(recordNumber*23));
	}	
	file.close();
	outputFile.close();
	//ListNumber();
}
void IndexCity(){
	indexCityKey.clear();
	indexCityRRN.clear();
	ifstream readFile("Ciudades.bin",ios::binary);
	readFile.seekg(HeaderSize);
	int cont = 0;

 	while(true){
		stringstream rrn ;
		if(readFile.eof()){
			break;
		}
		char IdCiudad[4];
		char NameCiudad[40];
		readFile.read(reinterpret_cast<char*>(&IdCiudad), sizeof(IdCiudad));
		readFile.read(reinterpret_cast<char*>(&NameCiudad), sizeof(NameCiudad));
		bool iguales = false;
		for (int i = 0; i < sizeof(IdCiudad)-1; ++i){
			if(IdCiudad[i] == '*'){
				iguales = true;	
				break;			
			}
		}
		if(!iguales){
			stringstream ss;
			for (int i = 0; i < sizeof(IdCiudad); ++i){							
				ss<< IdCiudad[i];	
			}
			rrn<< cont;
			int key = atoi(ss.str().c_str());
			int position = PosicionIngresoOrdenadoAlIndice(indexCityKey, key);
			if (position == -1){
				indexCityKey.push_back(ss.str());
				indexCityRRN.push_back(rrn.str());
			}else{
				indexCityKey.insert(indexCityKey.begin() + position, ss.str());
				indexCityRRN.insert(indexCityRRN.begin() + position, rrn.str());
			}

		}
		cont++;

	}
	/*for (int i = 0; i < indexCityKey.size(); ++i)
	{
		cout << "Key: " << indexCityKey.at(i) << " RRN: " << indexCityRRN.at(i)<< endl;
	}	*/
	readFile.close();
	//writeIndex(indexCityKey,indexCityRRN, "IdenxCity.bin", "Ciudades.bin");
	//ListIndex("IndexCity.bin");
}
void IndexClient(){
	indexClientKey.clear();
	indexClientKey.clear();
	ifstream readFile("Clientes.bin",ios::binary);
	readFile.seekg(sizeof(int)+sizeof(int)+sizeof(bool));
	int cont = 0;

 	while(true){
		stringstream rrn ;
		if(readFile.eof())
			break;
		char IdClient[14];
		char NameClient[40];
		char Gender[2];
		char IdCiudad[4];
		readFile.read((char*)IdClient, sizeof(IdClient));
		readFile.read((char*)NameClient, sizeof(NameClient));
		readFile.read((char*)Gender, sizeof(Gender));
		readFile.read((char*)IdCiudad, sizeof(IdCiudad));
		bool iguales = false;
		for (int i = 0; i < sizeof(IdClient)-1; ++i)
		{
			if(IdClient[i] == '*'){
				iguales = true;	
				break;			
			}
		}
		if(!iguales){
			stringstream ss;
			for (int i = 0; i < sizeof(IdClient); ++i)
			{							
				ss<< IdClient[i];	
			}
			rrn<< cont;
			unsigned long key = atol(ss.str().c_str());
			int position = PosicionIngresoOrdenadoAlIndiceLong(indexClientKey, key);
			if (position == -1){
				indexClientKey.push_back(ss.str());
				indexClientRRN.push_back( rrn.str());
			}else{
				indexClientKey.insert(indexClientKey.begin() + position, ss.str());
				indexClientRRN.insert(indexClientRRN.begin() + position, rrn.str());
			}

		}
		cont++;

	}/*
	for (int i = 0; i < indexClientKey.size(); ++i)
	{
		cout << "Key: " << indexClientKey.at(i) << " RRN: " << indexClientRRN.at(i)<< endl;
	}	*/
	readFile.close();
}
void IndexNumber(){
	indexNumberKey.clear();
	indexNumberRRN.clear();
	ifstream readFile("Numeros.bin",ios::binary);
	readFile.seekg(HeaderSize);
	int cont = 0;

 	while(true){
		stringstream rrn ;
		if(readFile.eof())
			break;
		char Numero[9];
		char Id[14];
		readFile.read(reinterpret_cast<char*>(&Numero), sizeof(Numero));
		readFile.read((char*)Id, sizeof(Id));
		bool iguales = false;
		for (int i = 0; i < sizeof(Numero)-1; ++i){
			if(Numero[i] == '*'){
				iguales = true;	
				break;			
			}
		}
		if(!iguales){
			stringstream ss;
			for (int i = 0; i < sizeof(Numero); ++i){							
				ss<< Numero[i];	
			}
			//cout << ss.str()<<endl;
			rrn<< cont;
			//cout << rrn.str() << "|||"<< endl;
			int key = atoi(ss.str().c_str());
			int position = PosicionIngresoOrdenadoAlIndice(indexNumberKey, key);
			if (position == -1){
				indexNumberKey.push_back(ss.str());
				indexNumberRRN.push_back( rrn.str());
			}else{
				indexNumberKey.insert(indexNumberKey.begin() + position, ss.str());
				indexNumberRRN.insert(indexNumberRRN.begin() + position, rrn.str());
			}

		}
		cont++;

	}
	/*for (int i = 0; i < indexNumberKey.size(); ++i)
	{
		cout << "Key: " << indexNumberKey.at(i) << " RRN: " << indexNumberRRN.at(i)<< endl;
	}	*/
	readFile.close();
}
int PosicionIngresoOrdenadoAlIndice(vector<string> indexKey  , int key){
    int low = 0;
    int high = indexKey.size() - 1;
    int mid;
    bool avoidInfiniteCicle = false;
    
    while(true){
    	if(low > high)
    		break;    	
    	mid = (low + high)/2;
    	if(key == atoi((indexKey.at(mid)).c_str()) )
    		return mid;
    	if(key > atoi((indexKey.at(mid)).c_str())){
    		if(mid != indexKey.size() - 1){
    			if(key < atoi((indexKey.at(mid+1)).c_str())){
    				return mid+1;
    			}else{
    				if(avoidInfiniteCicle && mid == indexKey.size()-2)
    					return -1;
    				low = mid;
    				avoidInfiniteCicle = true;
    			}
    		}else{
    			if(key < atoi((indexKey.at(mid)).c_str())){
    				return mid;
    			}else{
    				return -1;
    			}

    		}
    	}else{
    		if(mid != 0){
    			if(key > atoi((indexKey.at(mid-1)).c_str())){

    				return mid;
    			}else{
    				high = mid;
    			}
    		}else{
    			if(key < atoi((indexKey.at(mid)).c_str())){
    				return mid;
    			}else{
    				return mid+1;
    			}

    		}
    	}
    }
    return -1;
}
int PosicionIngresoOrdenadoAlIndiceLong(vector<string> indexKey  , unsigned long key){
    int low = 0;
    int high = indexKey.size() - 1;
    int mid;
    bool avoidInfiniteCicle = false;
    
    while(true){
    	if(low > high)
    		break;    	
    	mid = (low + high)/2;
    	if(key == atol((indexKey.at(mid)).c_str()) )
    		return mid;
    	if(key > atol((indexKey.at(mid)).c_str())){
    		if(mid != indexKey.size() - 1){
    			if(key < atol((indexKey.at(mid+1)).c_str())){
    				return mid+1;
    			}else{
    				if(avoidInfiniteCicle && mid == indexKey.size()-2)
    					return -1;
    				low = mid;
    				avoidInfiniteCicle = true;
    			}
    		}else{
    			if(key < atol((indexKey.at(mid)).c_str())){
    				return mid;
    			}else{
    				return -1;
    			}

    		}
    	}else{
    		if(mid != 0){
    			if(key > atol((indexKey.at(mid-1)).c_str())){

    				return mid;
    			}else{
    				high = mid;
    			}
    		}else{
    			if(key < atol((indexKey.at(mid)).c_str())){
    				return mid;
    			}else{
    				return mid+1;
    			}

    		}
    	}
    }
    return -1;
}
void borrarCity( int key ){
	char IdCiudad[4];
	char NameCiudad[40];
	
	int position = PosicionIngresoOrdenadoAlIndice(indexCityKey, key);
	string rrn = indexCityRRN.at(position);
	int rrnInteger = atoi(rrn.c_str());
	stringstream rrnToString;
	ifstream readFile("Ciudades.bin", ios::binary);
	readFile.seekg(0);
	int rrnHeader;
	readFile.read(reinterpret_cast<char*>(&rrnHeader), sizeof(int));
	readFile.close();
	ofstream writeFile("Ciudades.bin", ios::out | ios::in);
	if (position != -1){
		IdCiudad[0] ='*';
		rrnToString<< rrnHeader;
		for (int i = 0; i < rrnToString.str().size(); ++i)
		{

			NameCiudad[i] = rrnToString.str()[i];
		}
		writeFile.seekp(HeaderSize + atoi((rrn).c_str())*( sizeof(IdCiudad) + sizeof(NameCiudad) )  );
		writeFile.write(reinterpret_cast<char*>(&IdCiudad), sizeof(IdCiudad) );
		writeFile.write(reinterpret_cast<char*>(&NameCiudad), sizeof(NameCiudad) );// se escribe el rrn en el header
		writeFile.seekp(0);
		writeFile.write(reinterpret_cast<char*>(&rrnInteger), sizeof(rrnInteger));
	}
	indexCityKey.erase(indexCityKey.begin() +position);
	indexCityRRN.erase(indexCityRRN.begin() +position);
	writeFile.close();
}