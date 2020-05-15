#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <conio.h> // getch
#include <fstream>
#include <vector>

using namespace std;

class Empleado {
    private: //Atributos
        string nombre;
        string contrasena;

    public: //Metodos
        Empleado(); //Constructor;
        void SetNombre( string value );
        void SetContrasena( string value);
        string GetNombre( ) const;
        string GetContrasena( ) const;
        void registrar();
        int CrearCombos();
        int GenerarReporteVentas();
        int salir();
};

#endif // EMPLEADO_H
