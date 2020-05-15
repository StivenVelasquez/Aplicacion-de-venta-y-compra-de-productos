#include <iostream>
#include "empleado.h"
#include "cliente.h"
#include <cstdlib>
#include <iomanip>
#include <list>
#include <vector>

using namespace std;

int main()
{
    //Se instancian las clases
    Empleado Empleado1;
    Cliente Cliente1;

    //Declaracion de variables
    int saldo=0, n=0;
    string cedula;

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
        cout<<"---------------------------------------------------------"<<endl;
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
                while (!ficheroAutenticacion.eof()) { //Mientras el fichero para autenticar la contraseña no haya llegado a su fin
                  ficheroAutenticacion >> cadena;
                }

                cout<<"INGRESE SU NOMBRE: ";
                cin>>nombreEmpleado;

                Empleado1.SetNombre(nombreEmpleado); //Se establece el nombre del empleado

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

                Empleado1.SetContrasena(password); //Se establece la contraseña que ingreso el usuario

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
                    //Registro de productos, siempre y cuando el usuario sea un empleado del cine.

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
                                return 0;
                            break;

                            default:
                                cout<<"|=======================================================|"<<endl;
                                cout<<"|=================¡Opcion Incorrecta!===================|"<<endl;
                                cout<<"|=======================================================|"<<endl;
                        }
                   }while(opcion1!=2);
                 }
         ficheroAutenticacion.close();  //Se cierra el archivo donde esta la contraseña de autenticacion
         }
        break;

         case 2:
        {
         //-----------------------------------------------------------------------------------------------------------------------------------
         //PARA LOS CLIENTES
         //-----------------------------------------------------------------------------------------------------------------------------------

            int  opcion2;

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

        do{

            switch (opcion2) {

                case 1:
                {
                cout<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<"|....INGRESE EL NUMERO DE SALA DONDE DESEA UBICARSE.....|"<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<"|1. SALA A..............................................|"<<endl;
                cout<<"|2. SALA B..............................................|"<<endl;
                cout<<"|3. SALA C..............................................|"<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<"|....................INGRESE LA SALA....................|"<<endl;
                cout<<"|.......................................................|"<<endl;
                cout<<endl;

                int OpcSala;

                cout<<"INGRESE UNA OPCION: "<<endl;

                cin>>OpcSala;

                cout<<"---------------------------------------------------------"<<endl;
                cout<<endl;

                string OpcionAsiento;

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
                        cout<<"*********************************************************"<<endl;
                        cout<<endl;

                        cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"CEDULA"<<setw(7)<<setprecision(2)<<right<<"   SALA"<<setw(7)<<setprecision(2)<<right<<"      ASIENTO"<<endl;
                        cout<<endl;

                        ifstream lectura("Sala de Cine 1.txt"); //Apertura del archivo en modo lectura
                        if(lectura.is_open()){//si archivo esta abierto
                            while (getline(lectura, linea)){ //leer lineas del archivo

                                cout << linea <<endl;
                                cout<<endl;
                                cout<<"---------------------------------------------------------"<<endl;
                                cout<<endl;
                            }
                        }
                        lectura.close(); //cerrar fichero

                        cout<<"---------------------------------------------------------"<<endl;
                        cout<<"-------INGRESE EL NUMERO DEL ASIENTO QUE DESEA OCUPAR:---"<<endl;
                        cout<<"---------ESTE NUMERO NO PUEDE ECCEDER EL LIMITE----------"<<endl;
                        cout<<"-------------QUE ES DE 14 PERSONAS POR SALA--------------"<<endl;
                        cout<<"---------------------------------------------------------"<<endl;
                        cout<<endl;
                        cin>>OpcionAsiento;
                        Cliente1.setAsiento(OpcionAsiento);
                        cout<<endl;
                        cout<<"*********************************************************"<<endl;
                        cout<<endl;

                        //Se transforma el string a entero para hacer el condicional
                        if(atoi(Cliente1.getAsiento().c_str())<=0 ||atoi(Cliente1.getAsiento().c_str())>=15){
                            cout<<"------------INGRESE OTRO ASIENTO POR FAVOR----------------"<<endl;
                            break;
                        }

                        cout<<endl;


                        escritura.open("Sala de Cine 1.txt",ios::out|ios::app); //Se abre el archivo en modo escritura
                        consulta.open("Sala de Cine 1.txt",ios::in); //Se abre el archivo en modo lectura

                         if(escritura.is_open() && consulta.is_open()){ //Mientras ambos archivos esten abiertos

                             consulta>>linea>>linea2>>linea3>>linea4; //Se lee los parametros que estan en el fichero

                             while(!consulta.eof()){ //Mientras el archivo no llegue a su fin
                                 if(linea4==Cliente1.getAsiento()){ //Si se encuentra el asiento
                                     cout<<endl;
                                     cout<<"|-------------------------------------------------------|"<<endl;
                                     cout<<"|-----------------Este asiento esta ocupado-------------|"<<endl;
                                     cout<<"|-------------------------------------------------------|"<<endl;
                                     cout<<endl;
                                     repetido=true; //asiento repetido
                                     break;
                                 }

                             consulta>>linea>>linea2>>linea3>>linea4; //lectura

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

                                 Cliente1.MenuCompradeCombos(); //Funcion para las compras en el cine
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

                        cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"CEDULA"<<setw(7)<<setprecision(2)<<right<<"   SALA"<<setw(7)<<setprecision(2)<<right<<"      ASIENTO"<<endl;
                        cout<<endl;
                        cout<<"*********************************************************"<<endl;
                        cout<<endl;

                        ifstream lectura("Sala de Cine 2.txt"); //Apertura del archivo en modo lectura
                        if(lectura.is_open()){ //Si archivo esta abierto
                            while (getline(lectura, linea)){ //Se leen las lineas del fichero

                                cout << linea <<endl;
                                cout<<endl;
                                cout<<"---------------------------------------------------------"<<endl;
                                cout<<endl;
                            }
                        }
                        lectura.close(); //cerrar fichero

                        cout<<"---------------------------------------------------------"<<endl;
                        cout<<"-------INGRESE EL NUMERO DEL ASIENTO QUE DESEA OCUPAR:---"<<endl;
                        cout<<"---------ESTE NUMERO NO PUEDE ECCEDER EL LIMITE----------"<<endl;
                        cout<<"-------------QUE ES DE 14 PERSONAS POR SALA--------------"<<endl;
                        cout<<"---------------------------------------------------------"<<endl;
                        cout<<endl;
                        cin>>OpcionAsiento;
                        Cliente1.setAsiento(OpcionAsiento);
                        cout<<endl;
                        cout<<"*********************************************************"<<endl;
                        cout<<endl;

                        //Se transforma el string a entero para hacer el condicional
                        if(atoi(Cliente1.getAsiento().c_str())<=0 ||atoi(Cliente1.getAsiento().c_str())>=15){
                            cout<<"------------INGRESE OTRO ASIENTO POR FAVOR----------------"<<endl;
                            break;
                        }

                        cout<<endl;

                        escritura.open("Sala de Cine 2.txt",ios::out|ios::app); //Se abre el archivo en modo escritura
                        consulta.open("Sala de Cine 2.txt",ios::in); //Se abre el archivo en modo lectura

                         if(escritura.is_open() && consulta.is_open()){ //Mientras ambos archivos esten abiertos

                             consulta>>linea>>linea2>>linea3>>linea4; //Se lee los parametros que estan en el fichero

                             while(!consulta.eof()){ //Mientras el archivo no llegue a su fin
                                 if(linea4==Cliente1.getAsiento()){ //si se encuentra el asiento
                                     cout<<endl;
                                     cout<<"|-------------------------------------------------------|"<<endl;
                                     cout<<"|-----------------Este asiento esta ocupado-------------|"<<endl;
                                     cout<<"|-------------------------------------------------------|"<<endl;
                                     cout<<endl;
                                     repetido=true; //asiento repetido
                                     break;
                                 }

                             consulta>>linea>>linea2>>linea3>>linea4;

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

                                 Cliente1.MenuCompradeCombos(); //Funcion para las compras en el cine
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

                    cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"CEDULA"<<setw(7)<<setprecision(2)<<right<<"   SALA"<<setw(7)<<setprecision(2)<<right<<"      ASIENTO"<<endl;
                    cout<<endl;
                    cout<<"*********************************************************"<<endl;
                    cout<<endl;

                    ifstream lectura("Sala de Cine 3.txt"); //Apertura del archivo en modo lectura
                    if(lectura.is_open()){ //Si archivo esta abierto
                        while (getline(lectura, linea)){//Se leen las lineas del fichero

                            cout << linea <<endl;
                            cout<<endl;
                            cout<<"--------------------------------------------------------"<<endl;
                            cout<<endl;
                        }
                    }
                    lectura.close(); //Se cierra el fichero

                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<"-------INGRESE EL NUMERO DEL ASIENTO QUE DESEA OCUPAR:---"<<endl;
                    cout<<"---------ESTE NUMERO NO PUEDE ECCEDER EL LIMITE----------"<<endl;
                    cout<<"-------------QUE ES DE 14 PERSONAS POR SALA--------------"<<endl;
                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<endl;
                    cin>>OpcionAsiento;
                    Cliente1.setAsiento(OpcionAsiento);
                    cout<<endl;
                    cout<<"*********************************************************"<<endl;
                    cout<<endl;

                    //Se transforma el string a entero para hacer el condicional
                    if(atoi(Cliente1.getAsiento().c_str())<=0 ||atoi(Cliente1.getAsiento().c_str())>=15){
                        cout<<"------------INGRESE OTRO ASIENTO POR FAVOR----------------"<<endl;
                        break;
                    }

                    cout<<endl;

                    escritura.open("Sala de Cine 3.txt",ios::out|ios::app); //Se abre el archivo en modo escritura
                    consulta.open("Sala de Cine 3.txt",ios::in); //Se abre el archivo en modo lectura

                     if(escritura.is_open() && consulta.is_open()){ //Mientras ambos archivos esten abiertos

                         consulta>>linea>>linea2>>linea3>>linea4; //Se lee los parametros que estan en el fichero

                         while(!consulta.eof()){ //Mientras el archivo no llegue a su fin
                             if(linea4==Cliente1.getAsiento()){ //Si se encuentra el asiento
                                 cout<<endl;
                                 cout<<"|-------------------------------------------------------|"<<endl;
                                 cout<<"|-----------------Este asiento esta ocupado-------------|"<<endl;
                                 cout<<"|-------------------------------------------------------|"<<endl;
                                 cout<<endl;
                                 repetido=true; //Asiento repetido
                                 break;
                             }

                         consulta>>linea>>linea2>>linea3>>linea4; //lectura

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

                             Cliente1.MenuCompradeCombos(); //Funcion para las compras en el cine
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
          }while(opcion2>0|| opcion2<4);

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


