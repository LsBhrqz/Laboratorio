#include <iostream>

using namespace std;

int main()
{
    int numero, resultado=0;
    cout << "Ingrese un numero: "; cin >> numero;
    for(int i=0;i<numero+1;i++){
        resultado+=i;
    }
    cout << "la sumatoria de 0 hasta "<<numero<<" es: "<<resultado<< endl;
    return 0;
}