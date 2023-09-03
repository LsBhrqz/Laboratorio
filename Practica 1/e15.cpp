#include <iostream>

using namespace std;

int main()
{
    int numero=1, sumatoria=0;
    while (numero!=0){
        cout <<"Ingrese un numero: "; cin>> numero;
        sumatoria+=numero;
        }
    cout <<"El resultado de la sumatoria es: " <<sumatoria<< endl;
}