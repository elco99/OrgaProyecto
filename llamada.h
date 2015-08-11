#ifndef LLAMADA_H
#define LLAMADA_H
#include <cstring>
#include <string>
using namespace std;
class Llamada{
	protected:
		string Numero;
		double FechaInicio;
		double FechaFinal;
		string IdCiudad;
	public:
		Llamada(string, double, double, string);
	    void setNumero(string Id);
	    void setFechaInicio(double Final);
	    void setFechaFinal(double Inicio);
	    void setIdCiudad(string IdCiudad);
	    string getNumero();
	    double getFechaInicio();
	    double getFechaFinal();
	    string setIdCiudad();
};

#endif
