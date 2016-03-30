/** Intr-un fisier text se gasesc informatii despre telefoane mobile.
Fiecare telefon este identificat prin marca, pret, numar si provider.
Afisati cate telefoane dispun de abonament la un anumit provider
cunoscut. Afisati toate informatiile despre un telefon cand se cunoaste
numarul sau. **/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct telefon
{
    char marca[25];
    float pret;
    char numar[11];
    char provider[25];
};

void afisare(telefon v[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        cout << endl << v[i].marca;
        cout << "\t\a" << v[i].pret << "\t" << v[i].numar;
        cout << "\t" << v[i].provider;
    }
}

int cautare(telefon v[], int n, char p[])
{
    int i, k = 0;
    for(i = 0; i < n; i++)
        if(strcmp(v[i].provider, p)==0)
           k++;
    return k;
}

void afisare_telefon(telefon v[], int n, char num[])
{
    int i, k = 0;
    for(i = 0; i < n; i++)
        if(strcmp(v[i].numar, num)==0)
        {
           k = 1;
           cout << "\n"<<v[i].marca << v[i].pret << v[i].provider;
        }
    if(k == 0)
        cout << "nu exista telefonul cautat";
}

int main()
{
    telefon v[50]; int n = 0;
    char p[25], num[11];
    ifstream f("telefoane.txt");
    while(!f.eof())
    {
        f.get(v[n].marca, 25);
        f >> v[n].pret;
        f.get();
        f.get(v[n].numar, 11);
        f.get();
        f.get(v[n].provider, 25);
        f.get();
        n++;
    }
    afisare(v, n);
    cout << "\nprovider= "; cin.get(p, 25);
    cout << "contor = " << cautare(v, n, p);
    cout << "\nnumar = "; cin >> num;
    afisare_telefon(v, n, num);
    return 0;
}
