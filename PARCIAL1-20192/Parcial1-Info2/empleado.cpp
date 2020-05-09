#include "empleado.h"
#include <iomanip>
#include <vector>

//Clase empleado

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
    ofstream aux,aux2;
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
    aux2.open("ListaProductos2.txt",ios::out);

    if(aux.is_open() && lectura.is_open()&& aux2.is_open()){

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

                    aux2<<left<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<endl;

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
               aux2<<left<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<endl;

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
                aux2<<left<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<endl;


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
   aux2.close();
   remove("ListaProductos.txt"); //Se borra el fichero
   rename("auxiliar.txt","ListaProductos.txt"); //Se renombran los ficheros


}//Fin funcion Registrar

int Empleado::CrearCombos()
{
   //Aca se leen los productos disponibles en el fichero y se pasan a un vector para luego imprimirlos en pantalla;
   vector<string>list;
   string line;
   string producto;
   string perro, hamburguesa, gaseosa, nachos;

   cout<<"===================PRODUCTOS DISPONIBLES==============="<<endl;
   cout<<endl;
   cout<<left<<setw(10)<<"PRODUCTO"<<setw(13)<<setprecision(2)<<setw(13)<<right<<"                    CANTIDAD"<<endl;
   cout<<endl;

   ifstream lectura("ListaProductos2.txt"); //Apertura del archivo en modo lectura
   if(lectura.is_open()){
       while (getline(lectura, producto)){
           list.push_back(producto);
           cout << producto << endl;
           list.pop_back();
       }
   }
   lectura.close();

   //Se imprime el vector
   for (int i = 0; i < list.size(); i++){
       cout << list[i];
       cout << endl;
   }
   cout<<endl;

   int n=0;
   string NombreCombo, IDCombo;

   cout<<"-------------------------------------------------------"<<endl;

   cout<<"INGRESE EL NOMBRE QUE DESEA DARLE AL COMBO "<<endl;
   cin>>NombreCombo;

   cout<<"-------------------------------------------------------"<<endl;
   cout<<endl;

   cout<<"INGRESE EL ID DEL COMBO QUE DESEA CREAR: "<<endl;
   cin>>IDCombo;

   cout<<"-------------------------------------------------------"<<endl;
   cout<<endl;




   ofstream escritura;
   escritura.open("Combos.txt",ios::out|ios::app);

   if(escritura.is_open()){
      escritura<<endl;
      escritura<<"ID: "<<IDCombo<<endl;
      escritura<<"COMBO "<<NombreCombo<<endl;
      escritura<<"-----------------"<<endl;
      escritura<<endl;
   }

   escritura.close();

do{

   cout<<"|-------------------------------------------------------|\n";
   cout<<"|----------------MENU PARA CREAR COMBOS-----------------|\n";
   cout<<"|-------------------------------------------------------|\n";
   cout<<"|-------------------------------------------------------|\n";
   cout<<"|1.PERRO------------------------------------------------|\n";
   cout<<"|2.HAMBURGUESA------------------------------------------|\n";
   cout<<"|3.GASEOSA----------------------------------------------|\n";
   cout<<"|4.PAQUETES DE NACHOS-----------------------------------|\n";
   cout<<"|5.FINALIZAR CREACION DE COMBO--------------------------|\n";
   cout<<"|-------------------------------------------------------|\n";

   cout<<endl;
   cout<<"------------------------------------------------------"<<endl;
   cout<<"CON CUALES INGREDIENTES DESEA ARMAR EL COMBO?"<<endl;
   cout<<endl;
   cout<<"------------------------------------------------------"<<endl;
   cout<<"INGRESE UNA OPCION: ";
   cin>>n;
   cout<<"------------------------------------------------------"<<endl;
   cout<<endl;

   switch (n) {

       case 1:
       {
           int Cant_Perros;
           escritura.open("Combos.txt",ios::out|ios::app);
           if(escritura.is_open()){
               cout<<"INGRESE LA CANTIDAD DE PERROS: "<<endl;
               cin>>Cant_Perros;

               if(Cant_Perros==1){
                   escritura<<Cant_Perros<<" PERRO"<<endl;
               }

               else{
                   escritura<<Cant_Perros<<" PERROS"<<endl;
               }
               cout<<"------------------------------------------------------"<<endl;
               cout<<endl;
           }
        escritura.close();
       }
       break;

       case 2:
       {
           int Cant_Hamburguesas;
           escritura.open("Combos.txt",ios::out|ios::app);
           if(escritura.is_open()){
               cout<<"INGRESE LA CANTIDAD DE HAMBURGUESAS: "<<endl;
               cin>>Cant_Hamburguesas;
               if(Cant_Hamburguesas==1){
                  escritura<<Cant_Hamburguesas<<" HAMBURGUESA"<<endl;
               }

               else{
                  escritura<<Cant_Hamburguesas<<" HAMBURGUESAS"<<endl;
               }
               cout<<"------------------------------------------------------"<<endl;
               cout<<endl;

           }
       escritura.close();
       }
       break;

       case 3:
       {
           int Cant_Gaseosas;
           escritura.open("Combos.txt",ios::out|ios::app);
           if(escritura.is_open()){
               cout<<"INGRESE LA CANTIDAD DE GASEOSAS: "<<endl;
               cin>>Cant_Gaseosas;
               if(Cant_Gaseosas==1){
                   escritura<<Cant_Gaseosas<<" GASEOSA"<<endl;
               }

               else{
                    escritura<<Cant_Gaseosas<<" GASEOSAS"<<endl;
               }
               cout<<"------------------------------------------------------"<<endl;
               cout<<endl;

           }
       escritura.close();
       }
       break;

       case 4:
       {
           int Cant_PaquetesNachos;
           escritura.open("Combos.txt",ios::out|ios::app);
           if(escritura.is_open()){
               cout<<"INGRESE LA CANTIDAD DE PAQUETES DE NACHOS: "<<endl;
               cin>>Cant_PaquetesNachos;
               if(Cant_PaquetesNachos==1){
                   escritura<<Cant_PaquetesNachos<<" PAQUETE DE NACHOS"<<endl;
               }
               else{
                    escritura<<Cant_PaquetesNachos<<" PAQUETES DE NACHOS"<<endl;
               }
               cout<<"------------------------------------------------------"<<endl;
               cout<<endl;

           }
       escritura.close();
       }
       break;

        case 5:
       {
       escritura.open("Combos.txt",ios::out|ios::app);
       if(escritura.is_open()){
           escritura<<endl;
           escritura<<"-----------------"<<endl;
           escritura<<endl;
       }
       escritura.close();
       return -1;
       }
       break;

       default:
           cout<<"|=======================================================|"<<endl;
           cout<<"|=================¡Opcion Incorrecta!===================|"<<endl;
           cout<<"|=======================================================|"<<endl;

       }
   }while(n>0);

cin.get();

}


int Empleado::salir()
{
    cout<<"|=======================================================|"<<endl;
    cout<<"|==================Proceso finalizado===================|"<<endl;
    cout<<"|=======================================================|"<<endl;
    cout<<endl;
    return -1;
}
