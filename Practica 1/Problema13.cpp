#include <iostream>
using namespace std;
bool esprimo(int numero);
int main()
{
    int numero=0, rfinal=0; bool val=0;
    cout<<"Ingrese un numero: "; cin>>numero;
    for(int i=2; i<numero ;i++){
        val=esprimo(i);
        if(val){
            rfinal+=i;
        }
    }
    cout<<"El resultado de la suma es: "<<rfinal<<endl;
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

