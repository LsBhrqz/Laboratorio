#include <iostream>
using namespace std;
bool esVocal(char);
bool esLetra(char);

int main()
{
    char carac;
    cout<<"Ingrese una letra: "; cin >>carac;
    bool val1, val2;
    val1=esLetra(carac);
    if (val1){
        val2= esVocal(carac);
        if (val2){
            cout<<carac<< " es una vocal"<<endl;
        }else{
            cout<<carac<< " es una consonante"<<endl;
        }
    }else{
        cout<<carac<< " No es una letra"<<endl;
    }
}

bool esLetra(char caracter){
    if (caracter<=90 and caracter>=65){
        return true;
    }else if(caracter>=97 and caracter<=122){
        return true;
    }
    else{
        return false;
    }
}
bool esVocal(char caracter){
    bool val=false;
    char vocales[10]= {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for(int i=0; i<10;i++){
        if (caracter==vocales[i]){
            val=true;
        }
    }return val;

}
