/** operatii asupra numerelor rationale **/

#include <iostream>
using namespace std;

struct fractie
{
    int n, m;
};

fractie citireFractie(fractie F)
{
    cout << "numarator = "; cin >> F.n;
    cout << "numitor = "; cin >> F.m;
    return F;
}

void afisareFractie(fractie F)
{
    if(F.m < 0)
        cout << F.n << "/(" << F.m<<")";
    else cout << F.n << "/" << F.m;
}

int cmmdc(int x, int y)
{
    if (x < 0)
        x = -x;
    if (y < 0)
        y = -y;

    while(x != y)
        if(x > y)
           x -= y;
        else
           y -= x;
    return x;
}

fractie simplifica(fractie S)
{
    int k = cmmdc(S.n, S.m);

        S.n /= k;
        S.m /= k;

    return S;
}

fractie suma(fractie F, fractie G)
{
    fractie S;
    S.n = F.n * G.m + G.n * F.m;
    S.m = F.m * G.m;
    S = simplifica(S);
    return S;
}

fractie diferenta(fractie F, fractie G)
{
    fractie S;
    S.n = F.n * G.m - G.n * F.m;
    S.m = F.m * G.m;
    S = simplifica(S);
    return S;
}

fractie produs(fractie F, fractie G)
{
    fractie S;
    S.n = F.n * G.n;
    S.m = F.m * G.m;
    S = simplifica(S);
    return S;
}

fractie cat(fractie F, fractie G)
{
    fractie S;
    S.n = F.n * G.m;
    S.m = F.m * G.n;
    S = simplifica(S);
    return S;
}

int main()
{
    fractie F, G, R;
    cout << "prima fractie: " << endl;
    F = citireFractie(F);
    cout << "a doua fractie: " << endl;
    G = citireFractie(G);

    R = suma(F, G);
    cout << endl << "Suma = "; afisareFractie(R);
    R = diferenta(F, G);
    cout << endl << "Diferenta = "; afisareFractie(R);
    R = produs(F, G);
    cout << endl << "Produsul = "; afisareFractie(R);
    R = cat(F, G);
    cout << endl << "Catul = "; afisareFractie(R);
    return 0;
}
