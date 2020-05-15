#include "empleado.h"
#include <iomanip>
#include <vector>
#include <string>

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

    cout<<"INGRESE ID DEL PRODUCTO ";
    cin>>auxID;
    cout<<endl;

    //Se abren los ficheros a utilizar
    aux.open("auxiliar.txt",ios::out);
    lectura.open("ListaProductos.txt",ios::in);
    aux2.open("ListaProductos2.txt",ios::out);

    if(aux.is_open() && lectura.is_open()&& aux2.is_open()){ //Condicion para cuando los ficheros esten abiertos

        cout<<endl;
        cout<<"--------------------------------------------------------";
        cout<<endl;

        lectura>>ID; //lectura

        while(!lectura.eof()){ //mientras no se halla llegado al fin del fichero
            lectura>>Producto>>Cantidad>>CostoProducto>>CostoTotal;
               if(auxID==ID){ //Si se encuentra ID del producto
                  encontrado=true; //Se encontro el identificador

                    //para que no ponga resultados negativos en la base de datos
                    if(CostoTotal<=0) {
                        cout<<endl;
                        CostoTotal=0; //para que no ponga resultados negativos en la base de datos
                        cout<<"|-------------------------------------------------------|"<<endl;
                        cout<<"|EL CINE NO CUENTA CON "<<Producto<<" POR FAVOR ADQUIERA-|"<<endl;
                        cout<<"|-ESTE PRODUCTO, EL CUAL ES NECESARIO PARA LAS VENTAS---|"<<endl;
                        cout<<"|-------------------------------------------------------|"<<endl;
                        cout<<endl;
                        cout<<endl;

                        //Se pasa a imprimir la informacion en los ficheros
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
                   aux2<<left<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<CantidadModificada<<endl;

                    cout<<"|-------------------------------------------------------|"<<endl;
                    cout<<"|-----------------REGISTRO MODIFICADO-------------------|"<<endl;
                    cout<<"|-------------------------------------------------------|"<<endl;
                    cout<<endl;

                    //Actualizacion de datos
                    Cantidad=CantidadModificada;
                    CostoTotal=CostoTotalModificado;


                }

                else{
                   //Imprimir de manera orgnizada en los ficheros
                    aux<<left<<setw(10)<<ID<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<setw(7)<<CostoProducto<<setw(7)<<setprecision(2)<<right<<CostoTotal<<endl;
                    aux2<<left<<setw(10)<<Producto<<setw(13)<<setprecision(2)<<right<<Cantidad<<endl;
                }

     lectura>>ID; //lectura

        }
    }


   else{
           cout<<"--No se pudo abrir el Archivo o aun no ha sido Creado--"<<endl;
           cout<<endl;
       }

   if(encontrado==false){ //no se encontro el ID
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
   vector<string>list; //Vector de string llamado lista
   string line,producto,perro, hamburguesa, gaseosa, nachos,NombreCombo, IDCombo;
    int n=0, PrecioCombo;
   //Para manejo de archivos
   ofstream escritura, escritura2;
   ifstream consulta;

   cout<<"===================PRODUCTOS DISPONIBLES================"<<endl;
   cout<<endl;
   cout<<left<<setw(10)<<"PRODUCTO"<<setw(13)<<setprecision(2)<<setw(13)<<right<<"           CANTIDAD"<<endl;
   cout<<endl;

   //Pasamos los datos del fichero a un vector para luego pasarlos a imprimir en pantalla, y as se tenga claridad
   //de los productos disponibles para crear los combos
   ifstream lectura("ListaProductos2.txt"); //Apertura del archivo en modo lectura
   if(lectura.is_open()){ //si archivo esta abierto
       while (getline(lectura, producto)){ //se leen las lineas del fichero
           list.push_back(producto); //Se van agregando los productos en la lista
           cout << producto << endl;
           list.pop_back();//Para reducir tamanio de la lista
       }
   }
   lectura.close(); //se cierra archivo

   //Se imprime el vector con los productos disponibles
   for (int i = 0; i < list.size(); i++){
       cout << list[i];
       cout << endl;
   }
   cout<<endl;

   cout<<"--------------------------------------------------------"<<endl;

   cout<<"INGRESE EL ID DEL COMBO QUE DESEA CREAR: "<<endl;
   cin>>IDCombo;

   cout<<"--------------------------------------------------------"<<endl;
   cout<<endl;

   consulta.open("Combos.txt",ios::in); //Se abre el fichero en modo lectura

   string linea;
   string Texto="ID:",IDC;

   if(consulta.is_open()){ //mientras este abierto

       consulta>>Texto>>IDC;

       while(!consulta.eof()){ //mientras no se halla llegado al fin del fichero

           if(IDCombo==IDC){
               cout<<"|-------------------------------------------------------|"<<endl;
               cout<<"|----------Ya Existe este combo que desea crear---------|"<<endl;
               cout<<"|-------------------------------------------------------|"<<endl;
               cout<<endl;
               return -1;
           }
           consulta>>Texto; //lectura
       }
   consulta.close(); //cerrar archivo
   }

   cout<<"INGRESE EL NOMBRE QUE DESEA DARLE AL COMBO "<<endl;
   cin>>NombreCombo;

   cout<<"-------------------------------------------------------"<<endl;
   cout<<endl;

   cout<<"INGRESE EL VALOR DEL COMBO: "<<endl;
   cin>>PrecioCombo;

   cout<<"-------------------------------------------------------"<<endl;
   cout<<endl;

   //Se abren los archivos en modo escritura
   escritura.open("Combos.txt",ios::out|ios::app);
   escritura2.open("ListaPreciosCombos.txt",ios::out|ios::app);

   //En Combos.txt se van ingresando los combos creados y el otro fichero es para guardar el ID del combo con su precio
   if(escritura.is_open()&& escritura2.is_open()){ //si los archivos estan abiertos
      escritura<<endl;
      escritura<<"ID: "<<IDCombo<<endl;
      escritura<<"COMBO "<<NombreCombo<<endl;
      escritura<<"PRECIO: "<<PrecioCombo<<"$"<<endl;
      escritura<<"-----------------"<<endl;
      escritura<<endl;

      //Se guardan los identificadores de los combos con sus precios en el archivo ListaPreciosCombos.txt
   escritura2<<left<<setw(10)<<IDCombo<<setw(13)<<PrecioCombo;
   }

   //Se cierra los ficheros
   escritura2.close();
   escritura.close();

    do{

       cout<<"|-------------------------------------------------------|\n";
       cout<<"|----------------MENU PARA CREAR COMBOS-----------------|\n";
       cout<<"|-------------------------------------------------------|\n";
       cout<<"|Nota-Para finalizar la creacion de un combo  ingrese 5-|\n";
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
       cout<<"INGRESE UNA OPCION E INGRESE LA OPCION '5' PARA TERMINAR DE CREARLO: ";
       cin>>n;
       cout<<"------------------------------------------------------"<<endl;
       cout<<endl;

       switch (n) {

           //Para los perros
           case 1:
           {
               int Cant_Perros;
               escritura.open("Combos.txt",ios::out|ios::app); //Se abre fichero para ir creando los combos

               if(escritura.is_open()){ //si archivo esta abierto
                   cout<<"INGRESE LA CANTIDAD DE PERROS: "<<endl;
                   cin>>Cant_Perros;

                   escritura<<"PERROS: "<<Cant_Perros<<endl;

                   cout<<"------------------------------------------------------"<<endl;
                   cout<<endl;
               }
            escritura.close(); //Se cierra archivo
           }
           break;

           //Para las hamburguesas
           case 2:
           {
               int Cant_Hamburguesas;
               escritura.open("Combos.txt",ios::out|ios::app); //Se abre el fichero
               if(escritura.is_open()){//si archivo esta abierto
                   cout<<"INGRESE LA CANTIDAD DE HAMBURGUESAS: "<<endl;
                   cin>>Cant_Hamburguesas;

                   escritura<<"HAMBURGUESAS:" <<Cant_Hamburguesas<<endl;

                   cout<<"------------------------------------------------------"<<endl;
                   cout<<endl;

               }
           escritura.close(); //Se cierra el fichero
           }
           break;

           //Para las gaseosas
           case 3:
           {
               int Cant_Gaseosas;
               escritura.open("Combos.txt",ios::out|ios::app); //Se abre fichero
               if(escritura.is_open()){//si archivo esta abierto
                   cout<<"INGRESE LA CANTIDAD DE GASEOSAS: "<<endl;
                   cin>>Cant_Gaseosas;

                   escritura<<"GASEOSAS: "<<Cant_Gaseosas<<endl;

                   cout<<"------------------------------------------------------"<<endl;
                   cout<<endl;

               }
           escritura.close(); //Se cierra archivo
           }
           break;

           //Para los nachos
           case 4:
           {
               int Cant_PaquetesNachos;
               escritura.open("Combos.txt",ios::out|ios::app); //Se abre el archivo
               if(escritura.is_open()){//si archivo esta abierto
                   cout<<"INGRESE LA CANTIDAD DE PAQUETES DE NACHOS: "<<endl;
                   cin>>Cant_PaquetesNachos;

                   escritura<<"PAQUETES DE NACHOS: "<<Cant_PaquetesNachos<<endl;

                   cout<<"------------------------------------------------------"<<endl;
                   cout<<endl;

               }
           escritura.close(); //Se cierra archivo
           }
           break;

           //Para terminar la creacion de un combo
            case 5:
           {
               escritura.open("Combos.txt",ios::out|ios::app); //Se abre fichero
               if(escritura.is_open()){//si archivo esta abierto
                   escritura<<endl;
                   escritura<<"-----------------"<<endl;
                   escritura<<"*"<<endl;
                   escritura<<endl;
               }
           escritura.close(); //Se cierra fichero
           return 0;
           }
           break;

           default:
               cout<<"|=======================================================|"<<endl;
               cout<<"|=================¡Opcion Incorrecta!===================|"<<endl;
               cout<<"|=======================================================|"<<endl;

           }
       }while(n>=1 &&n<=5);

    cin.get();
}

int Empleado::GenerarReporteVentas()
{
    //Declaracion de variables
    vector<string>list; //Vector de string
    string linea,ID, line;
    ifstream lectura;
    int Plata=0, Platatotal=0, Opc=0;

    cout<<endl;
    cout<<"ID-COMBO    PRECIO"<<endl;
    cout<<endl;

    //Se pasan las lineas del archivo a un vector
    lectura.open("ventas.txt"); //Se abre el archivo
    if(lectura.is_open()){//si archivo esta abierto
            while (getline(lectura, linea)){ //Se leen las lineas del archivo
            list.push_back(linea); //Se agregan al vector
            cout << linea << endl;
            list.pop_back(); //para reducir tamanio del vector
        }
    }
    lectura.close(); //Se cierra el archivo

    //Se imprimen las ventas del dia
    for (int i = 0; i < list.size(); i++){
        cout << list[i];
        cout << endl;
    }
    cout<<endl;

    list.clear(); //Se borra contenido del vector

    lectura.open("ventas.txt"); //Se abre el archivo

    //Este proceso se hace para sumar las ventas totales del dia
    if(lectura.is_open()){//si archivo esta abierto
        lectura>>ID>>Plata; //lectura
        Platatotal=Plata;
        while (getline(lectura, line,'\n')){ //Se leen las lineas del archivo y se va sumando el dinero
          lectura>>ID>>Plata;
          Platatotal+=Plata;
        }
    }
    lectura.close(); //cerrar archivo

    //Se imprime el dinero total vendido
    cout<<endl;
    cout<<"EL DINERO TOTAL VENDIDO EL DIA DE HOY ES DE "<<Platatotal<<"$"<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<endl;

    cout<<"--------------------------------------------------------"<<endl;
    cout<<"------DESEA ELIMINAR REGISTROS DE LAS VENTAS PARA-------"<<endl;
    cout<<"----------INICIAR EL REGISTRO DE UN NUEVO DIA-----------"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"SI-------1"<<endl;
    cout<<"NO-------2"<<endl;
    cout<<endl;
    cout<<"INGRESE UNA OPCION: "<<endl;
    cin>>Opc;
    cout<<endl;
    cout<<"--------------------------------------------------------"<<endl;

    if(Opc==1){
        //Para eliminar el registro de las ventas
        ofstream aux;
        aux.open("auxi.txt",ios::out);
        aux.close();

        remove("ventas.txt");
        rename("auxi.txt","ventas.txt");
        cout<<endl;
        cout<<"SE HA ELIMINADO EL REGISTRO DE VENTAS"<<endl;
        cout<<endl;
        return 0;
    }

    else{
        return 0;
    }
}

int Empleado::salir()
{
    cout<<"|=======================================================|"<<endl;
    cout<<"|==================Proceso finalizado===================|"<<endl;
    cout<<"|=======================================================|"<<endl;
    cout<<endl;
    return 0;
}
