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
            case 1:
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

         case 2:
        {
         //-----------------------------------------------------------------------------------------------------------------------------------
         //PARA LOS CLIENTES
         //-----------------------------------------------------------------------------------------------------------------------------------

            int opcion=0, opcion2;

            cout<<"|.......................................................|"<<endl;
            cout<<"|.........BIENVENIDO AL PUNTO DE VENTAS DEL CINE........|"<<endl;
            cout<<"|.......................................................|"<<endl;
            cout<<"|1. Registrarse.........................................|"<<endl;
            cout<<"|2. Salir...............................................|"<<endl;
            cout<<"|....................QUE DESEA HACER?...................|"<<endl;
            cout<<"|.......................................................|"<<endl;
            cout<<endl;

            cin>>opcion2;
            cout<<"--------------------------------------------------------"<<endl;
            cout<<endl;

            switch (opcion2) {

                case 1:
                {
                cout<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<"|....INGRESE EL NUMERO DE SALA DONDE DESEA UBICARSE.....|"<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<"|1. SALA 1..............................................|"<<endl;
                cout<<"|2. SALA 2..............................................|"<<endl;
                cout<<"|3. SALA 3..............................................|"<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<"|....................INGRESE LA SALA....................|"<<endl;
                cout<<"|.......................................................|"<<endl;

                int OpcSala;

                cout<<"INGRESE UNA OPCION"<<endl;

                cin>>OpcSala;

                cout<<"---------------------------------------------------------"<<endl;

                string OpcionAsiento=0;

                switch (OpcSala){

                    case 1:
                    {
                        cout<<endl;
                        //Declaracion de variables
                        ofstream escritura;
                        ifstream consulta;
                        bool repetido=false;
                        string linea, linea2, linea3, linea4;

                        cout<<"A CONTINUACION SE MUESTRAN LOS ASIENTOS OCUPADOS"<<endl;
                        cout<<endl;

                        ifstream lectura("Sala de Cine 1.txt"); //Apertura del archivo en modo lectura
                        if(lectura.is_open()){
                            while (getline(lectura, linea)){

                                cout <<"Asiento: "<< linea <<" esta ocupado"<<endl;

                            }
                        }
                        lectura.close();

                        cout<<"INGRESE EL NUMERO DEL ASIENTO QUE DESEA OCUPAR: ";
                        cin>>OpcionAsiento;
                        Cliente1.setcedula(OpcionAsiento);
                        cout<<endl;

                        escritura.open("Sala de Cine 1.txt",ios::out|ios::app);
                        consulta.open("Sala de Cine 1.txt",ios::in);

                         if(escritura.is_open() && consulta.is_open()){

                             consulta>>linea>>linea2>>linea3>>linea4;

                             while(!consulta.eof()){
                                 if(linea4==Cliente1.getAsiento()){
                                     cout<<"|-------------------------------------------------------|"<<endl;
                                     cout<<"|-----------------Este asiento esta ocupado-------------|"<<endl;
                                     cout<<"|-------------------------------------------------------|"<<endl;
                                     cout<<endl;
                                     repetido=true;
                                     return 0;
                                 }

                             consulta>>linea;

                             }

                             if(repetido==false){

                                 string nombre, cedula;
                                 cout<<"INGRESE SU NOMBRE: ";
                                 cin>>nombre;
                                 Cliente1.setNombreCliente(nombre);
                                 cout<<endl;
                                 cout<<"INGRESE SU NUMERO DE IDENTIFICACION: ";
                                 cin>>cedula;
                                 Cliente1.setcedula(cedula);
                                 cout<<endl;

                                 //Se pasa a imprimir los datos en el fichero de una manera organizada
                                 escritura<<left<<setw(10)<<Cliente1.getNombreCliente()<<setw(13)<<Cliente1.getCedula()<<setw(7)<<setprecision(2)<<right<<OpcSala<<setw(7)<<setprecision(2)<<right<<Cliente1.getAsiento()<<endl;

                                 cout<<endl;

                                 cout<<"|=======================================================|"<<endl;
                                 cout<<"|======Registro Agregado bienvenido a nuestro cine======|"<<endl;
                                 cout<<"|=======================================================|"<<endl;

                                 cout<<endl;

                                 cout<<endl;
                             }


                         }

                         else{
                             cout<<"-Error, el Archivo No se Pudo Abrir o No ha sido Creado-"<<endl;
                             cout<<endl;
                         }

                        //Cerrando los archivos
                         escritura.close();
                         consulta.close();

                    }
                    break;

                case 2:
                {
                    cout<<endl;
                    //Declaracion de variables
                    ofstream escritura;
                    ifstream consulta;
                    bool repetido=false;
                    string linea, linea2, linea3, linea4;

                    cout<<"A CONTINUACION SE MUESTRAN LOS ASIENTOS OCUPADOS"<<endl;
                    cout<<endl;

                    ifstream lectura("Sala de Cine 2.txt"); //Apertura del archivo en modo lectura
                    if(lectura.is_open()){
                        while (getline(lectura, linea)){

                            cout <<"Asiento: "<< linea <<" esta ocupado"<<endl;

                        }
                    }
                    lectura.close();

                    cout<<"INGRESE EL NUMERO DEL ASIENTO QUE DESEA OCUPAR: ";
                    cin>>OpcionAsiento;
                    Cliente1.setcedula(OpcionAsiento);
                    cout<<endl;

                    escritura.open("Sala de Cine 2.txt",ios::out|ios::app);
                    consulta.open("Sala de Cine 2.txt",ios::in);

                     if(escritura.is_open() && consulta.is_open()){

                         consulta>>linea>>linea2>>linea3>>linea4;

                         while(!consulta.eof()){
                             if(linea4==Cliente1.getAsiento()){
                                 cout<<"|-------------------------------------------------------|"<<endl;
                                 cout<<"|-----------------Este asiento esta ocupado-------------|"<<endl;
                                 cout<<"|-------------------------------------------------------|"<<endl;
                                 cout<<endl;
                                 repetido=true;
                                 return 0;
                             }

                         consulta>>linea;

                         }

                         if(repetido==false){

                             string nombre, cedula;
                             cout<<"INGRESE SU NOMBRE: ";
                             cin>>nombre;
                             Cliente1.setNombreCliente(nombre);
                             cout<<endl;
                             cout<<"INGRESE SU NUMERO DE IDENTIFICACION: ";
                             cin>>cedula;
                             Cliente1.setcedula(cedula);
                             cout<<endl;

                             //Se pasa a imprimir los datos en el fichero de una manera organizada
                             escritura<<left<<setw(10)<<Cliente1.getNombreCliente()<<setw(13)<<Cliente1.getCedula()<<setw(7)<<setprecision(2)<<right<<OpcSala<<setw(7)<<setprecision(2)<<right<<Cliente1.getAsiento()<<endl;

                             cout<<endl;

                             cout<<"|=======================================================|"<<endl;
                             cout<<"|======Registro Agregado bienvenido a nuestro cine======|"<<endl;
                             cout<<"|=======================================================|"<<endl;

                             cout<<endl;

                             cout<<endl;
                         }


                     }

                     else{
                         cout<<"-Error, el Archivo No se Pudo Abrir o No ha sido Creado-"<<endl;
                         cout<<endl;
                     }

                    //Cerrando los archivos
                     escritura.close();
                     consulta.close();
                }

                case 3:
                {
                    cout<<endl;
                    //Declaracion de variables
                    ofstream escritura;
                    ifstream consulta;
                    bool repetido=false;
                    string linea, linea2, linea3, linea4;

                    cout<<"A CONTINUACION SE MUESTRAN LOS ASIENTOS OCUPADOS"<<endl;
                    cout<<endl;

                    ifstream lectura("Sala de Cine 3.txt"); //Apertura del archivo en modo lectura
                    if(lectura.is_open()){
                        while (getline(lectura, linea)){

                            cout <<"Asiento: "<< linea <<" esta ocupado"<<endl;

                        }
                    }
                    lectura.close();

                    cout<<"INGRESE EL NUMERO DEL ASIENTO QUE DESEA OCUPAR: ";
                    cin>>OpcionAsiento;
                    Cliente1.setcedula(OpcionAsiento);
                    cout<<endl;

                    escritura.open("Sala de Cine 3.txt",ios::out|ios::app);
                    consulta.open("Sala de Cine 3.txt",ios::in);

                     if(escritura.is_open() && consulta.is_open()){

                         consulta>>linea>>linea2>>linea3>>linea4;

                         while(!consulta.eof()){
                             if(linea4==Cliente1.getAsiento()){
                                 cout<<"|-------------------------------------------------------|"<<endl;
                                 cout<<"|-----------------Este asiento esta ocupado-------------|"<<endl;
                                 cout<<"|-------------------------------------------------------|"<<endl;
                                 cout<<endl;
                                 repetido=true;
                                 return 0;
                             }

                         consulta>>linea;

                         }

                         if(repetido==false){

                             string nombre, cedula;
                             cout<<"INGRESE SU NOMBRE: ";
                             cin>>nombre;
                             Cliente1.setNombreCliente(nombre);
                             cout<<endl;
                             cout<<"INGRESE SU NUMERO DE IDENTIFICACION: ";
                             cin>>cedula;
                             Cliente1.setcedula(cedula);
                             cout<<endl;

                             //Se pasa a imprimir los datos en el fichero de una manera organizada
                             escritura<<left<<setw(10)<<Cliente1.getNombreCliente()<<setw(13)<<Cliente1.getCedula()<<setw(7)<<setprecision(2)<<right<<OpcSala<<setw(7)<<setprecision(2)<<right<<Cliente1.getAsiento()<<endl;

                             cout<<endl;

                             cout<<"|=======================================================|"<<endl;
                             cout<<"|======Registro Agregado bienvenido a nuestro cine======|"<<endl;
                             cout<<"|=======================================================|"<<endl;

                             cout<<endl;

                             cout<<endl;
                         }


                     }

                     else{
                         cout<<"-Error, el Archivo No se Pudo Abrir o No ha sido Creado-"<<endl;
                         cout<<endl;
                     }

                    //Cerrando los archivos
                     escritura.close();
                     consulta.close();
                }

                default:
                    break;
                }

            }
            }


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


