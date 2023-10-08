#include <iostream>

using namespace std;

int main() {
    int numero=0; int arreglo[11]{0,0,0,0,0,0,0,0,0,0,0};
    cout<<"Ingrese la cantidad de dinero: "; cin >> numero;
    for(numero, arreglo; numero>0;){
        if(numero/50000){
            arreglo[0]+=1;
            numero-=50000;
        }else if(numero/20000){
            arreglo[1]+=1;
            numero-=20000;
        }else if(numero/10000){
            arreglo[2]+=1;
            numero-=10000;
        }else if(numero/5000){
            arreglo[3]+=1;
            numero-=5000;
        }else if(numero/2000){
            arreglo[4]+=1;
            numero-=2000;
        }else if(numero/1000){
            arreglo[5]+=1;
            numero-=1000;
        }else if(numero/500){
            arreglo[6]+=1;
            numero-=500;
        }else if(numero/200){
            arreglo[7]+=1;
            numero-=200;
        }else if(numero/100){
            arreglo[8]+=1;
            numero-=100;
        }else if(numero/50){
            arreglo[9]+=1;
            numero-=50;
        }else{
            arreglo[10]=numero;
            numero-=numero;
        }
    }
    cout<<"Combinaciones: "<<endl; cout<<"Billetes: "<<endl;
    cout<<"50000: "<< arreglo[0]<<endl; cout<<"20000: "<< arreglo[1]<<endl;
    cout<<"10000: "<< arreglo[2]<<endl; cout<<"5000: "<< arreglo[3]<<endl;
    cout<<"2000: "<< arreglo[4]<<endl; cout<<"1000: "<< arreglo[5]<<endl;
    cout<<"Monedas: "<<endl; cout<<"5000: "<< arreglo[6]<<endl;
    cout<<"200: "<< arreglo[7]<<endl; cout<<"100: "<< arreglo[8]<<endl;
    cout<<"50: "<< arreglo[9]<<endl; cout<< "Faltante: "<< arreglo[10]<<endl;
}
