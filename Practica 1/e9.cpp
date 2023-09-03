#include <iostream>

using namespace std;

int main()
{
    float radio,pi= 3.1416, perimetro=0, area=0;
    cout << "Ingrese el radio del circulo: "; cin >> radio;
    perimetro= 2*pi*radio;
    area=pi*(radio*radio);
    cout<<"Perimetro: "<< perimetro<< endl;
    cout<<"Area: "<< area<< endl;
    return 0;
}