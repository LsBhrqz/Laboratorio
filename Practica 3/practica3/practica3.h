#ifndef PRACTICA3_H
#define PRACTICA3_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;

bool comprobarLectura(){
    ifstream archivo;
    archivo.open("sudo.txt");
    if(!archivo){
        cerr << "No se puede abrir el archivo para lectura" << endl;
        return false;
    }else{
        cout << "Verificacion exitosa" <<endl;
        return true;
    }
}

string leerUnaLinea(){
    string linea;
    ifstream archivo;
    archivo.open("sudo.txt");
    getline(archivo, linea);
    archivo.close();
    return linea;
}
void verificacionAdministrador(){
    string contraseña_ingresada ="", contraseña_guardada="";
    cin >> contraseña_ingresada;
    contraseña_guardada= leerUnaLinea();
}


//Aplicar funciones con lectura archivo
//Decodificar correctamente (dejando las banderas)
//Todo va a devolver un string
//Documentación


//Esta función decodifica bajo el método uno



//Esta función decodifica bajo el método dos



/*Esta función recibe una de esas cadenas de bits, luego toma por bloques y decodifica cada caracter,
añadiendolo al string que representa esa cadena de bits*/
string convBinInt(string linea){
    string recibido = "";
    int len = linea.length();
    int residuo = len % 8;
    int index = 0;
    for(int i = 0; i <= (len - residuo); i += 8){
        string sublinea = linea.substr(i, i + 8);
        int entero = 0;
        for(int j = i; j < 8; j++){
            int aux = sublinea[-j];
            aux = aux * (pow(2,j));
            entero += aux;
        }
        recibido += char(entero);
        index++;
    }
    return recibido;

}

//Esta función recibe el arreglo de caracteres que va a convertir en números binarios
void convIntBin(char *linea, int ent){
    for (int i = 7; i >= 0; i--) {
        linea[i] = (ent % 2) + '0';
        ent = ent / 2;
    }
    linea[8] = '\0';
}


//Esta función aplica las reglas del método 1 de codificación
void aplicarReglas(string &grupo, string &grupoAnterior){

    int unosAnterior = 0, cerosAnterior = 0;

    for (char bit : grupoAnterior){
        if (bit == '1'){
            unosAnterior++;
        } else{
            cerosAnterior++;
        }
    }

    if (unosAnterior == cerosAnterior){

        for (char &bit : grupo){
            bit = (bit == '1') ? '0' : '1';
        }
    } else if (unosAnterior > cerosAnterior){

        for (int i = 2; i < grupo.length(); i += 3){
            grupo[i] = (grupo[i] == '1') ? '0' : '1';
        }
    } else{

        for (int i = 1; i < grupo.length(); i += 2){
            grupo[i] = (grupo[i] == '1') ? '0' : '1';
        }
    }
}


//Esta función se encarga de codificar bajo el segundo método
void codificarM2(string &cadena, int n){
    int longitud = cadena.length();
    string resultado = "";

    for (int i = 0; i < longitud; i += n){
        string grupo = cadena.substr(i, n);

        char ultimoBit = grupo[n - 1];
        for (int j = n - 2; j >= 0; j--){
            grupo[j + 1] = grupo[j];
        }
        grupo[0] = ultimoBit;

        resultado += grupo + " ";
    }

    resultado += " 1";

    cout << "El archivo codificado es: " << resultado << endl;
}


//Esta función se encarga de codificar bajo el primer método
void codificarM1(string &cadena, int n){
    int longitud = cadena.length();
    string resultado = "";

    string primerBloque = cadena.substr(0, n);

    for (char &bit : primerBloque) {
        bit = (bit == '1') ? '0' : '1';
    }
    resultado += primerBloque + " ";

    string grupoAnterior = primerBloque;

    for (int i = n; i < longitud; i += n) {
        string grupo = cadena.substr(i, n);
        aplicarReglas(grupo, grupoAnterior);
        resultado += grupo + " ";
        grupoAnterior = cadena.substr(i, n);
    }

    resultado += " 0";
    cout << "El archivo codificado es: " << resultado << endl;

}

int principal(){
    char lecturaConsola[90];
    cout << "Ingrese la línea: " << endl;
    cin.getline(lecturaConsola, 90, '\n');
    int longitud = strlen(lecturaConsola);

    char lineaBin[720] = "";

    for (int i = 0; i < longitud; i++) {
        char aux[9];
        convIntBin(aux, lecturaConsola[i]);
        strcat(lineaBin, aux);
    }

    cout << "El archivo en binario es: " << lineaBin << endl;

    string lineaBinString = lineaBin;

    string entregado = convBinInt(lineaBinString);

    cout << entregado;

    /*

    int n;
    cout << "Ingrese el tamaño del bloque para la codificación: ";
    cin >> n;



    if(lineaBinString.length() < n){
        for(int x = lineaBinString.length(); x < n ; x++)
            lineaBinString += "0";
    }

    if((lineaBinString.length() % n) != 0){
        for(int x = (lineaBinString.length()%n); x < n ; x++)
            lineaBinString += "0";
    }


    codificarM1(lineaBinString, n);
    codificarM2(lineaBinString, n);
*/

return 0;
}
#endif // PRACTICA3_H
