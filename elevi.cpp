#include <iostream>
using namespace std;

struct elev
{
    char nume[21];
    int nota1, nota2;
    float media;
};

void citireElevi(elev e[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        cin.get();
        cin.get(e[i].nume, 21);
        cin >> e[i].nota1;
        cin >> e[i].nota2;
    }
}

int construieste(elev e[], int n, elev en[])
{
    int i, j = 0;
    for(i = 0; i < n; i++)
        if(e[i].media >= 5)
        {
            en[j] = e[i];
            j++;
        }
    return j;
}

void afisareElevi(elev e[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cout << e[i].nume << " " << e[i].media;
}

int main()
{
    elev e[25], en[25];
    int i, n, j;
    cout << "n = "; cin >> n;
    citireElevi(e, n);
    for(i = 0; i < n; i++)
        e[i].media = (e[i].nota1 + e[i].nota2) / 2.0;
    j = construieste(e, n, en);
    afisareElevi(en, j);
    return 0;
}





