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
    string NombreCliente, Cedula, Asiento;

public:
    Cliente();//Constructor
    void setNombreCliente(string value);
    void setcedula(string value);
    void setAsiento(string value);
    string getNombreCliente() const;
    string getCedula() const;
    string getAsiento() const;
    int ComprarCombo();
    //Las 3 funciones siguientes se utilizan para descontar ingredientes luego de comprar combo
   void  DescontarIngredienteCombo();
    void inserta_nombre(string linea, map<string, string>& nombres);
    void leer_datos(string, map<string, string>&);
    int HayONoHayIngredientesParaCombo ();
    int MenuCompradeCombos();
};
#endif // CLIENTE_H
