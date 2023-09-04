#include <iostream>

using namespace std;
bool esVocal(char);
bool esLetra(char);

int main(int argv, char *apuntador[])
{
    bool val1, val2;
        for(int c=0; c<argv;c++){
            char carac= *apuntador[c];
            val1=esLetra(carac);
            if (val1){
                val2= esVocal(carac);
                if (val2){
                    cout<<apuntador[c]<< " es una vocal"<<endl;
                }else{
                    cout<<apuntador[c]<< " es una consonante"<<endl;
                }

            }else{
                cout<<apuntador[c]<< " No es una letra"<<endl;
            }
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
