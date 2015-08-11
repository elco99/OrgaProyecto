#ifndef CLIENTE_H
#define CLIENTE_H
#include <cstring>
class Cliente{
  protected:
    int Id;
    char* Name;
    char Gender;
    int IdCiudad;


  public:
    Cliente(int, char [] ,char,int);
    void setId(int Id);
    void setName(char* Name);
    void setGender(char Gender);
    void setIdCiudad(int IdCiudad);
    int getId();
    char* getName();
    char getGender();
    int setIdCiudad();
};

#endif