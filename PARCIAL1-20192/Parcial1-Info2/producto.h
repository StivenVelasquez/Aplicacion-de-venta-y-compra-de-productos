#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
using namespace std;

class PRODUCTO
{
private:
    int costo;
    int cantidad;
    string ID;
    string DescripcionProd;
public:
    PRODUCTO();
    void Setcosto( int value );
    void Setcantidad( int value);
    void setID(string value);
    void setDescripcionProd(string value);
    int Getcosto( ) const;
    int Getcantidad( ) const;
    string GetID() const;
    string GetDescripcionProd() const;
};

#endif // PRODUCTO_H
