#include "cliente.h"
#include <iomanip>

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
    string ID, IDaux, linea;
    int opcion=0;
    list<string> listaC; //Lista de string

   do{

    cout<<endl;
    cout<<endl;
    cout<<"======================================================="<<endl;
    cout<<"*****INGRESE EL ID DEL COMBO QUE DESEA COMPRAR*********"<<endl;
    cout<<"======================================================="<<endl;
    cout<<endl;
    cin>>IDaux;

    ifstream leer("Combos.txt"); //Apertura del archivo en modo lectura
    string Texto="ID: ";

    if(leer.is_open()){
                    while (getline(leer, linea, '*'))
                    {
                        if(linea.find(Texto+IDaux) != string::npos){
                        listaC.push_back(linea); //Se van agragando las lineas del archivo a la lista
                        cout << linea << endl;
                        listaC.pop_back(); //se elimina el ultimo element
                        }

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

            int CantidadDinero; //  Variable que representa la cantidad de dinero con el que el usuario pagara el combo

            switch (opcion) {

                case 1:

            {
             ifstream leer("ListaPreciosCombos.txt"); //Apertura del archivo en modo lectura
          //   leer.open("ListaPreciosCombos.txt",ios::in);
              int precio;
              int division,restando, Devuelta;

              if(leer.is_open() ){
                  cout<<endl;
                  cout<<"--------------------------------------------------------";
                  cout<<endl;

                  leer>>ID;

                  while(!leer.eof()){
                      leer>>precio;
                      if(ID==IDaux){
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

                      cout<<"INGRESE LA CANTIDAD DE DINERO CON EL QUE DESEA PAGAR SU PEDIDO"<<endl;
                      cin>>CantidadDinero;
                      cout<<"--------------------------------------------------------------"<<endl;
                      cout<<endl;
                      cout<<endl;

                      Devuelta=CantidadDinero-precio;

                      cout<<"A CONTINUACIÓN SE MUESTRA SU DEVUELTA: "<<endl;
                      cout<<"--------------------------------------------------------------"<<endl;
                      cout<<endl;

                      int cantidades[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};//lista donde se guardan las cantidades dadas
                      for(int i=0;i<=10;i++){//recorre la lista cantidades
                          division=Devuelta/cantidades[i];//divide el dinero por cada valor en cantidades
                          if(division==0){
                              cout<<cantidades[i]<<" : "<<division<<endl;
                              if(cantidades[i]==50){
                                  break;
                              }
                          }
                          else {
                              restando=division*cantidades[i];
                              Devuelta=Devuelta-restando;//actualiza el dinero
                              cout<<cantidades[i]<<" : "<<division<<endl;

                          }

                      }

                      }

                  leer>>ID;
                  }
              }
              leer.close(); //Se cierra el fichero

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

               }
               escritura.close();

                     cout<<endl;
                     cout<<"--------------MUCHAS GRACIAS POR SU COMPRA--------------"<<endl;
                     cout<<endl;
                     cout<<"--------------------------------------------------------"<<endl;
                     return EXIT_SUCCESS;
                 }
                break;

                case 2:
                    break;

            }

    }while(true);


}
