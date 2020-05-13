#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <fstream>
#include <list>
#include <string.h>
#include <map>

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
   void  DescontarIngredienteCombo();
    void inserta_nombre(string linea, map<string, string>& nombres); //Funcion para descontar ingredientes
    void leer_datos(string, map<string, string>&);
    int HayONoHayIngredientesParaCombo ();

};
#endif // CLIENTE_H
