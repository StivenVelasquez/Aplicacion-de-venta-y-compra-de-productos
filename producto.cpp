#include "producto.h"

PRODUCTO::PRODUCTO()
{

}

void PRODUCTO::Setcosto(int value)
{
   costo=value;
}

void PRODUCTO::Setcantidad(int value)
{
    cantidad=value;
}

void PRODUCTO::setID(string value)
{
    ID=value;
}

void PRODUCTO::setDescripcionProd(string value)
{
    DescripcionProd=value;
}

int PRODUCTO::Getcosto() const
{
    return costo;
}

int PRODUCTO::Getcantidad() const
{
    return cantidad;
}

string PRODUCTO::GetID() const
{
    return ID;
}

string PRODUCTO::GetDescripcionProd() const
{
    return DescripcionProd;
}
