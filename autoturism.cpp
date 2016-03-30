/** Dată fiind structura autoturism (numar_inmatriculare, tip, model,
km_parcursi) realizați un program C++ care citește date despre autoturisme
dintr-un fișier text și
apoi afișează autoturismul cu cei mai puțini
kilometri parcurși. **/

#include <iostream>
#include <fstream>

using namespace std;

struct autoturism
{
    char nr[8];
    char tip[15];
    char model[15];
    int km;
};

autoturism minimkm(autoturism a[], int n)
{
    int i;
    autoturism minim = a[0];
    for(i = 1; i < n; i++)
        if(a[i].km < minim.km)
            minim = a[i];
    return minim;
}

int main()
{
    autoturism a[50];
    ifstream f("auto.txt");
    int n = 0;
    while(!f.eof())
    {
        f.get(a[n].nr, 8);
        f.get();
        f.get(a[n].tip, 15);
        f.get();
        f.get(a[n].model, 15);
        f >> a[n].km;
        n++;
        f.get();
    }
    int i;
    for(i = 0; i < n; i++)
        cout << a[i].nr << " " << a[i].tip << " "
        << a[i].model << " " << a[i].km << endl;

    autoturism m = minimkm(a, n);
    cout << "Model= " << m.model << " Tip = "
          << m.tip << "  Km = " << m.km;
    return 0;
}
