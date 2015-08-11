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


using namespace std;

int main(int argc, char* argv[]){
	srand(time(0));
	for (int i = 0; i < 5; ++i)
	{
		stringstream ko;
		ko << rand() % 10 << rand() % 10<< rand() % 10<< rand() % 10 << (rand() % 98 + 1900) << (rand() % 90000+10000);
		cout << ko.str() << endl;
	}
	return 0;
}
