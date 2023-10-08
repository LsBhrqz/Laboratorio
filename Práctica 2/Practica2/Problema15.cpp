#include <iostream>

using namespace std;
void imprimirArreglo(int arreglo[]);

int main() {
    int arreglo1[4]={0,0,8,4};
    int arreglo2[4]={5,2,6,7};
    int interseccion[4]={0,0,0,0};
    int x=0,y=1, w=2,h=3;

    cout<<"El arreglo 1 es: {";imprimirArreglo(arreglo1);cout<<"}"<<endl;
    cout<<"El arreglo 2 es: {";imprimirArreglo(arreglo2);cout<<"}"<<endl;

    //Primero comparo si los arreglos son iguales
    if(arreglo1[x]==arreglo2[x] && (arreglo1[x]+arreglo1[w] == arreglo2[x]+ arreglo2[w]) ){
        if(arreglo1[y]==arreglo2[y] && (arreglo1[y]+arreglo1[h] == arreglo2[y]+ arreglo2[h])){
            interseccion[x]= arreglo1[x];interseccion[y]= arreglo1[y];
            interseccion[w]= arreglo1[w];interseccion[h]= arreglo1[h];
            cout<< "Las figuras son iguales"<<endl;
        } 
    }else{
        //En este caso puede que haya una parte dentro de otra o que no haya interseccion

        //Comparo las x
        if((arreglo1[x] >= arreglo2[x])){
            //Determino la que está más a la derecha
            interseccion[x]=arreglo1[x];

            //Verifico si la interseccion no existe
            if((arreglo2[x] + arreglo2[w]) <= arreglo1[x]){
                cout<<"La interseccion no existe"<<endl;

            //Las x de una figura están dentro de la otra
            }else if(arreglo1[x]+arreglo1[w] <= arreglo2[x]+arreglo2[w]){
                interseccion[w]= arreglo1[x]+arreglo1[w]-interseccion[x];

            //Una x está dentro de una figura
            }else{
                interseccion[w]=arreglo2[x]+arreglo2[w]-interseccion[x];
            }

        }else{

            //Determino la que está más a la derecha
            interseccion[x]=arreglo2[x];

            //Verifico si la interseccion no existe
            if((arreglo1[x]+ arreglo1[w])<= arreglo2[x]){
                cout<<"La interseccion no existe"<<endl;

            //Las x de una figura están dentro de la otra
            }else if(arreglo2[x]+arreglo2[w] <= arreglo1[x]+arreglo1[w]){
                interseccion[w]= arreglo2[x]+arreglo2[w]-interseccion[x];

            //Una x está dentro de la figura
            }else{
                interseccion[w]=arreglo1[x]+arreglo1[w]-interseccion[x];
            }
        }

        //Despues comparo las y
        if((arreglo1[y] >= arreglo2[y])){

            //Determino la y que está más abajo
            interseccion[y]=arreglo2[y];

            //Evaluo si no existe la intersecion
            if((arreglo1[y] + arreglo1[h]) <= arreglo2[y]){
                cout<<"La interseccion no existe"<<endl;

            //Las y están dentro de la otra figura
            }else if( (arreglo1[y] + arreglo1[h]) >= (arreglo2[y] + arreglo2[h]) ){
                interseccion[h]= arreglo2[y] + arreglo2[h] - interseccion[y];

            //Unas y están dentro de ula otra figura
            }else{
                interseccion[h]= arreglo1[y] + arreglo1[h] - interseccion[y];
            }

        }else{

            //Determino la y que está más abajo
            interseccion[y]=arreglo1[y];

            //Evaluo si no existe la intersecion
            if((arreglo2[y] + arreglo2[h]) <= arreglo1[y]){
                cout<<"La interseccion no existe"<<endl;

                //Las y están dentro de la otra figura
            }else if( (arreglo2[y] + arreglo2[h]) >= (arreglo1[y] + arreglo1[h]) ){
                interseccion[h]= arreglo1[y] + arreglo1[h] - interseccion[y];

                //Unas y están dentro de ula otra figura
            }else{
                interseccion[h]= arreglo2[y] + arreglo2[h] - interseccion[y];
            }
        }
    }

    cout<<"El arreglo de la interseccion es: {";imprimirArreglo(interseccion);cout<<"}"<<endl;

}

void imprimirArreglo(int arreglo[]){
    for(int i=0; i<4; i++){
        if(i==3){
            cout<<arreglo[i];
        }else{
            cout<<arreglo[i]<<", ";
        }
    }
}
