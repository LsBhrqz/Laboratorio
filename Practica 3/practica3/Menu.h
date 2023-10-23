#ifndef MENU_H
#define MENU_H

#include "codificaciones.h"
#include <string>

int NumeroLineasArchivo(string nombreArchivo){
    string linea;
    int numero_linea_actual=0;
    ifstream archivo;
    archivo.open(nombreArchivo);
    while(getline(archivo, linea)){
        numero_linea_actual++;
    }
    archivo.close();
    return numero_linea_actual;
}

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

string leerUnaLinea(int numero_linea_deseada, string nombreArchivo){
    string linea;
    int numero_linea_actual=0;
    ifstream archivo;
    archivo.open(nombreArchivo);
    while(getline(archivo, linea)){
        if(numero_linea_actual==numero_linea_deseada){
            archivo.close();
            return linea;
        }
        numero_linea_actual++;
    }
}

bool verificacionAdministrador(string nombreArchivo, int semilla_de_codificacion){
    string contraseña_ingresada =" ";
    string contraseña_guardada= leerUnaLinea(0, nombreArchivo);
    cin >> contraseña_ingresada;
    contraseña_guardada= decodificarM2(contraseña_guardada, semilla_de_codificacion);
    contraseña_guardada= convBinInt(contraseña_guardada);
    if(contraseña_guardada==contraseña_ingresada){
        return true;
    }else{
        return false;
    }
}

void EscribirContraseñasobreArchivo(string line, string nombreArchivo){
    ofstream archivo;
    archivo.open(nombreArchivo);
    archivo<<line<<endl;
    archivo.close();
}

