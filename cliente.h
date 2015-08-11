#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
using namespace std;
class Cliente{
  protected:
    string Id;
    char* Name;
    char Gender;
    string IdCiudad;


  public:
    Cliente(string, char [] ,char,string);
    void setId(string Id);
    void setName(char* Name);
    void setGender(char Gender);
    void setIdCiudad(string IdCiudad);
    string getId();
    char* getName();
    char getGender();
    string setIdCiudad();
};

#endif