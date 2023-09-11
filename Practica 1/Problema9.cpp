#include <iostream>
using namespace std;
int numeroDigitos( int numero);
int potenciador(int a, int b);

int main()
{
    int numero=0, nvnumero=0, digitos=0, resultado=0, aux=0;
    int residuo=0, rpotencias=0;
    cout<<"Ingrese un numero: "; cin>>numero;
    digitos= numeroDigitos(numero);
   do{
        aux= potenciador(10, digitos-1);
        nvnumero= numero/aux;
        residuo= numero%aux;
        rpotencias= potenciador(nvnumero,nvnumero);
        resultado+=rpotencias;
        digitos-=1;
        numero=residuo;
    }while(digitos>0);
   cout <<resultado<<endl;
}

int numeroDigitos( int numero){
    int nvnumero=0, digitos=0;
    do{
        nvnumero=numero/10;
        numero=nvnumero;
        digitos+=1;

    }while(nvnumero>0);
    return digitos;
}

int potenciador(int a, int b){
    signed int potencia = 1;
    int valor = potencia;
    while (potencia <= b) {
        valor = valor*a;
        potencia += 1;
    }
    return valor;
}