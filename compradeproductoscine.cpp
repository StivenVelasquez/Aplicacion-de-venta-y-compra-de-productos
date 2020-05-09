#include "compradeproductoscine.h"
#include "producto.h"
#include <iomanip>

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
    return nombre;
}

string Empleado::GetContrasena() const
{
    return contrasena;
}

void Empleado::registrar()
{

    //Declaracion de variables
    ofstream aux;
    ifstream lectura;
    bool encontrado=false;
    string auxID,ID,Producto;
    int Cantidad, CostoTotal, CostoProducto, cuantos, CantidadModificada,CostoTotalModificado;
    \
    cout<<"INGRESE ID DEL PRODUCTO ";
    cin>>auxID;
    cout<<endl;

    //Se abren los ficheros a utilizar
    aux.open("auxiliar.txt",ios::out);
    lectura.open("ListaProductos.txt",ios::in);

    if(aux.is_open() && lectura.is_open()){

        cout<<endl;
        cout<<"--------------------------------------------------------";
        cout<<endl;

        lectura>>ID;

        while(!lectura.eof()){
            lectura>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
           if(auxID==ID){
              encontrado=true;

                if(CostoTotal<=0) {
                    cout<<endl;
                    CostoTotal=0; //para que no ponga resultados negativos en la base de datos
                    cout<<"|-------------------------------------------------------|"<<endl;
                    cout<<"|EL CINE NO CUENTA CON "<<Producto<<"POR FAVOR ADQUIERA-|"<<endl;
                    cout<<"|-ESTE PRODUCTO, EL CUAL ES NECESARIO PARA LAS VENTAS---|"<<endl;
                    cout<<"|-------------------------------------------------------|"<<endl;
                    cout<<endl;

                    aux<<left<<setw(10)<<ID<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoProducto<<endl;

                    break;

                }

                cout<<endl;
                cout<<"________________________________________________________"<<endl;
                cout<<"PRODUCTO: "<<Producto<<endl;
                cout<<"CANTIDAD: "<<Cantidad<<endl;
                cout<<"COSTO DEL PRODUCTO: "<<CostoProducto<<endl;
                cout<<"COSTO TOTAL: "<<CostoTotal<<endl;
                cout<<"________________________________________________________"<<endl;
                cout<<endl;

                cout<<"INGRESA LA CANTIDAD DE "<<Producto<<" QUE DESEA REGISTRAR: "<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                cin>>cuantos;
                cout<<endl;
                cout<<"________________________________________________________"<<endl;

                CantidadModificada=Cantidad+cuantos;
                CostoTotalModificado=CostoTotal+(cuantos*CostoProducto);

                //Para imprimir de manera organizada en el fichero
               aux<<left<<setw(10)<<ID<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotalModificado<<endl;

                cout<<"|-------------------------------------------------------|"<<endl;
                cout<<"|-----------------REGISTRO MODIFICADO-------------------|"<<endl;
                cout<<"|-------------------------------------------------------|"<<endl;
                cout<<endl;

                //Actualizacion de datos
                Cantidad=CantidadModificada;
                CostoTotal=CostoTotalModificado;


            }

            else
               //Imprimir de manera orgnizada en el fichero
                aux<<left<<setw(10)<<ID<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;



     lectura>>ID;

        }
    }


   else{
           cout<<"--No se pudo abrir el Archivo o aun no ha sido Creado--"<<endl;
           cout<<endl;
       }

   if(encontrado==false){
           cout<<endl;
           cout<<"-No se encontro ningun registro con ese ID-"<<endl;
           cout<<endl;
           cout<<endl;
       }

   //Cerrando los archivos
   aux.close();
   lectura.close();
   remove("ListaProductos.txt"); //Se borra el fichero
   rename("auxiliar.txt","ListaProductos.txt"); //Se renombran los ficheros


}//Fin funcion Registrar

void Empleado::CrearCombos()
{

}


void Empleado::salir()
{
    cout<<"|=======================================================|"<<endl;
    cout<<"|==================Proceso finalizado===================|"<<endl;
    cout<<"|=======================================================|"<<endl;
    cout<<endl;
}


