#include <iostream>
#include <string.h>

using namespace std;

int tamañoNumero(int numero);

int main()
{
    int numero; int nDigitos=0;
    cout<<"Ingrese un numero"; cin>>numero;
    nDigitos=tamañoNumero(numero);
    cout<<nDigitos;

}

int tamañoNumero(int numero){
    int digitos=0;
    if(numero==0){
        digitos+=1;
    }else{
        while(numero>0){
            numero=numero/10;
            digitos+=1;
        }
    }
    return digitos;
}
