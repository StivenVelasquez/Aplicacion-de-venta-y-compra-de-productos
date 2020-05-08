#include "compradeproductoscine.h"

/*Cliente::Cliente()
{

}

*/
/*void Empleado::SetNombre(string nombre)
{
    m_nombre = nombre;
}

void Empleado::SetContrasena(string contrasena)
{
    m_contrasena = contrasena;

}

const  string Empleado::GetNombre()
{
    return m_nombre;
}

const string Empleado::GetContrasena()
{
    return m_contrasena;
}


Empleado::Empleado()
{

}



void Cliente::setNombreCliente(string NombreCliente)
{
    m_NombreCliente=NombreCliente;
}

void Cliente::setcedula(string Cedula)
{
    m_Cedula=Cedula;
}

const string Cliente::getNombreCliente()
{
    return m_NombreCliente;
}

const string Cliente::getCedula()
{
    return m_Cedula;
}

void Cliente::lecturaCedula(fstream consulta, string cedula)
{
    consulta>>cedula;
}
*/

Empleado::Empleado()
{

}

void Empleado::SetNombre(string value)
{
   nombre=value;
}

void Empleado::SetContrasena(string value)
{
    contrasena=value;
}

string Empleado::GetNombre() const
{
    return contrasena;
}

string Empleado::GetContrasena() const
{
    return nombre;
}
