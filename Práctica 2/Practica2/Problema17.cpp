#include <iostream>

using namespace std;
int SumaDeDivisores(int &numero);

int main(){
    int limite, numero2, suma_numeros_amigos=0, suma_divisores_num2;
    cout<<"Ingrese un numero limite : "; cin>>limite;

    for(int numero1=220; numero1<limite; numero1++){
        numero2= SumaDeDivisores(numero1);
        suma_divisores_num2= SumaDeDivisores(numero2);
        if(suma_divisores_num2==numero1 && numero1!=numero2){
            suma_numeros_amigos+= numero1;
        }
    }
    if(suma_numeros_amigos==0){
        cout<<"No hay numeros amigos menores al numero ingresado"<<endl;
    }else{
        cout<<"La suma de los numeros amigos menores que "<<limite<<" es "<< suma_numeros_amigos<<endl;
    }

}

int SumaDeDivisores(int &numero){
    int suma=0;
    for(int i=1; i<=numero/2; i++){
        if(numero%i==0){
            suma+=i;
        }
    }
    return suma;
}
