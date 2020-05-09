#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <fstream>
#include <list>

using namespace  std;

class Cliente
{

private:
    string NombreCliente, Cedula;

public:
    Cliente();//Constructor
    void setNombreCliente(string value);
    void setcedula(string value);
    string getNombreCliente() const;
    string getCedula() const;
    int ComprarCombo();

};
#endif // CLIENTE_H
