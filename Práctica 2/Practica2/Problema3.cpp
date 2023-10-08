#include <iostream>

using namespace std;

int main() {
    char cadena1[50], cadena2[50], limpiar=' ';

    for(int indice=0; indice<50; indice++){
        cadena1[indice]=limpiar; cadena2[indice]=limpiar;
    }
    bool comprobante=true;
    cout<<"Ingrese la primera cadena: ";cin.getline(cadena1,50);
    cout<<"Ingrese la segunda cadena: ";cin.getline(cadena2, 50);
    for(int i=0; i<50; i++){
        if(cadena1[i]!=cadena2[i]){
            comprobante= false;
        }
    }
    if(comprobante){
        cout<<"Las cadenas son iguales"<<endl;
    }else{
        cout<<"Las cadenas son diferentes"<<endl;
    }
}
