#include <iostream>
using namespace std;

int main()
{
    char simbolo='-'; int limiteinferior=0, limitesuperior=100, numero=50;
    cout <<"Piense en un numero del 0 al 100"<<endl;
    do{
        cout<< "¿Es mayor o menor que "<< numero<<"?"<<endl;
        cout << "Ingrese <,> o = segun sea el caso: ";cin>>simbolo;
        if (simbolo=='<'){
            limitesuperior=numero; numero= (limiteinferior+limitesuperior)/2;
        }else if(simbolo=='>'){
            limiteinferior=numero; numero=(limiteinferior+limitesuperior)/2;
        }
    }while(simbolo != '=');
    cout<<"Usted penso en el "<<numero<<endl;
    return 0;
}
