#include <iostream>
#include <string>
using namespace std;

int convertirStr_Int(string cadena, int longitud);

int main() {
    int num=0;
    int n;
    string cadena;

    cout << "Ingrese un numero n: "; cin >> n;
    cout << "Ingrese una cadena de caracteres numericos: ";cin >> cadena;

    //Almaceno el tamaño de la cadena
    int longitud = cadena.length();
    int suma = 0;

    // Verifico si hacen falta números y si es así agrego ceros a la izquierda
    while (longitud % n != 0) {
        cadena = "0" + cadena;
        longitud++;
    }

    // Separar la cadena en números de n cifras, sumarlos e imprimir el resultado
    for (int i = 0; i < longitud; i += n) {
        string numStr = cadena.substr(i, n);
        num = convertirStr_Int(numStr, n);
        suma += num;
    }

    cout <<"Suma: "<< suma << endl;

    return 0;
}

int convertirStr_Int(string cadena, int longitud){
    int numero=0;
    for(int i=0; i<longitud; i++){
        numero+= cadena[i]-'0';
        if(i!=longitud-1){
            numero*=10;
        }
    }
    return numero;
}