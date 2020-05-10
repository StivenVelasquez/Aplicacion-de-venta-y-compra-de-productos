#ifndef EMPLEADO_H
#define EMPLEADO_H


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
        void GenerarReporteVentas();
        int salir();
};

#endif // EMPLEADO_H
