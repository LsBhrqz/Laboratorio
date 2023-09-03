#include <iostream>

using namespace std;

int main()
{
    int numero=1, mayor=0;
    while (numero!=0){
        cout <<"Ingrese un numero: "; cin>> numero;
        if(numero>mayor){
            mayor=numero;
        }
        }
    cout <<"El numero mayor fue: " <<mayor<< endl;
}