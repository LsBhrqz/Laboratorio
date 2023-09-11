#include <iostream>
using namespace std;
char *funcionMultiplicador(char caracter, int multiplicador);

int main()
{

    int tamañoFigura=0, numeroEspacios=0, numeroFilas=0; char espacios=' ';
    char asteriscos='*' , *lineamayor= new char; int numeroAsteriscos=1;
    cout<<"Ingrese el tamaño de la figura: ";cin>>tamañoFigura;
            numeroEspacios=tamañoFigura/2; numeroFilas= tamañoFigura;
    do{
        char *linea= new char;
        char *lineap= new char;
        for(numeroEspacios;numeroEspacios>0;numeroEspacios-=1){
            linea= funcionMultiplicador(espacios,numeroEspacios);
            for(int control1=0;linea[control1]!='\0';control1++){
                cout<< linea[control1];
            }
            lineap=funcionMultiplicador(asteriscos,numeroAsteriscos);
            numeroAsteriscos+=2;
            for(int control2=0;lineap[control2]!='\0';control2++){
                cout<< lineap[control2];
            }cout<<endl;
        }
    }while(numeroAsteriscos<tamañoFigura-2);
    lineamayor= funcionMultiplicador(asteriscos, tamañoFigura);
    for(int control1=0;lineamayor[control1]!='\0';control1++){
        cout<< lineamayor[control1];
    } cout<<endl;
    do{
        numeroEspacios=1;
        char *linea= new char;
        char *lineap= new char;
        for(numeroEspacios;numeroEspacios<=tamañoFigura/2;numeroEspacios+=1){
            linea= funcionMultiplicador(espacios,numeroEspacios);
            for(int control1=0;linea[control1]!='\0';control1++){
                cout<< linea[control1];
            }
            numeroAsteriscos-=2;
            lineap=funcionMultiplicador(asteriscos,numeroAsteriscos);
            for(int control2=0;lineap[control2]!='\0';control2++){
                cout<< lineap[control2];
            }cout<<endl;
        }
    }while(numeroAsteriscos>0);

 }


char *funcionMultiplicador(char caracter, int multiplicador){
    char *linea= new char[multiplicador];
    int i=0;
    for(;i<multiplicador;i++){
        linea[i]= caracter;
    }
    linea[i]='\0';
    return linea;
}
