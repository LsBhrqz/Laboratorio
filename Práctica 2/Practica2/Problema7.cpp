#include <iostream>

using namespace std;

int main() {
    //Creo un arreglo que finalmente tenga el tamaño suficiente para contener lo que se ingresó por consola
    int posActual=0; const int tam= 64; int tamBuffer=tam;
    char* frase_ingresada= new char[tam];char c;
    cout<<"Ingrese la cadena de caracteres: ";
    while(cin.get(c) && c!= '\n'){
        frase_ingresada[posActual]=c;
        posActual++;
        if(posActual==tamBuffer-1){
            tamBuffer*=2;
            char* nuevoarreglo= new char[tamBuffer];
            copy(frase_ingresada,frase_ingresada+posActual,nuevoarreglo);
            delete[] frase_ingresada;
            frase_ingresada=nuevoarreglo;
        }
    }
    //Me aseguro de que al final vaya el caracter nulo
    frase_ingresada[posActual]='\0';

    //Creo un nuevo arreglo con sus correspondientes variables
    int longitud_nueva_frase;
    char nueva_frase[tamBuffer];
    bool verificar=false;

    //Me aseguro de que el nuevo arreglo sólo tenga el caracter nulo
    for(int i=0; i<tamBuffer; i++){
        nueva_frase[i]= '\0';
    }

    //Verifico si cada carcater de la cadena ingresada está en la nueva cadena y si no lo está la agrego
    for(int i=0; i<posActual;i++){
        c= frase_ingresada[i];
        verificar=false;
        for(int j=0; j<longitud_nueva_frase; j++){
            if(c==nueva_frase[j]){
                verificar=true;
                break;
            }
        }

        if(!verificar){
            nueva_frase[longitud_nueva_frase]= c;
            longitud_nueva_frase++;
        }
    }

    cout<<"Cadena sin letras repetidas: "<< nueva_frase<<endl;

    delete[] frase_ingresada;

    return 0;
}
