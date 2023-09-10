#include <iostream>
using namespace std;

int main()
{
    float numero1=0, numero2=0, resultado=0; char operacion; bool val=true;
    while(val){
        cout <<"Ingrese un numero: "; cin >>numero1;
        cout <<"Ingrese una operacion (+-/*): "; cin >>operacion;
        cout << "Ingrese otro numero: "; cin >>numero2;
    if(operacion=='+'){
        resultado= numero1+numero2;
        cout <<numero1<<"+"<<numero2<<"="<<resultado<<endl;
        val=false;
    }else if(operacion=='-'){
        resultado= numero1-numero2;
        cout <<numero1<<"-"<<numero2<<"="<<resultado<<endl;
        val=false;
    }else if(operacion=='*'){
        resultado= numero1*numero2;
        cout <<numero1<<"*"<<numero2<<"="<<resultado<<endl;
        val=false;
    }else if(operacion=='/'){
        resultado= numero1/numero2;
        cout <<numero1<<"/"<<numero2<<"="<<resultado<<endl;
        val=false;
    }else{
        cout<<"Ingresaste una operacion no valida"<<endl;

    }
    }
    return 0;
}
