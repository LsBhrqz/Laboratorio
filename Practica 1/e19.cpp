#include <iostream>

using namespace std;
bool esprimo(int);

int main()
{
    int numero;
    bool valor;
    cout <<"Ingrese un numero: "; cin>> numero;
    valor= esprimo(numero);
    if (valor){
        cout<<numero<<" es un numero primo"<< endl;
    }else{
        cout<<numero<<" NO es un numero primo"<<endl;
    }
}

bool esprimo(int numero){
    if (numero==1)
        return false;
    else if (numero==2){
        return true;
        }
    else if(numero%2==0){
        return false;
    }
    for(int i=3; i*i<=numero;i+=2){
        if(numero%i==0){
            return false;
        }else{
            return true;
        }
    }
}