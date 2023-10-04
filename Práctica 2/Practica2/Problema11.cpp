#include <iostream>
#include <iomanip> // Necesario para formatear la salida

using namespace std;

void imprimirTabla(char (*saladecine)[20]);
bool comprobarDisponibilidad(int fila, int columna, char (*puntero)[20]);


int main() {
    char saladecine[15][20];
    int fila, columna;

    //  Inicio la sala de cine con todos los asientos disponibles
    for (int i = 0; i<15; i++) {
        for (int j = 0; j<20; j++) {
            saladecine[i][j]= '-';
        }
    }

    char (*psaladecine)[20]= saladecine;
    imprimirTabla(psaladecine);

    cout<<"Ingrese la fila de la silla que desea reservar: "; cin>>fila;
    cout<<"Ingrese la columna de la silla que desea reservar: "; cin>>columna;

    if(comprobarDisponibilidad(fila, columna, psaladecine)){
        saladecine[fila][columna]= '-';
    }else{
        cout<<"La silla está reservada. Elija otro asiento"<<endl;
    }
    imprimirTabla(psaladecine);
    return 0;
}

void imprimirTabla(char (*saladecine)[20]){
    for (int fila = 0; fila < 15; fila++) {
        for (int columna = 0; columna < 20; columna++) {
            // Usar setw para establecer un ancho fijo para cada elemento de la tabla
            cout<<setw(4)<< saladecine[fila][columna] << " ";
        }
        cout<<endl;
    }
}

bool comprobarDisponibilidad(int fila, int columna, char (*puntero)[20]){
    bool comprobante=false;
    if (puntero[fila][columna]=='-'){
        return comprobante;
    }else{
        comprobante= true;
        return comprobante;
    }
}
