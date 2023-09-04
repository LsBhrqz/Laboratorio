#include <iostream>

using namespace std;
bool esprimo(int);

int main()
{
    int n1, n2, auxiliar, multiplicador1=1, multiplicador2=1, multiplo1, multiplo2=0;
    cout <<"Ingrese el primer numero: ";cin >>n1;
    cout <<"Ingrese el segundo numero: ";cin >>auxiliar;
    if (n1>auxiliar){
        n2=auxiliar;
    }else{
        n2=n1;
        n1=auxiliar;

    }auxiliar=1;
    while(auxiliar!=0){
        multiplo1=n1*multiplicador1;
        multiplicador1+=1;
        while(multiplo2<multiplo1){
            multiplo2=n2*multiplicador2;
            multiplicador2+=1;
            if(multiplo1==multiplo2){
                cout << "El MCM de "<<n1<<" y "<<n2<<" es: "<<multiplo1<<endl;
                auxiliar=0;
            }
        }
    }
}
