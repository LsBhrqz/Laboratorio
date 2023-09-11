#include <iostream>
using namespace std;
int convertirEnteros(const char*puntero);

int main()
{
    char *arreglo= new char; int dia=0, mes=0; bool val=true;
    cout<<"Ingrese una fecha dd/mm: "; cin >> arreglo;
    for(int i=0; arreglo[i]!='\0';i++){
        if(arreglo[i]=='/'){
            val=false;
            char *nvarreglo= new char[i];
            for(int u=0; u<i;u++){
                nvarreglo[u]=arreglo[u];
            }
            nvarreglo[i]= '\0';
            dia= convertirEnteros(nvarreglo);

            char *nvarreglo2= new char;
            int u=0;
            for(;arreglo[u+i+1]!='\0';u++){
                nvarreglo2[u]=arreglo[u+i+1];
            }
            nvarreglo2[u]= '\0';
            mes= convertirEnteros(nvarreglo2);
        }
    }if(val){
        mes= convertirEnteros(arreglo);
    }
    if(mes<=12 and mes>0){
        if(mes==1 or mes==3 or mes==5 or mes==7 or mes==8 or mes==10 or mes==12){
            if(dia<=31 and dia>0){
                cout<<dia<<"/"<<mes<<" es una fecha valida"<<endl;
            }else{
                cout<<dia<<"/"<<mes<<" es una fecha invalida"<<endl;
            }
        }else if(mes==4 or mes==6 or mes==9 or mes==11){
            if(dia<=30 and dia>0){
                cout<<dia<<"/"<<mes<<" es una fecha valida"<<endl;
            }else{
                cout<<dia<<"/"<<mes<<" es una fecha invalida"<<endl;
            }
        }else if(mes==2){
            if(dia<=28 and dia>0){
                cout<<dia<<"/"<<mes<<" es una fecha valida"<<endl;
            }else if(dia==29){
                cout<<dia<<"/"<<mes<<" es valida en bisiesto"<<endl;
            }else{
                cout<<dia<<"/"<<mes<<" es una fecha invalida"<<endl;
            }
        }else{
            if(dia==0){
                cout<<mes<<" es una fecha invalida"<<endl;
            }else{
                cout<<dia<<"/"<<mes<<" es una fecha invalida"<<endl;
            }

        }
    }else{
        if(dia==0){
            cout<<mes<<" es una fecha invalida"<<endl;
        }else{
            cout<<dia<<"/"<<mes<<" es una fecha invalida"<<endl;
        }
    }


}

int convertirEnteros(const char*puntero){
    int resultadofinal=0;
    for(int i=0; puntero[i]!='\0';i++){
        resultadofinal*=10;
        resultadofinal+=puntero[i]-'0';
    }
    return resultadofinal;
}