string CrearArhcivo(int& n){
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

void ComprobacionDeArchivo(string& nombre_del_archivo, bool& bandera, int &semilla){
    bool inicio= true;
    char respuesta= ' ';
    string verificar_tamaño= "";
    char respuesta_creacion_archivo= ' ';

    while(inicio){
        cout <<"\nVerficacion de los archivos del sistema...\n"<<endl;
        bandera= comprobarLectura(nombre_del_archivo);
        if(bandera){
            inicio= false;
        }else{
            cout << "Desea crear un archivo? (Ingrese s(si) o n(no)): "; cin >>verificar_tamaño;
            if(verificar_tamaño.length() > 1){
                cout << "Solo puedes ingresar una letra" <<endl;
            }else if (verificar_tamaño.length() ==1 && verificar_tamaño != "\n"){
                respuesta= verificar_tamaño[0];
                switch(respuesta){
                case 's':
                    nombre_del_archivo = CrearArhcivo(semilla);
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

}

bool cedulaRepetida(string nombre_del_archivo, string cedula_a_verificar){
    string linea;
    ifstream archivo;
    archivo.open(nombre_del_archivo);
    int numero_de_lineas= NumeroLineasArchivo(nombre_del_archivo);
    for(int i=1; i<numero_de_lineas; i+=3){
        linea= leerUnaLinea(i, nombre_del_archivo);
        if(linea==cedula_a_verificar){
            archivo.close();
            return true;
        }
    }
    return false;
}

void CrearUsuario(string nombre_archivo, int semilla){
    ofstream archivo;
    string linea;
    long long int numero;
    archivo.open(nombre_archivo, ios::app);
    for(int i=0; i<3; i++){
        if(i==0){
            bool bandera=true;
            while(bandera){
                cout <<"Ingrese la cedula (Solo ingrese numeros): ";
                try{
                    if(!(cin >> numero)){
                        throw 1;
                    }else{
                        string version_string= to_string(numero);
                        int longitud = version_string.length();
                        string lineaBina= "";
                        for (int i = 0; i < longitud; i++) {
                            char aux[9];
                            convIntBin(aux, version_string[i]);
                            lineaBina+= aux;
                        }
                        version_string= codificarM2(lineaBina, semilla);
                        if(cedulaRepetida(nombre_archivo, version_string)){
                            cout << "No se puede agregar esta cedula porque ya existe en el archivo" <<endl;
                        }else{
                            archivo << version_string<< endl;
                            bandera=false;
                        }

                    }
                }catch(int error){
                    if(error==1){
                        cout<<"\n Ingresate una opcion invalida. Solo puede ingresar numeros\n"<<endl;
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                }
            }
        }else if(i==1){
            cout <<"Ingrese la clave: "; cin >> linea;
            int longitud = linea.length();
            string lineaBina= "";
            for (int i = 0; i < longitud; i++) {
                char aux[9];
                convIntBin(aux, linea[i]);
                lineaBina+= aux;
            }
            linea= codificarM2(lineaBina, semilla);
            archivo << linea<< endl;
        }else{
            bool bandera2=true;
            while(bandera2){
                cout <<"Ingrese el saldo (Solo ingrese numeros): ";
                try{
                    if(!(cin >> numero)){
                        throw 1;
                    }else{
                        string version_string_saldo= to_string(numero);
                        int longitud = version_string_saldo.length();
                        string lineaBina= "";
                        for (int i = 0; i < longitud; i++) {
                            char aux[9];
                            convIntBin(aux, version_string_saldo[i]);
                            lineaBina+= aux;
                        }
                        version_string_saldo= codificarM2(lineaBina, semilla);
                        archivo << version_string_saldo<< endl;
                        bandera2=false;
                    }
                }catch(int error){
                    if(error==1){
                        cout<<"\n Ingresate una opcion invalida. Solo puede ingresar numeros\n"<<endl;
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                }
            }

        }
    }
    archivo.close();
}

string ValidarCedula_o_Saldo(string nombre){
    string version_string;
    long long int numero;
    bool bandera=true;
    while(bandera){
        cout <<"Ingrese "<<nombre<<" (Solo ingrese numeros): ";
        try{
            if(!(cin >> numero)){
                throw 1;
            }else{
                version_string= to_string(numero);
                bandera=false;
            }
        }catch(int error){
            if(error==1){
                cout<<"\n Ingresate una opcion invalida. Solo puede ingresar numeros\n"<<endl;
                cin.clear();
                cin.ignore(255, '\n');
            }
        }
    }
    return version_string;
}


bool ValidacionUsuario(string nombre_del_archivo, int semilla, int& numero_de_linea_cedula){
    string cedula;
    cedula= ValidarCedula_o_Saldo("la cedula");
    string linea;
    ifstream archivo;
    archivo.open(nombre_del_archivo);
    int numero_lineas_del_archivo= NumeroLineasArchivo(nombre_del_archivo);
    for(int numero_linea_actual=1; numero_linea_actual<numero_lineas_del_archivo; numero_linea_actual+=3){
        linea= leerUnaLinea(numero_linea_actual, nombre_del_archivo);
        linea= decodificarM2(linea, semilla);
        linea= convBinInt(linea);
        if(linea==cedula){
            numero_de_linea_cedula=numero_linea_actual;
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

char VerificarTamaño(){
    char respuesta= ' ';
    bool var_control=true;
    while(var_control){
        string verificar_tamaño;
        cin>> verificar_tamaño;
        if(verificar_tamaño.length() > 1){
            cout << "Solo puedes ingresar una letra: ";
        }else if (verificar_tamaño.length() ==1 && verificar_tamaño != "\n"){
            respuesta= verificar_tamaño[0];
            var_control=false;
        }
    }
    return respuesta;
}

bool VerificarSaldo(int& saldo_entero, int numero_linea_deseada, string nombreArchivo, int semilla){
    string saldo_string=leerUnaLinea(numero_linea_deseada, nombreArchivo);
    saldo_string= decodificarM2(saldo_string, semilla);
    saldo_string= quitarCeros(saldo_string);
    saldo_string= convBinInt(saldo_string);
    saldo_entero= stoi(saldo_string);
    if(saldo_entero< 1000){
        return false;
    }else{
        return true;
    }
}

void SobreEscribirUnaLinea(){

}

#endif // MENU_H
