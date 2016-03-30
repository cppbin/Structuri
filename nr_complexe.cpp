/** operatii asupra numerelor complexe **/

#include <iostream>
#include <math.h>
using namespace std;

struct nr_complex
{
    float re, im;
};

nr_complex citire(nr_complex Z)
{
    cout << "partea reala = "; cin >> Z.re;
    cout << "partea imaginara = "; cin >> Z.im;
    return Z;
}

void afisare(nr_complex Z)
{
    if(Z.im < 0)
        cout << Z.re << "+ i*(" << Z.im << ")";
    else cout << Z.re << "+ i*"<<Z.im;
}

nr_complex suma(nr_complex Z1, nr_complex Z2)
{
    nr_complex S;
    S.re = Z1.re + Z2.re;
    S.im = Z1.im + Z2.im;
    return S;
}

nr_complex diferenta(nr_complex Z1, nr_complex Z2)
{
    nr_complex S;
    S.re = Z1.re - Z2.re;
    S.im = Z1.im - Z2.im;
    return S;
}

nr_complex produs(nr_complex Z1, nr_complex Z2)
{
    nr_complex S;
    S.re = Z1.re*Z2.re - Z1.im*Z2.im;
    S.im = Z1.re*Z2.im + Z2.re*Z1.im;
    return S;
}

float modul(nr_complex Z)
{
    return sqrt(Z.re*Z.re + Z.im*Z.im);
}

nr_complex cat(nr_complex Z1, nr_complex Z2)
{
    nr_complex S;
    float r = modul(Z2);
    S.re = (Z1.re*Z2.re + Z1.im*Z2.im)/(r*r);
    S.im = (Z2.re*Z1.im - Z1.re*Z2.im)/(r*r);
    return S;
}

int main()
{
    nr_complex Z, W, R;
    cout << "primul numar complex:" << endl;
    Z = citire(Z);
    cout << "al doilea numar complex: " << endl;
    W = citire(W);
    cout << endl; afisare(Z);
    cout << endl; afisare(W);
    R = suma(Z, W);
    cout << endl << "Suma = "; afisare(R);
    R = diferenta(Z, W);
    cout << endl << "Diferenta = "; afisare(R);
    R = produs(Z, W);
    cout << endl << "Produsul = "; afisare(R);
    R = cat(Z, W);
    cout << endl << "Catul = "; afisare(R);
    return 0;
}




