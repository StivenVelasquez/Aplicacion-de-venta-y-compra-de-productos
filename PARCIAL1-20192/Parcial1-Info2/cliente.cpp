#include "cliente.h"

Cliente::Cliente()
{

}

void Cliente::setNombreCliente(string value)
{
   NombreCliente=value;
}

void Cliente::setcedula(string value)
{
    Cedula=value;
}

string Cliente::getNombreCliente() const
{
    return NombreCliente;
}

string Cliente::getCedula() const
{
    return Cedula;
}

void Cliente::ComprarCombo()
{
    cout<<endl;
    cout<<endl;
    cout<<"======================================================="<<endl;
    cout<<"*****INGRESE EL ID DEL COMBO QUE DESEA COMPRAR*********"<<endl;
    cout<<"======================================================="<<endl;
    cout<<endl;


}
