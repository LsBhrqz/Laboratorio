#include <iostream>
using namespace std;

int mcm(int n1, int auxiliar);
int main()
{
    int numero=0, r=0, Mcm=1, aux=0;
    cout<<"Ingrese un numero: ";cin>>numero;
        if(numero==2){
        Mcm=2;
    }
        for(int i=1; i<numero-1;i++){
            aux= i+1;
            r=mcm(i, aux);
            Mcm= mcm(r, aux+1);
    }
        cout<<Mcm<<endl;

}

int mcm(int n1, int auxiliar){
    int multiplicador1=1, n2=0, multiplicador2=1, multiplo1, multiplo2=0;
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
                return multiplo1;
            }
        }
    }
}
