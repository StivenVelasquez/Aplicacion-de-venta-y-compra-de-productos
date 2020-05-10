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

            switch (opcion) {

                case 1:

            {
             ifstream leer("ListaPreciosCombos.txt"); //Apertura del archivo en modo lectura
          //   leer.open("ListaPreciosCombos.txt",ios::in);
              string precio;

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
                      cout<<"ID: "<<ID<<endl;
                      cout<<"PRECIO: "<<precio<<endl;
                      cout<<endl;
                      }

                  leer>>ID;
                  }
              }
              leer.close();

/*



    if(aux.is_open() && lectura.is_open()){

       cout<<endl;
       cout<<"--------------------------------------------------------";

       lectura>>Cedula_;

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
 */

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
