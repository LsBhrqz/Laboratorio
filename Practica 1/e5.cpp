#include <iostream>

using namespace std;

int main()
{
    float A, B, C;
    int D;
    cout << "Ingrese el valor de A: "; cin >> A;
    cout << "Ingrese el valor de B: "; cin >> B;
    C= A/B;
    D=C;

    if ((C-D)>0.5){
        D += 1;
    }
    cout << D << endl;

    return 0;
}