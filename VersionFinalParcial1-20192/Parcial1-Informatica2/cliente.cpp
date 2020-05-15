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
    ofstream aux, auxiliar;
    ifstream lectura;
    string ID, IDaux, linea,Texto="ID: ", leyendo, leyendo2,leyend, leyen;
    int opcion=0;
    list<string> listaC; //Lista de string para guardar lineas de fichero

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

        cout<<endl;
        cout<<"ESTE ES EL COMBO QUE USTED DESEA COMPRAR"<<endl;
        cout<<endl;
        cout<<"=============================================="<<endl;
        cout<<endl;

        if(leer.is_open() && auxiliar.is_open()){ //Lectura de los combos para capturar solo la parte del combo que se elije
                                                  //y se va agregando cada linea a una lista
                        while (getline(leer, linea, '*')) //Se leen las lineas del archivo
                        {
                            if(linea.find(Texto+IDaux) != string::npos){ // Se busca la subcadena en el archivo para obtener
                                                                         //el combo que nos interesa
                                listaC.push_back(linea); //Se van agragando las lineas del archivo a la lista
                                cout << linea << endl;
                                auxiliar<<left<<setw(10)<<linea<<endl; //Se va guardando la informacion en el archivo
                                listaC.pop_back(); //se elimina el ultimo elemento para reducir tamanio de la lista
                            }

                        }
                        cout<<endl<<endl;
         }
          auxiliar.close(); //Se cierra archivo
          leer.close(); //Se cierra el archivo

          cout<<"----------ESTA SEGURO QUE DE HACER ESTA COMPRA?--------"<<endl;
          cout<<endl;

          //Se imprime el combo que eligio el usuario
          while( listaC.size()!=0 ) //mientras la lista no este vacia
          {
            linea = listaC.front();//Referencia al primer elemento de la lista
            cout << linea << endl;
            listaC.pop_front(); //Elimina el primer elemento para reducir tamanio de la lista
          }

            cout<<"|.......................................................|"<<endl;
            cout<<"|1. Realizar la compra..................................|"<<endl;
            cout<<"|3. Volver al menu de compra de combos..................|"<<endl;
            cout<<"|.......................................................|"<<endl;
            cout<<"|....................QUE DESEA HACER?...................|"<<endl;
            cout<<"|.......................................................|"<<endl;
            cin>>opcion;

            int CantidadDinero; //  Variable que representa la cantidad de dinero con el que el usuario pagara el combo

            switch (opcion) {

                case 1:
                {

                 ofstream escritura;
                 ifstream leer("ListaPreciosCombos.txt"); //Apertura del archivo en modo lectura
                 escritura.open("ventas.txt",ios::out|ios::app); //Apertura del archivo en modo escritura
                 int precio,division,restando, Devuelta, Dinero=0;
                 string ID;

                  if(leer.is_open() && escritura.is_open() ){ //Mientras el archivo este abierto

                      leer>>ID; //Se leen los IDs del archivo ListaPreciosCombo.txt

                      while(!leer.eof()){ //Mientras fichero no halla llegado al fin
                          leer>>precio; //lectura
                          if(ID==IDaux){ //Si encuentra el ID en el archivo
                          cout<<endl;
                          cout<<"________________________________________________________"<<endl;
                          cout<<endl;
                          cout<<endl;
                          cout<<"======================================================="<<endl;
                          cout<<"***EL PRECIO DEL COMBO QUE ELIGIO ES DE "<<precio<<"$**"<<endl;
                          cout<<"======================================================="<<endl;
                          cout<<endl;
                          cout<<endl;

                          //Se registran las ventas en ventas.txt
                          escritura<<left<<setw(10)<<IDaux<<setw(20)<<setw(7)<<setprecision(2)<<right<<precio<<endl; //Para registrar las ventas

                          cout<<"INGRESE LA CANTIDAD DE DINERO CON EL QUE DESEA PAGAR SU PEDIDO"<<endl;
                          cin>>CantidadDinero;
                          cout<<"--------------------------------------------------------------"<<endl;
                          cout<<endl;
                          cout<<endl;

                          Devuelta=CantidadDinero-precio;

                          cout<<"SU DEVUELTA ES DE "<<Devuelta<<"$"<<endl;
                          cout<<endl;

                          cout<<"A CONTINUACION SE MUESTRA SU DEVUELTA: "<<endl;
                          cout<<"--------------------------------------------------------------"<<endl;
                          cout<<endl;

                          int cantidades[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};//arreglo con las denoninaciones de billetes
                                                                                               //y monedas
                          for(int i=0;i<=10;i++){//recorre el arreglo
                              division=Devuelta/cantidades[i];//divide el dinero por cada valor
                              if(division==0){
                                  cout<<cantidades[i]<<" : "<<division<<endl;
                                  if(cantidades[i]==50){
                                     cout<<endl;

                                     DescontarIngredienteCombo(); //Para descontar ingredientes de ListaProductos.txt
                                     remove("auxiliarC.txt"); //Se remueve el fichero donde esta el combo que el cliente compro
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
                                     cout<<endl;

                                    int OpcSala;

                                    cout<<"INGRESE UNA OPCION"<<endl;

                                    cin>>OpcSala;

                                    cout<<"---------------------------------------------------------"<<endl;

                                    string OpcionAsiento;

                                    switch (OpcSala){

                                        case 1:
                                        {
                                            cout<<endl;
                                            //Declaracion de variables
                                            ofstream escritura;
                                            ifstream consulta;
                                            bool encontrado=false;
                                            string linea, linea2, linea3, linea4;

                                            cout<<"INGRESE EL NUMERO DE SU ASIENTO: ";
                                            cin>>OpcionAsiento;
                                            cout<<endl;

                                            consulta.open("Sala de Cine 1.txt",ios::in);

                                             if(consulta.is_open()){ //Si el fichero esta abierto

                                                 consulta>>linea>>linea2>>linea3>>linea4; //lectura

                                                 while(!consulta.eof()){ //Mientras no halla llegado al final
                                                     if(linea4==OpcionAsiento){ //Si encontro el asiento

                                                         encontrado=true; //Se encontro el asiento
                                                         cout<<endl;
                                                         cout<<"________________________________________________________"<<endl;
                                                         cout<<"Nombre: "<<linea<<endl;
                                                         cout<<"Cedula: "<<linea2<<endl;
                                                         cout<<"Sala: "<<linea3<<endl;
                                                         cout<<"Asiento: "<<linea4<<endl;
                                                         cout<<"________________________________________________________"<<endl;
                                                         cout<<endl;

                                                     }



                                                    consulta>>linea>>linea2>>linea3>>linea4; //lectura
                                                 }


                                                 if(encontrado==false){ //Si no se encuentra el asiento


                                                     //Se pasa a imprimir los datos en el fichero de una manera organizada
                                                     escritura<<left<<setw(10)<<OpcionAsiento<<endl;
                                                     cout<<endl;

                                                     cout<<"|=======================================================|"<<endl;
                                                     cout<<"|==================Registro no encontrado===============|"<<endl;
                                                     cout<<"|=======================================================|"<<endl;

                                                     cout<<endl;
                                                 }


                                             }

                                             else{
                                                 cout<<"-Error, el Archivo No se Pudo Abrir o No ha sido Creado-"<<endl;
                                                 cout<<endl;
                                             }

                                            //Cerrando los archivos
                                             consulta.close();

                                        }
                                        break;

                                    case 2:
                                    {
                                        cout<<endl;
                                        //Declaracion de variables
                                        ofstream escritura;
                                        ifstream consulta;
                                        bool encontrado=false;
                                        string linea, linea2, linea3, linea4;

                                        cout<<"INGRESE EL NUMERO DE SU ASIENTO: ";
                                        cin>>OpcionAsiento;
                                        cout<<endl;

                                        consulta.open("Sala de Cine 2.txt",ios::in); //Se abre archivo en modo lectura

                                         if(consulta.is_open()){ //Si el fichero esta abierto

                                             consulta>>linea>>linea2>>linea3>>linea4; //lectura

                                             while(!consulta.eof()){ //mientras el fichero no halla llegado al final
                                                 if(linea4==OpcionAsiento){

                                                     encontrado=true; //Si se encuentra el asiento
                                                     cout<<endl;
                                                     cout<<"________________________________________________________"<<endl;
                                                     cout<<"Nombre: "<<linea<<endl;
                                                     cout<<"Cedula: "<<linea2<<endl;
                                                     cout<<"Sala: "<<linea3<<endl;
                                                     cout<<"Asiento: "<<linea4<<endl;
                                                     cout<<"________________________________________________________"<<endl;
                                                     cout<<endl;

                                                 }

                                                consulta>>linea>>linea2>>linea3>>linea4; //lectura
                                             }

                                             if(encontrado==false){ //Si no se encuentra el asiento

                                                 //Se pasa a imprimir los datos en el fichero de una manera organizada
                                                 escritura<<left<<setw(10)<<OpcionAsiento<<endl;
                                                 cout<<endl;

                                                 cout<<"|=======================================================|"<<endl;
                                                 cout<<"|==================Registro no encontrado===============|"<<endl;
                                                 cout<<"|=======================================================|"<<endl;

                                                 cout<<endl;
                                             }


                                         }

                                         else{
                                             cout<<"-Error, el Archivo No se Pudo Abrir o No ha sido Creado-"<<endl;
                                             cout<<endl;
                                         }

                                        //Cerrando los archivos
                                         consulta.close();
                                    }


                                    case 3:
                                    {
                                        cout<<endl;
                                        //Declaracion de variables
                                        ofstream escritura;
                                        ifstream consulta;
                                        bool encontrado=false;
                                        string linea, linea2, linea3, linea4;

                                        cout<<"INGRESE EL NUMERO DE SU ASIENTO: ";
                                        cin>>OpcionAsiento;
                                        cout<<endl;

                                        consulta.open("Sala de Cine 3.txt",ios::in);

                                         if(consulta.is_open()){ //Si el fichero esta abierto

                                             consulta>>linea>>linea2>>linea3>>linea4; //lectura

                                             while(!consulta.eof()){  //Si no ha llegado al final del fichero
                                                 if(linea4==OpcionAsiento){

                                                     encontrado=true;
                                                     cout<<endl;
                                                     cout<<"________________________________________________________"<<endl;
                                                     cout<<"Nombre: "<<linea<<endl;
                                                     cout<<"Cedula: "<<linea2<<endl;
                                                     cout<<"Sala: "<<linea3<<endl;
                                                     cout<<"Asiento: "<<linea4<<endl;
                                                     cout<<"________________________________________________________"<<endl;
                                                     cout<<endl;

                                                 }



                                                consulta>>linea>>linea2>>linea3>>linea4; //lectura
                                             }


                                             if(encontrado==false){


                                                 //Se pasa a imprimir los datos en el fichero de una manera organizada
                                                 escritura<<left<<setw(10)<<OpcionAsiento<<endl;
                                                 cout<<endl;

                                                 cout<<"|=======================================================|"<<endl;
                                                 cout<<"|==================Registro no encontrado===============|"<<endl;
                                                 cout<<"|=======================================================|"<<endl;

                                                 cout<<endl;
                                             }


                                         }

                                         else{
                                             cout<<"-Error, el Archivo No se Pudo Abrir o No ha sido Creado-"<<endl;
                                             cout<<endl;
                                         }

                                        //Cerrando los archivos
                                         consulta.close();
                                    }

                                    default:
                                        break;
                               }



                             cout<<endl;
                             cout<<"--------------MUCHAS GRACIAS POR SU COMPRA--------------"<<endl;
                             cout<<endl;
                             cout<<"--------------------------------------------------------"<<endl;
                             break;

                                  }
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
    //Declaracion
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

    while(g>0){ //Mientras el numero de PERROS  que pidio el usuario sea mayor que 0

        while(contIng>0){ //Mientras el numero de ingredientes que tiene el PERRO sea mayor a 0

            leyendo.open("ListaProductos.txt",ios::in); //archivo en modo lectura
            escribiendo.open("auxiliando.txt",ios::out); //archivo en modo escritura

            if(leyendo.is_open() && escribiendo.is_open()){ //Mientras ambos archivos esten abiertos
                leyendo>>leer;

                while(!leyendo.eof()){ //Mientras ListaProductos.txt no halla llegado a su fin
                   leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal; //lectura
                   if(leer==Ingred){ //Si se encuentra el Id del ingrediente
                      encontrado=true; //Se encontro el ingrediente

                      CantidadModificada=Cantidad-1; //Se le resta una unidad a ese ingrediente

                      //Para no guardar resultados negativos en el fichero
                      if(CantidadModificada<=0){
                          CantidadModificada=0;
                      }

                      CostoTotalModificado=CostoTotal-(CostoProducto); //Se le resta el costo del producto al costo total

                      //Para no guardar resultados negativos en el fichero
                      if(CostoTotalModificado<=0){
                          CostoTotalModificado=0;
                      }
                      //Se guarda la informacion en el fichero auxiliar
                       escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotalModificado<<endl;

                       //Se actualizan los resultados
                       Cantidad=CantidadModificada;
                       CostoTotal=CostoTotalModificado;
                    }

                   else{
                       //Se guarda la informacion en el fichero auxiliar
                         escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;
                   }

                  leyendo>>leer; //lectura
                }
                //Se cierran los ficheros
                leyendo.close();
                escribiendo.close();

                remove("ListaProductos.txt"); //Se remueve el fichero que contiene la lista de productos
                rename("auxiliando.txt","ListaProductos.txt"); //Se cambia el nombre del fichero auxiliar por ListaProductos.txt
            }

        contIng--; //Se resta una unidad al numero de ingredientes del PERRO

        if(contIng==2)
            Ingred="3"; //Se pasa a otro producto en ListaProductos.txt

        else if(contIng==1)
            Ingred="5";//Se pasa a otro producto en ListaProductos.txt

  }

    g--; //Se resta una unidad al numero de PERROS que pidio el usuario

    if(g==0) //Si ya no hay mas PERROS se finaliza
        break;

    //Se actualiza la cantidad de ingredientes del PERRO y el ID del ingrediente inicial
    contIng=3;
    Ingred="2";
  }

   //Para hamburguesa
    //****************************************************************************************************
    contIng=3;
    Ingred="4";

    while(h>0){ //Mientras el numero de HAMBURGUESAS que pidio el usuario sea mayor que 0

           while(contIng>0){ //Mientras el numero de ingredientes que tiene la HAMBURGUESA sea mayor a 0

               leyendo.open("ListaProductos.txt",ios::in); //archivo en modo lectura
               escribiendo.open("auxiliando.txt",ios::out); //archivo en modo escritura

               if(leyendo.is_open() && escribiendo.is_open()){ //Mientras ambos archivos esten abiertos
                   leyendo>>leer;

                   while(!leyendo.eof()){ //Mientras ListaProductos.txt no halla llegado a su fin
                      leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal; //lectura
                      if(leer==Ingred){ //Si se encuentra el Id del ingrediente
                         encontrado=true; //Se encontro el ingrediente

                         CantidadModificada=Cantidad-1; //Se le resta una unidad a ese ingrediente

                         //Para no guardar resultados negativos en el fichero
                         if(CantidadModificada<=0){
                             CantidadModificada=0;
                         }

                         CostoTotalModificado=CostoTotal-(CostoProducto); //Se le resta el costo del producto al costo total

                         //Para no guardar resultados negativos en el fichero
                         if(CostoTotalModificado<=0){
                             CostoTotalModificado=0;
                         }
                         //Se guarda la informacion en el fichero auxiliar
                          escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotalModificado<<endl;

                          //Se actualizan los resultados
                          Cantidad=CantidadModificada;
                          CostoTotal=CostoTotalModificado;
                       }

                      else{
                          //Se guarda la informacion en el fichero auxiliar
                            escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;
                      }

                     leyendo>>leer; //lectura
                   }
                   //Se cierran los ficheros
                   leyendo.close();
                   escribiendo.close();

                   remove("ListaProductos.txt"); //Se remueve el fichero que contiene la lista de productos
                   rename("auxiliando.txt","ListaProductos.txt"); //Se cambia el nombre del fichero auxiliar por ListaProductos.txt
               }

           contIng--; //Se resta una unidad al numero de ingredientes de la HAMBURGUESA

           if(contIng==2)
               Ingred="5"; //Se pasa a otro producto en ListaProductos.txt

           else if(contIng==1)
               Ingred="7";//Se pasa a otro producto en ListaProductos.txt

     }

       h--; //Se resta una unidad al numero de HAMBURGUESAS que pidio el usuario

       if(h==0) //Si ya no hay mas HAMBURGUESAS se finaliza
           break;

       //Se actualiza la cantidad de ingredientes de la HAMURGUESA y el ID del ingrediente inicial
       contIng=3;
       Ingred="4";
  }

    //Para gaseosas
    //*************************************************************************************************
    contIng=2;
    Ingred="1";

    while(i>0){ //Mientras el numero de GASEOSAS que pidio el usuario sea mayor que 0

            while(contIng>0){ //Mientras el numero de ingredientes que tiene la GASEOSA sea mayor a 0

                leyendo.open("ListaProductos.txt",ios::in); //archivo en modo lectura
                escribiendo.open("auxiliando.txt",ios::out); //archivo en modo escritura

                if(leyendo.is_open() && escribiendo.is_open()){ //Mientras ambos archivos esten abiertos
                    leyendo>>leer;

                    while(!leyendo.eof()){ //Mientras ListaProductos.txt no halla llegado a su fin
                       leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal; //lectura
                       if(leer==Ingred){ //Si se encuentra el Id del ingrediente
                          encontrado=true; //Se encontro el ingrediente

                          CantidadModificada=Cantidad-1; //Se le resta una unidad a ese ingrediente

                          //Para no guardar resultados negativos en el fichero
                          if(CantidadModificada<=0){
                              CantidadModificada=0;
                          }

                          CostoTotalModificado=CostoTotal-(CostoProducto); //Se le resta el costo del producto al costo total

                          //Para no guardar resultados negativos en el fichero
                          if(CostoTotalModificado<=0){
                              CostoTotalModificado=0;
                          }
                          //Se guarda la informacion en el fichero auxiliar
                           escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotalModificado<<endl;

                           //Se actualizan los resultados
                           Cantidad=CantidadModificada;
                           CostoTotal=CostoTotalModificado;
                        }

                       else{
                           //Se guarda la informacion en el fichero auxiliar
                             escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;
                       }

                      leyendo>>leer; //lectura
                    }
                    //Se cierran los ficheros
                    leyendo.close();
                    escribiendo.close();

                    remove("ListaProductos.txt"); //Se remueve el fichero que contiene la lista de productos
                    rename("auxiliando.txt","ListaProductos.txt"); //Se cambia el nombre del fichero auxiliar por ListaProductos.txt
                }

            contIng--; //Se resta una unidad al numero de ingredientes de la GASEOSA


            if(contIng==1)
                Ingred="6";//Se pasa a otro producto en ListaProductos.txt

      }

        i--; //Se resta una unidad al numero de GASEOSAS que pidio el usuario

        if(i==0) //Si ya no hay mas GASEOSAS se finaliza
            break;

        //Se actualiza la cantidad de ingredientes de la GASEOSA y el ID del ingrediente inicial
        contIng=2;
        Ingred="1";
  }

    //Para Paquete de nachos
    //********************************************************************************************************
    contIng=1;
    Ingred="8";

    while(j>0){ //Mientras el numero de PAQUETES DE NACHOS sea mayor que 0

           while(contIng>0){ //Mientras el numero de ingredientes que tienen los PAQUETES DE NACHOS sea mayor a 0

               leyendo.open("ListaProductos.txt",ios::in); //archivo en modo lectura
               escribiendo.open("auxiliando.txt",ios::out); //archivo en modo escritura

               if(leyendo.is_open() && escribiendo.is_open()){ //Mientras ambos archivos esten abiertos
                   leyendo>>leer;

                   while(!leyendo.eof()){ //Mientras ListaProductos.txt no halla llegado a su fin
                      leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal; //lectura
                      if(leer==Ingred){ //Si se encuentra el Id del ingrediente
                         encontrado=true; //Se encontro el ingrediente

                         CantidadModificada=Cantidad-1; //Se le resta una unidad a ese ingrediente

                         //Para no guardar resultados negativos en el fichero
                         if(CantidadModificada<=0){
                             CantidadModificada=0;
                         }

                         CostoTotalModificado=CostoTotal-(CostoProducto); //Se le resta el costo del producto al costo total

                         //Para no guardar resultados negativos en el fichero
                         if(CostoTotalModificado<=0){
                             CostoTotalModificado=0;
                         }
                         //Se guarda la informacion en el fichero auxiliar
                          escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotalModificado<<endl;

                          //Se actualizan los resultados
                          Cantidad=CantidadModificada;
                          CostoTotal=CostoTotalModificado;
                       }

                      else{
                          //Se guarda la informacion en el fichero auxiliar
                            escribiendo<<left<<setw(10)<<leer<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;
                      }

                     leyendo>>leer; //lectura
                   }
                   //Se cierran los ficheros
                   leyendo.close();
                   escribiendo.close();

                   remove("ListaProductos.txt"); //Se remueve el fichero que contiene la lista de productos
                   rename("auxiliando.txt","ListaProductos.txt"); //Se cambia el nombre del fichero auxiliar por ListaProductos.txt
               }

           contIng--; //Se resta una unidad al numero de ingredientes de los PAQUETES DE NACHOS




     }

       j--; //Se resta una unidad al numero de PAQUETES DE NACHOS que pidio el usuario

       if(j==0) //Si ya no hay mas PAQUETES DE NACHOS se finaliza
           break;

       //Se actualiza la cantidad de ingredientes de los PAQUETES DE NACHOS y el ID del ingrediente inicial
       contIng=1;
       Ingred="8";
  }
}

void Cliente::inserta_nombre(string linea, map<string, string> & nombres)
{
    int pos=linea.find(':'); //Para buscar ';'
    if(pos!= -1){
        string llave=linea.substr(0,pos); //para obtener los productos del combo
        string valor=linea.substr(pos+1); //para obtener el numero de esos productos
        nombres[llave]=valor; //Se van guardando los valores en el mapa
    }
}

void Cliente::leer_datos(string nombre_fichero, map<string, string>& nombres)
{
    string linea;
    ifstream F(nombre_fichero.c_str()); //Se declara el archivo el modo lectura
    getline(F,linea);// Para leer lineas del archivo
    while(!F.eof()){ //Mientras el archivo no haya llegado a su fin
        inserta_nombre(linea,nombres); //Se agrega el valor y la llave al mapa 'nombres'
        getline(F,linea); //Se lee la siguiente linea
    }
}

//Esta funcion es para saber si hay ingredientes para vender un combo
int Cliente::HayONoHayIngredientesParaCombo()
{
    //Declaracion
    map<string,string> nombres;
    ifstream leyendo, leyendo2;
    ofstream escribiendo;
    string a="PERROS",b="HAMBURGUESAS",c="GASEOSAS",d="NACHOS";
    int g=atoi(nombres[a].c_str()),h=atoi(nombres[b].c_str()),i=atoi(nombres[c].c_str()),j=atoi(nombres[d].c_str());
    string Producto;
    int Cantidad=0, CostoTotal=0, CostoProducto=0,contIng=3;
    bool encontrado=false;
    string leer;
    string Ingred="2";

    leer_datos("auxiliarC.txt",nombres); //Se usa la funcion de leer los datos en auxiliar.txt que contiene el combo que eligio
                                         //El usuario y los datos se agregan al mapa 'nombres'

    //Para los PERROS
    //***********************************************************************************************************

        while(contIng>=0){ //Mientras el numero de ingredientes de un PERRO sea mayor a 0

            leyendo.open("ListaProductos.txt",ios::in); //archivo en modo lectura

            if(leyendo.is_open()){ //si el archivo esta abierto
                leyendo>>leer; //lectura

                while(!leyendo.eof()){ //mientras archivo no llegue al fin
                   leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal; //lectura
                   if(leer==Ingred){ //Si se encuentra el ID del ingrediente en ListaProductos.txt
                      encontrado=true; //se encontro


                      //No hay ingredientes para vender combo
                      if(Cantidad<g || CostoProducto<=0 || CostoTotal<=0 )
                      {
                          cout<<"LO SENTIMOS, PERO NO TENEMOS INGREDIENTES PARA VENDERLE ESTE COMBO"<<endl;
                          cout<<endl;
                          exit(0); //Abandona el programa
                      }



                    }

                   leyendo>>leer; //lectura
                }
                leyendo.close(); //se cierra el archivo
            }

        contIng--; //Se le resta una unidad a los ingredientes

        if(contIng==2)
            Ingred="3";//Se cambia a otro ingrediente

        if(contIng==1)
            Ingred="5";//Se cambia a otro ingrediente
        }

    //***********************************************************************************************************
    //Para hamburguesas
    //*******************************************************************************************************
     Ingred="4";
     contIng=3;

     while(contIng>=0){ //Mientras el numero de ingredientes de una HAMBURGUEDA sea mayor a 0

                leyendo.open("ListaProductos.txt",ios::in); //archivo en modo lectura

                if(leyendo.is_open()){ //si el archivo esta abierto
                    leyendo>>leer; //lectura

                    while(!leyendo.eof()){ //mientras archivo no llegue al fin
                       leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal; //lectura
                       if(leer==Ingred){ //Si se encuentra el ID del ingrediente en ListaProductos.txt
                          encontrado=true; //se encontro


                          //No hay ingredientes para vender combo
                          if(Cantidad<g || CostoProducto<=0 || CostoTotal<=0 )
                          {
                              cout<<"LO SENTIMOS, PERO NO TENEMOS INGREDIENTES PARA VENDERLE ESTE COMBO"<<endl;
                              cout<<endl;
                              exit(0); //Abandona el programa
                          }



                        }

                       leyendo>>leer; //lectura
                    }
                    leyendo.close(); //se cierra el archivo
                }

            contIng--; //Se le resta una unidad a los ingredientes

            if(contIng==2)
                Ingred="5";//Se cambia a otro ingrediente

            if(contIng==1)
                Ingred="7";//Se cambia a otro ingrediente
            }

    //Para gaseosas
    //***************************************************************************************************************
    Ingred="1";
    contIng=2;

    while(contIng>=0){ //Mientras el numero de ingredientes de una GASEOSA sea mayor a 0

               leyendo.open("ListaProductos.txt",ios::in); //archivo en modo lectura

               if(leyendo.is_open()){ //si el archivo esta abierto
                   leyendo>>leer; //lectura

                   while(!leyendo.eof()){ //mientras archivo no llegue al fin
                      leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal; //lectura
                      if(leer==Ingred){ //Si se encuentra el ID del ingrediente en ListaProductos.txt
                         encontrado=true; //se encontro


                         //No hay ingredientes para vender combo
                         if(Cantidad<g || CostoProducto<=0 || CostoTotal<=0 )
                         {
                             cout<<"LO SENTIMOS, PERO NO TENEMOS INGREDIENTES PARA VENDERLE ESTE COMBO"<<endl;
                             cout<<endl;
                             exit(0); //Abandona el programa
                         }



                       }

                      leyendo>>leer; //lectura
                   }
                   leyendo.close(); //se cierra el archivo
               }

           contIng--; //Se le resta una unidad a los ingredientes
           if(contIng==1)
               Ingred="6";//Se cambia a otro ingrediente
           }

   //Para nachos
   //********************************************************************************************************************
   Ingred="8";
   contIng=1;

   while(contIng>=0){ //Mientras el numero de ingredientes de un PAQUETE DE NACHOS sea mayor a 0

              leyendo.open("ListaProductos.txt",ios::in); //archivo en modo lectura

              if(leyendo.is_open()){ //si el archivo esta abierto
                  leyendo>>leer; //lectura

                  while(!leyendo.eof()){ //mientras archivo no llegue al fin
                     leyendo>>Producto>>Cantidad>>CostoProducto>>CostoTotal; //lectura
                     if(leer==Ingred){ //Si se encuentra el ID del ingrediente en ListaProductos.txt
                        encontrado=true; //se encontro


                        //No hay ingredientes para vender combo
                        if(Cantidad<g || CostoProducto<=0 || CostoTotal<=0 )
                        {
                            cout<<"LO SENTIMOS, PERO NO TENEMOS INGREDIENTES PARA VENDERLE ESTE COMBO"<<endl;
                            cout<<endl;
                            exit(0); //Abandona el programa
                        }



                      }

                     leyendo>>leer; //lectura
                  }
                  leyendo.close(); //se cierra el archivo
              }

          contIng--; //Se le resta una unidad a los ingredientes
          }

}

int Cliente::MenuCompradeCombos()
{

        int opcion=0;

          do{
              cout<<"|.......................................................|"<<endl;
              cout<<"|.........BIENVENIDO AL PUNTO DE VENTAS DEL CINE........|"<<endl;
              cout<<"|.......................................................|"<<endl;
              cout<<"|1. Comprar un combo....................................|"<<endl;
              cout<<"|2. Salir...............................................|"<<endl;
              cout<<"|....................QUE DESEA HACER?...................|"<<endl;
              cout<<"|.......................................................|"<<endl;
              cout<<endl;

              cin>>opcion;
              cout<<"---------------------------------------------------------"<<endl;
              cout<<endl;

              switch (opcion) {

                  case 1:

                  {

                      list<string> lalista; //Lista de string
                      string line,producto;

                      //Se muestra la lista de los combos, para esto agregamos las lineas del archivo en una lista

                      cout<<"-------------------LISTA DE COMBOS-----------------------" << endl;
                      cout<<"---------------------------------------------------------" <<endl;
                      cout<<endl;

                      ifstream lectura("Combos.txt"); //Apertura del archivo en modo lectura

                      if(lectura.is_open()){ //Si el fichero esta abierto
                          while (getline(lectura, producto)){ //leer lineas del fichero
                              lalista.push_back(producto); //Se van agragando las lineas del archivo a la lista
                              cout << producto << endl;
                              lalista.pop_back(); //se eliminan elementos para reducir tamanio de la lista
                          }
                      }

                      lectura.close(); //Se cierra el archivo

                      while( lalista.size()!=0 ) //mientras la lista no este vacia
                      {
                        producto = lalista.front();
                        cout << producto << endl;
                        lalista.pop_front(); //Elimina elementos para reducir tamanio de la lista
                      }

           //----------------------------------------------------------------------------------------------

                    ComprarCombo();  //Funcion para comprar los combos


                  } //case 1

              case 2:
                  return  0;
              }
          }
          while(opcion!=0);
    }






