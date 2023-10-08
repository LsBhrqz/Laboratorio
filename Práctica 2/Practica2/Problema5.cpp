#include <iostream>

using namespace std;

int tamañoNumero(int numero);
void crearCadena(int tamaño, char* puntero, int numero);

int main(){
    int numero; int nDigitos=0;
    cout<<"Ingrese un numero: "; cin>>numero;
    nDigitos=tamañoNumero(numero);
    char arreglo[nDigitos+1];
    crearCadena(nDigitos, arreglo, numero);
    cout<<"'";for(int i=0; i<nDigitos; i++){ cout<<arreglo[i];} cout<<"'"<<endl;
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

void crearCadena(int tamaño, char* puntero, int numero){
    for(int i= tamaño-1; i>-1; i--){
        puntero[i]= '0' + numero%10;
        numero/=10;
    }
    puntero[tamaño]= '\0';
}