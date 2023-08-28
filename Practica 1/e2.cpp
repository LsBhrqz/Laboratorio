#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Ingrese N: ";
    cin >> n;
    cout << n << "Es ";
    if (n%2==0){
        cout << "par \n";
    }
    else{
        cout << "impar \n";
    }
    return 0;
}
