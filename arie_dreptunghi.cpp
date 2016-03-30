/** aria dreptunghiului identificat
    de doua puncte diagonal opuse cunoscute **/

#include <iostream>
#include <math.h>
using namespace std;

struct point
{
    float x, y;
};

point citire(point P)
{
    cout << "P.x = "; cin >> P.x;
    cout << "P.y = "; cin >> P.y;
    return P;
}

float distanta(point A, point B)
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

int main()
{
    point A, C, B;
    A = citire(A);
    C = citire(C);
    B.x = A.x;
    B.y = C.y;
    cout << "Aria = " << distanta(A, B) * distanta(B, C);
    return 0;

}
