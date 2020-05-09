#ifndef COMPRADEPRODUCTOSCINE_H
#define COMPRADEPRODUCTOSCINE_H
#include <iostream>
#include <conio.h> // getch
#include <fstream>
#include <vector>

using namespace std;


class Empleado {
    private:
        string nombre;
        string contrasena;

    public:
        Empleado(); //Constructor;
        void SetNombre( string value );
        void SetContrasena( string value);
        string GetNombre( ) const;
        string GetContrasena( ) const;
        void registrar();
        int CrearCombos();
        int salir();
};

/*class Cliente
{

private:
    string m_NombreCliente, m_Cedula;

public:
    Cliente();
    void lecturaCedula(fstream, string);
    void setNombreCliente(string NombreCliente);
    void setcedula(string Cedula);
 //    string getNombreCliente();
 //    string getCedula();

};
*/

#endif // COMPRADEPRODUCTOSCINE_H
