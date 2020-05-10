#include <iostream>
#include "empleado.h"
#include "cliente.h"
#include <cstdlib>
#include <iomanip>
#include <list>
#include <vector>

using namespace std;

int saldo=0;
string cedula;

int main()
{
    //Se instancian las clases
    Empleado Empleado1;
    Cliente Cliente1;

    int n;

    do{
        cout<<endl;
        cout<<"|-------------------------------------------------------|\n";
        cout<<"|BIENVENIDO AL SISTEMA DE COMPRA DE PRODUCTOS DEL CINE--|\n";
        cout<<"|-----------DE LA UNIVERSIDAD DE ANTIOQUIA--------------|\n";
        cout<<"|-------------------------------------------------------|\n";
        cout<<"|-------------------------MENU--------------------------|\n";
        cout<<"|-------------------------------------------------------|\n";
        cout<<"|........Es usted empleado?............................1|\n";
        cout<<"|........Es usted cliente?.............................2|\n";
        cout<<"|-------------------------------------------------------|\n";

        cout<<endl;

        cout<<"INGRESE UNA OPCION: ";
        cin>>n;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<endl;

        switch (n) {

       //-------------------------------------------------------------------------------------------------------------------------------------
       //PARA LOS EMPLEADOS
       //-------------------------------------------------------------------------------------------------------------------------------------
            case 2:
                   {

                    //Declaracion de variables
                    char cadena[128];
                    string password,nombreEmpleado;
                    int Decision=0;
                    char caracter;

                    //Declaracion de macros-identificadores que seran utilizados para encriptar la contrasena
                    #define ENTER 13
                    #define BACKSPACE 8

                    ifstream ficheroAutenticacion("Contrasena.txt");//se abre el fichero donde se encuentra la contrasena que lo acredita
                                                                                                     //como administrador
                    while (!ficheroAutenticacion.eof()) {
                      ficheroAutenticacion >> cadena;
                    }

                    cout<<"INGRESE SU NOMBRE: ";
                    cin>>nombreEmpleado;
                    Empleado1.SetNombre(nombreEmpleado);

                     cout<<"INGRESE CONTRASENA: ";


                        //La contrasena ingresada se cifra a un estilo password con el simbolo "*"
                        caracter = getch();
                        password = "";

                        while (caracter != ENTER) {

                            if (caracter != BACKSPACE) {
                                password.push_back(caracter);
                                cout << "*";

                            }

                            else {
                                if (password.length() > 0) {
                                    cout << "\b \b";
                                    password = password.substr(0, password.length() - 1);
                                }

                            }

                            caracter = getch();
                         }

                    cout<<endl;
                    cout<<"........................................................."<<endl;

                    cout<<endl;

                    Empleado1.SetContrasena(password);

                    if(cadena==password)
                      {  Decision=0;
                        cout<<"|-------------------------------------------------------|\n";
                        cout<<"|................Bienvenido.."<<Empleado1.GetNombre()<<".....................|\n";
                        cout<<"|.........Usted es uno de nuestros empleados............|\n";
                        cout<<"|Ahora Podra Acceder a Nuestro sistema de Base de Datos.|\n";
                        cout<<"|-------------------------------------------------------|\n";
                        cout<<endl;
                        cout<<"........................................................"<<endl;
                    }

                    else {

                        Decision=1;
                        cout<<"|--------------------------------------------------------|"<<endl;
                        cout<<"|.............USTED NO ES EMPLEADO EN ESTE CINE..........|"<<endl;
                        cout<<"|....NO TIENE PERMISOS PARA ACCEDER A LA BASE DE DATOS...|"<<endl;
                        cout<<"|........................................................|"<<endl;
                        cout<<"|....EN POCOS SEGUNDOS VOLVERA A NUESTRO MENU DE INICIO..|"<<endl;
                        cout<<"|--------------------------------------------------------|"<<endl;
                        cout<<endl;
                        cout<<"........................................................"<<endl;

                    }

                    if(Decision==0){
                        //Registro de productos
                        int opcion1=0;


                               do{
                                        cout<<"|.......................................................|"<<endl;
                                        cout<<"|.......REGISTRO DE PRODUCTOS EN LA BASE DE DATOS.......|"<<endl;
                                        cout<<"|.......................................................|"<<endl;
                                        cout<<"|1. Registrar un producto...............................|"<<endl;
                                        cout<<"|2. Crear un combo para la venta........................|"<<endl;
                                        cout<<"|3. Generar reporte de las ventas realizadas al dia.....|"<<endl;
                                        cout<<"|4. Salir...............................................|"<<endl;
                                        cout<<"|....................QUE DESEA HACER?...................|"<<endl;
                                        cout<<"|.......................................................|"<<endl;
                                        cout<<endl;

                                        cin>>opcion1;
                                        cout<<"--------------------------------------------------------"<<endl;
                                        cout<<endl;

                                        switch(opcion1){
                                            case 1:
                                                Empleado1.registrar(); //Funcion para registrar los productos
                                            break;

                                            case 2:
                                               Empleado1.CrearCombos();//Funcion para crear los combos
                                            break;
                                            case 3:
                                                Empleado1.GenerarReporteVentas();
                                            break;

                                            case 4:
                                                Empleado1.salir(); //Para salir
                                            break;

                                            default:
                                                cout<<"|=======================================================|"<<endl;
                                                cout<<"|=================¡Opcion Incorrecta!===================|"<<endl;
                                                cout<<"|=======================================================|"<<endl;
                                        }
                                    }while(opcion1!=2);


                   }

                    ficheroAutenticacion.close();  //Se cierra el archivo


                }
                break;

         case 1:
        {
         //-----------------------------------------------------------------------------------------------------------------------------------
         //PARA LOS CLIENTES
         //-----------------------------------------------------------------------------------------------------------------------------------

            int opcion=0;

            do{
                cout<<"|.......................................................|"<<endl;
                cout<<"|.........BIENVENIDO AL PUNTO DE VENTAS DEL CINE........|"<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<"|1. Comprar un combo....................................|"<<endl;
                cout<<"|3. Salir...............................................|"<<endl;
                cout<<"|....................QUE DESEA HACER?...................|"<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<endl;

                cin>>opcion;
                cout<<"--------------------------------------------------------"<<endl;
                cout<<endl;

                switch (opcion) {

                    case 1:

                    {

                        list<string> lalista; //Lista de string
                        string line,producto;

                        //Se muestra la lista de los combos, para esto agregamos las lineas del archivo en una lista

                        cout<<"------------------LISTA DE COMBOS-----------------------" << endl;
                        cout<<"--------------------------------------------------------" <<endl;
                        cout<<endl;

                        ifstream lectura("Combos.txt"); //Apertura del archivo en modo lectura

                        if(lectura.is_open()){
                            while (getline(lectura, producto)){ //leer lineas del fichero
                                lalista.push_back(producto); //Se van agragando las lineas del archivo a la lista
                                cout << producto << endl;
                                lalista.pop_back(); //se elimina el ultimo elemento
                            }
                        }

                        lectura.close(); //Se cierra el archivo

                        while( lalista.size()!=0 ) //mientras la lista no este vacia
                        {
                          producto = lalista.front();
                          cout << producto << endl;
                          lalista.pop_front(); //Elimina el primer elemento
                        }

             //----------------------------------------------------------------------------------------------

                    Cliente1.ComprarCombo();  //Funcion para comprar los combos


                    } //case 1

                }




               }
            while(opcion!=0);

        }




        case 0:
            return -1;

         default:
            cout<<"|========================================================|"<<endl;
            cout<<"|=============El valor ingresado no es valido============|"<<endl;
            cout<<"|========================================================|"<<endl;
            break;
    }
} while(n!=0);

cin.get();
return 0;


}


