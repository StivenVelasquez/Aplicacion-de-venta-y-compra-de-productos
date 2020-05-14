#include "cliente.h"
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <cstdio>
#include <cstdlib>

using namespace std;

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

void Cliente::setAsiento(string value)
{
    Asiento=value;
}

string Cliente::getNombreCliente() const
{
    return NombreCliente;
}

string Cliente::getCedula() const
{
    return Cedula;
}

string Cliente::getAsiento() const
{
    return  Asiento;
}

int Cliente::ComprarCombo()
{

    //Declaracion de variables
    ofstream aux;
    ifstream lectura;
    string ID, IDaux, linea,Texto="ID: ", leyendo, leyendo2,leyend, leyen;
    int opcion=0;
    list<string> listaC; //Lista de string
    ofstream auxiliar;

    do{

        cout<<endl;
        cout<<endl;
        cout<<"======================================================="<<endl;
        cout<<"*****INGRESE EL ID DEL COMBO QUE DESEA COMPRAR*********"<<endl;
        cout<<"======================================================="<<endl;
        cout<<endl;
        cin>>IDaux;

        ifstream leer("Combos.txt"); //Apertura del archivo en modo lectura del archivo donde estan registrados los combos
        string Texto="ID: ", leyendo, leyendo2,leyend, leyen;

        auxiliar.open("auxiliarC.txt",ios::out);//Se crea un fichero auxiliar para meter el combo que se elije

        HayONoHayIngredientesParaCombo(); //Funcion para saber si hay o no ingredientes para vender el combo


        if(leer.is_open() && auxiliar.is_open()){ //Lectura de los combos para capturar solo la parte del combo que se elije
                                                  //y se va agregando cada linea a una lista
                        while (getline(leer, linea, '*'))
                        {
                            if(linea.find(Texto+IDaux) != string::npos){
                                listaC.push_back(linea); //Se van agragando las lineas del archivo a la lista
                                cout << linea << endl;
                                auxiliar<<left<<setw(10)<<linea<<endl; //Se va guardando la informacion
                                listaC.pop_back(); //se elimina el ultimo elemento
                            }

                        }
         }
          auxiliar.close(); //Se cierra archivo
          leer.close(); //Se cierra el archivo
         // remove("auxiliarC.txt"); //Se remueve el fichero


          cout<<"----------ESTA SEGURO QUE DE HACER ESTA COMPRA?--------"<<endl;
          cout<<endl;

          //Se imprime el combo que eligio el usuario
          while( listaC.size()!=0 ) //mientras la lista no este vacia
          {
            linea = listaC.front();//Para ir eliminando elementos de la lista
            cout << linea << endl;
            listaC.pop_front(); //Elimina el primer elemento
          }

            cout<<"|.......................................................|"<<endl;
            cout<<"|1. Realizar la compra..................................|"<<endl;
            cout<<"|3. Volver al menu de compra de combos..................|"<<endl;
            cout<<"|.......................................................|"<<endl;
            cout<<"|....................QUE DESEA HACER?...................|"<<endl;
            cout<<"|.......................................................|"<<endl;
            cout<<endl;

            cin>>opcion;
            cout<<endl;

            int CantidadDinero; //  Variable que representa la cantidad de dinero con el que el usuario pagara el combo

            switch (opcion) {

                case 1:
                {
                 ofstream escritura;
                 ifstream leer("ListaPreciosCombos.txt"); //Apertura del archivo en modo lectura
                 escritura.open("ventas.txt",ios::out|ios::app);
                 int precio,division,restando, Devuelta, Dinero=0;
                 string ID;

                  if(leer.is_open() && escritura.is_open() ){ //Mientras el archivo este abierto
                      cout<<endl;
                      cout<<endl;

                      leer>>ID; //Se leen los IDs del archivo ListaPreciosCombo.txt

                      while(!leer.eof()){
                          leer>>precio;
                          if(ID==IDaux){ //Si encuentra el ID en el archivo
                          cout<<endl;
                          cout<<"________________________________________________________"<<endl;
                          cout<<endl;
                          cout<<endl;
                          cout<<endl;
                          cout<<"======================================================="<<endl;
                          cout<<"***EL PRECIO DEL COMBO QUE ELIGIO ES DE "<<precio<<"$**"<<endl;
                          cout<<"======================================================="<<endl;
                          cout<<endl;
                          cout<<endl;

                          escritura<<left<<setw(10)<<IDaux<<setw(13)<<precio<<endl;

                          cout<<"INGRESE LA CANTIDAD DE DINERO CON EL QUE DESEA PAGAR SU PEDIDO"<<endl;
                          cin>>CantidadDinero;
                          cout<<"--------------------------------------------------------------"<<endl;
                          cout<<endl;
                          cout<<endl;

                          Devuelta=CantidadDinero-precio;

                          cout<<"A CONTINUACIÓN SE MUESTRA SU DEVUELTA: "<<endl;
                          cout<<"--------------------------------------------------------------"<<endl;
                          cout<<endl;

                     /*     //Para ir registrando las ventas
                                     ofstream escritura;
                                      string ID;
                                      int Dinero=0;

                                      escritura.open("ventas.txt",ios::out|ios::app);

                                       if(escritura.is_open()){

                                           while(!escritura.eof()){

                                               escritura<<ID<<Dinero<<endl;
                                               //Se pasa a imprimir los datos en el fichero de una manera organizada
                                               escritura<<left<<setw(10)<<IDaux<<setw(13)<<precio<<endl;
                                               cout<<endl;
                                           }
                                         break;
                                       }
                                        escritura.close();*/

                          int cantidades[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};//lista donde se guardan las cantidades dadas
                          for(int i=0;i<=10;i++){//recorre la lista cantidades
                              division=Devuelta/cantidades[i];//divide el dinero por cada valor en cantidades
                              if(division==0){
                                  cout<<cantidades[i]<<" : "<<division<<endl;
                                  if(cantidades[i]==50){
                                      cout<<endl;

                                      DescontarIngredienteCombo();
                                     remove("auxiliarC.txt"); //Se remueve el fichero
                                     cout<<endl;
                                     cout<<"|.......................................................|"<<endl;
                                     cout<<"|.SELECCIONE LA SALA DONDE SE ENCUENTRA PARA LLEVARLE EL|"<<endl;
                                     cout<<"|................PEDIDO QUE ACABO DE HACER..............|"<<endl;
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
                                            string linea;

                                            cout<<"A CONTINUACION SE MUESTRAN LOS ASIENTOS OCUPADOS"<<endl;
                                            cout<<endl;

                                            ifstream lectura("Sala de Cine 1.txt"); //Apertura del archivo en modo lectura
                                            if(lectura.is_open()){
                                                while (getline(lectura, linea)){

                                                    cout <<"Asiento: "<< linea <<" esta ocupado"<<endl;

                                                }
                                            }
                                            lectura.close();

                                            cout<<"INGRESE EL NUMERO DE SU ASIENTO: ";
                                            cin>>OpcionAsiento;
                                            cout<<endl;

                                            escritura.open("Sala de Cine 1.txt",ios::out|ios::app);
                                            consulta.open("Sala de Cine 1.txt",ios::in);

                                             if(escritura.is_open() && consulta.is_open()){

                                                 consulta>>linea;

                                                 while(!consulta.eof()){
                                                     if(linea==OpcionAsiento){
                                                         cout<<"|-------------------------------------------------------|"<<endl;
                                                         cout<<"|-----Este asiento esta ocupado, ingrese otra opcion----|"<<endl;
                                                         cout<<"|-------------------------------------------------------|"<<endl;
                                                         cout<<endl;
                                                         repetido=true;
                                                         break;
                                                     }

                                                 consulta>>linea;

                                                 }

                                                 if(repetido==false){


                                                     //Se pasa a imprimir los datos en el fichero de una manera organizada
                                                     escritura<<left<<setw(10)<<OpcionAsiento<<endl;
                                                     cout<<endl;

                                                     cout<<"|=======================================================|"<<endl;
                                                     cout<<"|==================Asiento ocupado======================|"<<endl;
                                                     cout<<"|=======================================================|"<<endl;

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
                                        string linea;

                                        cout<<"A CONTINUACION SE MUESTRAN LOS ASIENTOS OCUPADOS"<<endl;
                                        cout<<endl;

                                        ifstream lectura("Sala de Cine 2.txt"); //Apertura del archivo en modo lectura
                                        if(lectura.is_open()){
                                            while (getline(lectura, linea)){

                                                cout <<"Asiento: "<< linea <<" esta ocupado"<<endl;

                                            }
                                        }
                                        lectura.close();

                                        cout<<"INGRESE EL NUMERO DE SU ASIENTO: ";
                                        cin>>OpcionAsiento;
                                        cout<<endl;

                                        escritura.open("Sala de Cine 2.txt",ios::out|ios::app);
                                        consulta.open("Sala de Cine 2.txt",ios::in);

                                         if(escritura.is_open() && consulta.is_open()){

                                             consulta>>linea;

                                             while(!consulta.eof()){
                                                 if(linea==OpcionAsiento){
                                                     cout<<"|-------------------------------------------------------|"<<endl;
                                                     cout<<"|-----Este asiento esta ocupado, ingrese otra opcion----|"<<endl;
                                                     cout<<"|-------------------------------------------------------|"<<endl;
                                                     cout<<endl;
                                                     repetido=true;
                                                     break;
                                                 }

                                             consulta>>linea;

                                             }

                                             if(repetido==false){


                                                 //Se pasa a imprimir los datos en el fichero de una manera organizada
                                                 escritura<<left<<setw(10)<<OpcionAsiento<<endl;
                                                 cout<<endl;

                                                 cout<<"|=======================================================|"<<endl;
                                                 cout<<"|==================Asiento ocupado======================|"<<endl;
                                                 cout<<"|=======================================================|"<<endl;

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
                                        string linea;

                                        cout<<"A CONTINUACION SE MUESTRAN LOS ASIENTOS OCUPADOS"<<endl;
                                        cout<<endl;

                                        ifstream lectura("Sala de Cine 3.txt"); //Apertura del archivo en modo lectura
                                        if(lectura.is_open()){
                                            while (getline(lectura, linea)){

                                                cout <<"Asiento: "<< linea <<" esta ocupado"<<endl;

                                            }
                                        }
                                        lectura.close();

                                        cout<<"INGRESE EL NUMERO DE SU ASIENTO: ";
                                        cin>>OpcionAsiento;
                                        cout<<endl;

                                        escritura.open("Sala de Cine 3.txt",ios::out|ios::app);
                                        consulta.open("Sala de Cine 3.txt",ios::in);

                                         if(escritura.is_open() && consulta.is_open()){

                                             consulta>>linea;

                                             while(!consulta.eof()){
                                                 if(linea==OpcionAsiento){
                                                     cout<<"|-------------------------------------------------------|"<<endl;
                                                     cout<<"|-----Este asiento esta ocupado, ingrese otra opcion----|"<<endl;
                                                     cout<<"|-------------------------------------------------------|"<<endl;
                                                     cout<<endl;
                                                     repetido=true;
                                                     break;
                                                 }

                                             consulta>>linea;

                                             }

                                             if(repetido==false){


                                                 //Se pasa a imprimir los datos en el fichero de una manera organizada
                                                 escritura<<left<<setw(10)<<OpcionAsiento<<endl;
                                                 cout<<endl;

                                                 cout<<"|=======================================================|"<<endl;
                                                 cout<<"|==================Asiento ocupado======================|"<<endl;
                                                 cout<<"|=======================================================|"<<endl;

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

                                     cout<<endl;
                                     cout<<"--------------MUCHAS GRACIAS POR SU COMPRA--------------"<<endl;
                                     cout<<endl;
                                     cout<<"--------------------------------------------------------"<<endl;
                                     return EXIT_SUCCESS;
                                     break;


                                  }
                              //    auxiliar.close();
                               //   remove("auxiliar.txt");
                              }

                              else {
                                  restando=division*cantidades[i];
                                  Devuelta=Devuelta-restando;//actualiza el dinero
                                  cout<<cantidades[i]<<" : "<<division<<endl;

                              }

                          }

                          return 0;

                          }

                     leer>>ID;
                      }
                  }
                 leer.close(); //Se cierra el fichero
                 escritura.close();
                 }
                break;

                case 2:
                    break;

                }

    }while(true);
}

void Cliente::DescontarIngredienteCombo()
{
    map<string,string> nombres;
    ifstream leyendo;// leyendo2;
    ofstream escribiendo;
    leer_datos("auxiliarC.txt",nombres);
    string a="PERROS",b="HAMBURGUESAS",c="GASEOSAS", d="NACHOS",Producto;
    int g=atoi(nombres[a].c_str()),h=atoi(nombres[b].c_str()),i=atoi(nombres[c].c_str()),j=atoi(nombres[d].c_str());
    int Cantidad=0, CostoTotal=0, CostoProducto=0, CantidadModificada=0,CostoTotalModificado=0, contIng=3;
    bool encontrado=false;

    string leer;
    string Ingred="2";

    //Para Perros
    //***********************************************************************************************************

    while(g>0){

        while(contIng>0){

            leyendo.open("ListaProductos.txt",ios::in);
            escribiendo.open("auxiliando.txt",ios::out);

            if(leyendo.is_open() && escribiendo.is_open()){
                leyendo>>leer;

                while(!leyendo.eof()){
                   leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
                   if(leer==Ingred){
                      encontrado=true;
                      CantidadModificada=Cantidad-1;
                      CostoTotalModificado=CostoTotal-(CostoProducto);
                       escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotalModificado<<endl;

                       Cantidad=CantidadModificada;
                       CostoTotal=CostoTotalModificado;
                    }

                   else{
                         escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;
                   }

                  leyendo>>leer;
                }
                leyendo.close();
                escribiendo.close();
                remove("ListaProductos.txt");
                rename("auxiliando.txt","ListaProductos.txt");
            }
        contIng--;
        if(contIng==2)
            Ingred="3";

        else if(contIng==1)
            Ingred="5";

  }

    g--;
    if(g==0)
        break;
    contIng=3;
    Ingred="2";
  }

   //Para hamburguesa
    //****************************************************************************************************
    contIng=3;
    Ingred="4";

    while(h>=0){

        while(contIng>=0){

            leyendo.open("ListaProductos.txt",ios::in);
            escribiendo.open("auxiliando.txt",ios::out);

            if(leyendo.is_open() && escribiendo.is_open()){
                leyendo>>leer;

                while(!leyendo.eof()){
                   leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
                   if(leer==Ingred){
                      encontrado=true;
                      CantidadModificada=Cantidad-1;
                      CostoTotalModificado=CostoTotal-(CostoProducto);
                       escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotalModificado<<endl;

                       Cantidad=CantidadModificada;
                       CostoTotal=CostoTotalModificado;
                   }

                   else{
                         escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;
                   }

                   leyendo>>leer;
                }
                leyendo.close();
                escribiendo.close();
                remove("ListaProductos.txt");
                rename("auxiliando.txt","ListaProductos.txt");
             }


    contIng--;
    if(contIng==2)
        Ingred="5";

    if(contIng==1)
        Ingred="7";

        }

        h--;
        if(h==0)
            break;
        contIng=3;
        Ingred="4";
  }

    //Para gaseosas
    //*************************************************************************************************
    contIng=2;
    Ingred="1";

    while(i>=0){

        while(contIng>=0){

            leyendo.open("ListaProductos.txt",ios::in);
            escribiendo.open("auxiliando.txt",ios::out);

            if(leyendo.is_open() && escribiendo.is_open()){
                leyendo>>leer;

                while(!leyendo.eof()){
                   leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
                   if(leer==Ingred){
                      encontrado=true;
                      CantidadModificada=Cantidad-1;
                      CostoTotalModificado=CostoTotal-(CostoProducto);
                       escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotalModificado<<endl;

                       Cantidad=CantidadModificada;
                       CostoTotal=CostoTotalModificado;

                   }

                   else{
                         escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;
                   }
                   leyendo>>leer;
                }
                leyendo.close();
                escribiendo.close();
                remove("ListaProductos.txt");
                rename("auxiliando.txt","ListaProductos.txt");
            }


            contIng--;
            if(contIng==1)
                Ingred="6";

   }

        i--;
        if(i==0)
            break;
        contIng=2;
        Ingred="1";
  }

    //Para Paquete de nachos
    //********************************************************************************************************
    contIng=1;
    Ingred="8";

    while(j>=0){

        while(contIng>=0){

            leyendo.open("ListaProductos.txt",ios::in);
            escribiendo.open("auxiliando.txt",ios::out);

            if(leyendo.is_open() && escribiendo.is_open()){
                leyendo>>leer;

                while(!leyendo.eof()){
                   leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
                   if(leer==Ingred){
                      encontrado=true;
                      CantidadModificada=Cantidad-1;
                      CostoTotalModificado=CostoTotal-(CostoProducto);
                       escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotalModificado<<endl;

                       Cantidad=CantidadModificada;
                       CostoTotal=CostoTotalModificado;
                   }

                   else{
                         escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;
                   }
                   leyendo>>leer;
                }
                leyendo.close();
                escribiendo.close();
                remove("ListaProductos.txt");
                rename("auxiliando.txt","ListaProductos.txt");
            }

            contIng--;
   }

        j--;
        if(j==0)
            break;
        contIng=1;
        Ingred="8";
  }
}

void Cliente::inserta_nombre(string linea, map<string, string> & nombres)
{
    int pos=linea.find(':');
    if(pos!= -1){
        string llave=linea.substr(0,pos);
        string valor=linea.substr(pos+1);
        nombres[llave]=valor;
    }
}

void Cliente::leer_datos(string nombre_fichero, map<string, string>& nombres)
{
    string linea;
    ifstream F(nombre_fichero.c_str());
    getline(F,linea);
    while(!F.eof()){
        inserta_nombre(linea,nombres);
        getline(F,linea);
    }
}

int Cliente::HayONoHayIngredientesParaCombo()
{
    map<string,string> nombres;
    ifstream leyendo, leyendo2;
    ofstream escribiendo;
    leer_datos("auxiliarC.txt",nombres);
    string a="PERROS",b="HAMBURGUESAS",c="GASEOSAS",d="NACHOS";
    int g=atoi(nombres[a].c_str()),h=atoi(nombres[b].c_str()),i=atoi(nombres[c].c_str()),j=atoi(nombres[d].c_str());
    string Producto;
    int Cantidad=0, CostoTotal=0, CostoProducto=0, CantidadModificada=0,CostoTotalModificado=0, contIng=3;
    bool encontrado=false;

    string leer;
    string Ingred="2";

    //Para los PERROS
    //***********************************************************************************************************

        while(contIng>=0){
            int ExistenIng=0;

            leyendo.open("ListaProductos.txt",ios::in);

            if(leyendo.is_open()){
                leyendo>>leer;

                while(!leyendo.eof()){
                   leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
                   if(leer==Ingred){
                      encontrado=true;

                      if(Cantidad<g)
                      {
                          cout<<"LO SENTIMOS, PERO NO TENEMOS INGREDIENTES PARA VENDERLE ESTE COMBO"<<endl;
                          cout<<endl;
                          exit(0);
                      }



                    }

                   leyendo>>leer;
                }
                leyendo.close();
            }

        contIng--;
        if(contIng==2)
            Ingred="3";

        if(contIng==1)
            Ingred="5";
        }

    //***********************************************************************************************************
    //Para hamburguesas
    //*******************************************************************************************************
     Ingred="4";
     contIng=3;

        while(contIng>=0){

            leyendo.open("ListaProductos.txt",ios::in);

            if(leyendo.is_open()){
                leyendo>>leer;

                while(!leyendo.eof()){
                   leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
                   if(leer==Ingred){
                      encontrado=true;

                      if(Cantidad<h)
                      {
                          cout<<"LO SENTIMOS, PERO NO TENEMOS INGREDIENTES PARA VENDERLE ESTE COMBO"<<endl;
                          cout<<endl;
                           exit(0);
                      }

                    }

                   leyendo>>leer;
                }
                leyendo.close();

           }
            contIng--;
            if(contIng==2)
                Ingred="5";

            if(contIng==1)
                Ingred="7";
        }

    //Para gaseosas
    //***************************************************************************************************************
    Ingred="1";
    contIng=2;

       while(contIng>=0){

           leyendo.open("ListaProductos.txt",ios::in);

           if(leyendo.is_open()){
               leyendo>>leer;

               while(!leyendo.eof()){
                  leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
                  if(leer==Ingred){
                     encontrado=true;

                     if(Cantidad<i){
                         cout<<"LO SENTIMOS, PERO NO TENEMOS INGREDIENTES PARA VENDERLE ESTE COMBO"<<endl;
                         cout<<endl;
                          exit(0);
                     }

                   }

                  leyendo>>leer;
               }
               leyendo.close();
           }
           contIng--;

           if(contIng==1)
               Ingred="6";
       }

   //Para nachos
   //********************************************************************************************************************
   Ingred="8";
   contIng=1;

      while(contIng>=0){

          leyendo.open("ListaProductos.txt",ios::in);

          if(leyendo.is_open()){
              leyendo>>leer;

              while(!leyendo.eof()){
                 leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
                 if(leer==Ingred){
                    encontrado=true;

                    if(Cantidad<j){
                        cout<<"LO SENTIMOS, PERO NO TENEMOS INGREDIENTES PARA VENDERLE ESTE COMBO"<<endl;
                        cout<<endl;
                         exit(0);
                    }

                  }

                 leyendo>>leer;
              }
              leyendo.close();
          }
     contIng--;
      }

}


