#ifndef LLAMADA_H
#define LLAMADA_H
#include <cstring>
class Llamada{
	protected:
		int Numero;
		double FechaInicio;
		double FechaFinal;
		int IdCiudad;
	public:
		Llamada(int, double, double, int);
	    void setNumero(int Id);
	    void setFechaInicio(double Final);
	    void setFechaFinal(double Inicio);
	    void setIdCiudad(int IdCiudad);
	    int getNumero();
	    double getFechaInicio();
	    double getFechaFinal();
	    int setIdCiudad();

};

#endif
