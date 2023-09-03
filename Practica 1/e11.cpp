#include <iostream>

using namespace std;

int main()
{
    int numero, resultado=0;
    cout <<"Ingrese un numero: "; cin>> numero;
    for(int i=1; i<11; i++){
        resultado= i*numero;
        cout <<i<<'x'<<numero<<"="<<resultado<< endl;
    }
}
