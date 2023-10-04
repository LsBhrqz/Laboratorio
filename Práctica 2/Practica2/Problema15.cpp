#include <iostream>

using namespace std;

int contadorDeEstrellas(int (*puntero)[8]);

int main()
{
    int galaxia[6][8]= {{0,3,4,0,0,0,6,8},{5,13,6,0,0,0,2,3},{2,6,2,7,3,0,10,0},
    {0,0,4,15,4,1,6,0},{0,0,7,12,6,9,10,4},{5,0,6,10,6,4}};
    int numeroEstrellas=0;
    int (*puntero)[8]= galaxia;
    numeroEstrellas= contadorDeEstrellas(puntero);
    cout<<"El numero de estrellas es: "<<numeroEstrellas<<endl;
}

int contadorDeEstrellas(int (*puntero)[8]){
    int numeroestrellas=0; int *punteroestrellas= &numeroestrellas;
    float suma=0, dividendo=0;
    for(int i=1; i<5;i++){
        for(int j=1; j<7;j++){
            dividendo= puntero[i][j]+puntero[i][j-1]+puntero[i][j+1]+puntero[i-1][j]+puntero[i+1][j];
            suma= dividendo/5.0;
            if(suma>6){
                *punteroestrellas+=1;
            }
        }
    }

    return numeroestrellas;
}

