#ifndef MENU_H
#define MENU_H

#include "codificaciones.h"

bool comprobarLectura( string nombredelarchivo){
    ifstream archivo;
    archivo.open(nombredelarchivo);
    if(!archivo){
        cerr << "No se puede abrir el archivo. No se encuentra." << endl;
        return false;
    }else{
        cout << "Verificacion exitosa" <<endl;
        return true;
    }
}

string leerUnaLinea(int numero_linea_deseada){
    string linea;
    int numero_linea_actual=0;
    ifstream archivo;
    archivo.open("sudo.txt");
    while(getline(archivo, linea)){
        if(numero_linea_actual==numero_linea_deseada){
            archivo.close();
            return linea;
        }
    }
}

void verificacionAdministrador(){
    string contraseña_ingresada ="", contraseña_guardada= leerUnaLinea(0);
    cin >> contraseña_ingresada;
            contraseña_guardada= decodificarM2();
    if(contraseña_guardada==contraseña_ingresada){
        return true;
    }
}

void EscribirContraseñasobreArchivo(string line, string nombreArchivo){
    ofstream archivo;
    archivo.open(nombreArchivo);
    archivo<<line<<endl;
    archivo.close();
}



string CrearArhcivo(){
    //Primera parte: Pedir una contraseña para el administrados y encriptarla
    string nombre_nuevo_archivo= "Nuevo archivo.txt";
    string lecturaConsola = "";
    cout << "Ingrese la clave del administrador: " << endl;
    cin >> lecturaConsola;
    int longitud = lecturaConsola.length();

    string lineaBin= "";

    for (int i = 0; i < longitud; i++) {
        char aux[9];
        convIntBin(aux, lecturaConsola[i]);
        lineaBin+= aux;
    }

    cout << "La contraseña en binario es: " << lineaBin << endl;

    int n;
    cout << "Ingrese semilla de codificacion: ";
    cin >> n;

    int tamaño= lineaBin.length();
    if(tamaño < n){
        for(int x = tamaño; x < n ; x++)
            lineaBin += "0";
    }

    if((tamaño % n) != 0){
        for(int x = (tamaño % n); x < n ; x++)
            lineaBin += "0";
    }

    string contraseña_encriptada;

    contraseña_encriptada= codificarM2(lineaBin, n);

    EscribirContraseñasobreArchivo(contraseña_encriptada, nombre_nuevo_archivo);

    return nombre_nuevo_archivo;
}

void ComprobacionDeArchivo(string& nombre_del_archivo, bool& bandera){
    bool inicio= true;
    char respuesta= ' ';
    char respuesta_creacion_archivo= ' ';

    while(inicio){
        cout <<"\nVerficacion de los archivos del sistema...\n"<<endl;
        bandera= comprobarLectura(nombre_del_archivo);
        if(bandera){
            inicio= false;
        }else{
            cout << "Desea crear un archivo? (Ingrese s(si) o n(no)): "; cin >> respuesta;
            switch(respuesta){
            case 's':

                nombre_del_archivo = CrearArhcivo();
                break;
            case 'n':
            {
                bool bandera_interna= true;
                while(bandera_interna){
                    cout<< "Desea salir del programa? (Ingrese s(si) o n(no)):  "; cin >> respuesta_creacion_archivo;
                    switch(respuesta_creacion_archivo){
                    case 's':{
                        inicio=false;
                        bandera_interna=false;}
                    break;
                    case 'n':
                        bandera_interna= false;
                        break;
                    default:
                        cout << "\nIngresaste una opcion invalida" <<endl;
                        break;
                    }
                    cin.clear();
                    cin.ignore(255, '\n');
                }
            }
            break;
            default:
                cout << "\nIngresaste una opcion invalida" <<endl;
                cin.clear();
                cin.ignore(255, '\n');
                break;
            }
        }
    }

}
#endif // MENU_H
