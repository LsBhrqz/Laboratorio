#include <iostream>
using namespace std;
bool esprimo(int numero);
int main()
{
    int numero=0, rfinal=0, constante=2, inicio=1, suma=1;
    cout<<"Ingrese el tamaño: "; cin>>numero;
        for(int i=0; i<(numero-1)/2 ;i++){
        for(int limite=0; limite<4; limite++){
            suma= inicio+constante;
            inicio=suma;
            rfinal+=suma;
            if(limite==3){
                constante+=2;
            }
        }
    }
    cout<<"El resultado de la suma es: "<<rfinal+1<<endl;
}
