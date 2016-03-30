/** Intr-un fisier text se pastreaza date referitoare
la imprimante. O imprimanta este caracterizata de:
model, pret_cartus, viteza.
Sa se decida care imprimanta are cartusele cele mai scumpe **/

#include <iostream>
#include <fstream>
using namespace std;

struct imprimanta
{
    char model[15];
    float pret;
    int viteza;
};

ifstream f("imp.txt");

int citireDate(imprimanta x[])
{
    int n = 0;
    while(!f.eof())
    {
        f.get(x[n].model, 15);
        f >> x[n].pret;
        f >> x[n].viteza;
        n++;
        f.get();
    }
    return n;
}

void afisareDate(imprimanta x[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cout << endl << x[i].model
             << " " << x[i].pret << " "
             << x[i].viteza;
}

imprimanta maximPret(imprimanta x[], int n)
{
    imprimanta maxim = x[0];
    int i;
    for(i = 1; i < n; i++)
        if(x[i].pret > maxim.pret)
            maxim = x[i];
    return maxim;
}

int main()
{
    imprimanta x[30], m;
    int n = citireDate(x);
    afisareDate(x, n);
    m = maximPret(x, n);
    cout << endl << "Pret maxim: "<< m.model;
    return 0;
}





