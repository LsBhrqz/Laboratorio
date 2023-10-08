/*#include <iostream>

using namespace std;

int tamañoNumero(int numero);
void llenarCadena(char arreglo[], int numero, int Tamaño);

int main()
{
    int numero; int nDigitos=0;
    cout<<"Ingrese un numero: "; cin>>numero;
    nDigitos=tamañoNumero(numero);
    char arreglo[nDigitos];
    cout<<char(1)<<endl;
    llenarCadena(arreglo, numero, nDigitos);
    cout<<"'";
    for(int i=0;i<nDigitos; i++){
        cout<<arreglo[i];
    }
    cout<<"'";
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

void llenarCadena(char arreglo[], int numero, int Tamaño){
    for(int i=-1; i>=-Tamaño; i--){
        arreglo[i]= char(numero%10);
        numero/=10;
    }
}
*/
