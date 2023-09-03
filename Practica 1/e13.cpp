#include <iostream>

using namespace std;

int main()
{
    int numero, resultado=0;
    cout <<"Ingrese un numero: "; cin>> numero;
    cout<< "Los divisores de "<<numero<<" son: "<< endl;
    cout <<1<<endl;
    for(int i=2;i<numero;i++){
        resultado=numero%i;
        if(resultado==0){
            cout <<i<<endl;
        }
    }
    cout << numero<< endl;
}