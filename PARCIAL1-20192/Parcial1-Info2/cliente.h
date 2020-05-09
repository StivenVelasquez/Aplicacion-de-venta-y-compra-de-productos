#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

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
    void ComprarCombo();

};
#endif // CLIENTE_H
