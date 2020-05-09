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

int Cliente::ComprarCombo()
{

    //Declaracion de variables
    ofstream aux;
    ifstream lectura;
    string ID, linea;
    int opcion=0;
    list<string> listaC; //Lista de string

   do{

    cout<<endl;
    cout<<endl;
    cout<<"======================================================="<<endl;
    cout<<"*****INGRESE EL ID DEL COMBO QUE DESEA COMPRAR*********"<<endl;
    cout<<"======================================================="<<endl;
    cout<<endl;
    cin>>ID;

    ifstream leer("Combos.txt"); //Apertura del archivo en modo lectura

    if(leer.is_open()){
        while (getline(leer, linea,'*')){ //leer lineas del fichero
                    listaC.push_back(linea); //Se van agragando las lineas del archivo a la lista
                    cout << linea << endl;
                    listaC.pop_back(); //se elimina el ultimo elemento
                    }

                }
                leer.close(); //Se cierra el archivo


            cout<<"----------ESTA SEGURO QUE DE HACER ESTA COMPRA?--------"<<endl;
            cout<<endl;

            while( listaC.size()!=0 ) //mientras la lista no este vacia
            {
              linea = listaC.front();
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
            cout<<"--------------------------------------------------------"<<endl;
            cout<<endl;

            switch (opcion) {

                case 1:
                     cout<<"--------------MUCHAS GRACIAS POR SU COMPRA--------------"<<endl;
                     cout<<endl;
                     cout<<"--------------------------------------------------------"<<endl;
                     return EXIT_SUCCESS;

                case 2:
                    break;

            }

    }while(true);




/*
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

*/

   /* aux.open("auxiliar.txt",ios::out);
    lectura.open("Combos.txt",ios::in);

    if(aux.is_open() && lectura.is_open()){

       cout<<endl;
       cout<<"--------------------------------------------------------";

       lectura>>ID;

       while(!lectura.eof()){
           lectura>>clave_>>saldo_;
           if(auxCedula==Cedula_){
               encontrado_=true;
               cout<<endl;
               cout<<"________________________________________________________"<<endl;
               cout<<"Cedula: "<<Cedula_<<endl;
               cout<<"Clave: "<<clave_<<endl;
               cout<<"Saldo: "<<saldo_<<endl;
               cout<<"________________________________________________________"<<endl;
               cout<<endl;

             //CONDICION PARA DEBITAR POR LA CONSULTA EN CASO DE QUE EL MONTO DE SU CUENTA
             if(saldo_>=1000){
                                 saldo_modificado=saldo_-1000;

                                 cout<<"|.......................................................|"<<endl;
                                 cout<<"|......ADVERTENCIA! ACABAMOS DE DEBITAR 1000 COP........|"<<endl;
                                 cout<<"|.....DE SU CUENTA POR CONSULTAR EN NUESTRO BANCO.......|"<<endl;
                                 cout<<"|.......................................................|"<<endl;
                                 cout<<endl;

                                 saldo_=saldo_modificado;
                         }

               aux<<left<<setw(10)<<Cedula_<<setw(13)<<clave_<<setw(7)<<setprecision(2)<<right<<saldo_<<endl;
               }

             else{
                     aux<<left<<setw(10)<<Cedula_<<setw(13)<<clave_<<setw(7)<<setprecision(2)<<right<<saldo_<<endl;

                  }


          lectura>>Cedula_;

           }
     }

    else
     {
              cout<<"--No se pudo abrir el Archivo o aun no ha sido Creado--"<<endl;
              cout<<endl;
             }

     if(encontrado_==false){
              cout<<endl;
              cout<<"No se encontro ningun registro con ese numero de cedula"<<endl;
              cout<<endl;
             }

     aux.close();
     lectura.close();
     remove("clientes.txt");
     rename("auxiliar.txt","clientes.txt");

*/

}
