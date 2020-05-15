#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>
#include <list>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <cstdio>
#include <cstdlib>

using namespace  std;

class Cliente
{

private: //Atributos
    string NombreCliente, Cedula;
     string Asiento;

public://metodos
    Cliente();//Constructor
    void setNombreCliente(string value);
    void setcedula(string value);
    void setAsiento(string value);
    string getNombreCliente() const;
    string getCedula() const;
    string getAsiento() const;
    int ComprarCombo();
    int HayONoHayIngredientesParaCombo ();
    int MenuCompradeCombos(); //Menu para la compra de los combos
    //Las 3 funciones siguientes se utilizan para descontar ingredientes luego de comprar combo
   void  DescontarIngredienteCombo();
    void inserta_nombre(string linea, map<string, string>& nombres);
    void leer_datos(string, map<string, string>&);
};
#endif // CLIENTE_H
