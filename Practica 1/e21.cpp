#include <iostream>

using namespace std;
bool esprimo(int);

int main()
{
    char letra;
    bool val=true;
    while(val){
        cout << "Ingrese una letra del abecedario: "; cin >>letra;
        if (letra <=90 and letra>=65){
            letra+=32;
            cout <<"Letra convertida: "<< letra<< endl;
            val=false;
        }
        else if(letra>=97 and letra<=122){
            letra-=32;
            cout <<"Letra convertida: "<< letra<< endl;
            val=false;
        }else{
            cout << "Ingresaste un caracter no valido"<< endl;
        }
    }

}