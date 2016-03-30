/** Definiti structura care descrie un punct in plan
si calculati distanta euclidiana intre 2 puncte **/

#include <iostream>
#include <math.h>
using namespace std;

struct point
{
    float x, y;
};

point citire(point P)
{
    cout << ".x = "; cin >> P.x;
    cout << ".y = "; cin >> P.y;
    return P;
}

float distanta(point A, point B)
{
    float d;
    d = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
    return d;
}

point mijloc(point A, point B)
{
    point M;
    M.x = (A.x + B.x) / 2;
    M.y = (A.y + B.y) / 2;
    return M;
}

int main()
{
    point A, B, M, C;
    A = citire(A);
    B = citire(B);
    cout << "Distanta AB = " << distanta(A, B);
    M = mijloc(A, B);
    cout << endl << "Mijlocul seg. AB = ";
    cout << "("<<M.x<<", "<<M.y<<")";
    C.x = B.x;
    C.y = A.y;
    cout << endl << "Aria dreptunghiului ACBD = ";
    cout << distanta(A, C) * distanta(C, B);


    return 0;
}
