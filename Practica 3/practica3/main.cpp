#include "Menu.h"

using namespace std;

int main()
{
    bool bandera= false;
    string nombre_del_archivo= "sumo.txt";

    ComprobacionDeArchivo(nombre_del_archivo, bandera);

    while(bandera){
        int eleccion_menu_ingreso=0;
        cout << "\nBIENVENIDO A NUESTRO SISTEMA! \n" << endl;
        cout << "Seleccione un modo de ingreso: " <<endl;
        cout << "1. Administrador" <<endl;
        cout << "2. Usuario" <<endl;
        cout << "3. Salir del sistema" <<endl;
        try{
            if(!(cin >> eleccion_menu_ingreso)){
                throw 1;
            }else if(eleccion_menu_ingreso!=1 && eleccion_menu_ingreso!=2){
                throw 2;
            }else if(eleccion_menu_ingreso==1){
                cout << "Ingrese la contraseña"<<endl;
                if(verificacionAdministrador()){

                }
            }else if(eleccion_menu_ingreso==2){
                cout << "respuesta 2"<<endl;
            }else if(eleccion_menu_ingreso==3){
                bandera=false;
            }
        } catch(int n){
            if(n==1){
                cout<<"\n Ingresate una opcion invalida. Solo puede ingresar numeros\n"<<endl;
                cin.clear();
                cin.ignore();
            }if(n==2){
                cout<<"\nSeleccione 1 o 2 para ingresar\n"<<endl;
            }
        }

    }

    return 0;
}
