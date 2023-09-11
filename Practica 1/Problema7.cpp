#include <iostream>
using namespace std;
int fibonacci(int limite);

int main()
{
    int numero=0, rfinal=0;
    cout<<"Ingrese un numero: "; cin>>numero;
    rfinal= fibonacci(numero);
    cout<<"El resultado de la suma es: "<<rfinal<<endl;
}

int fibonacci(int limite){
    int suma=0, aux=1, i=0, sumafinal=0;
    for(int inicial=1; suma<limite;){
        aux=inicial;
        inicial=suma;
        suma= aux+inicial;
        if (suma%2==0 and suma<limite){
            sumafinal+=suma;
        }
    }return sumafinal;
}