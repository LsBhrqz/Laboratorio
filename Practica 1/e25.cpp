#include <iostream>
using namespace std;

int main()
{
    int numero=0, nvnumero=0, digitos=0, copia=0;
    cout <<"Ingrese un numero: "; cin >>numero;
    copia=numero;
    do{
        nvnumero=numero/10;
        numero=nvnumero;
        digitos+=1;

    }while(nvnumero>0);
    cout <<copia<<" tiene "<<digitos<<" digitos"<<endl;
}