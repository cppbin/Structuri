#include <iostream>
#include <string.h>

using namespace std;

struct Medicament
{
    char denumire[30], recomandat[100];
    float pret;
};

void citireMedicamente(Medicament m[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        cin.get();
        cout << "Denumirea = "; cin.get(m[i].denumire, 30);
        cin.get();
        cout << "Recomandat = "; cin.get(m[i].recomandat, 100);
        cout << "Pret = "; cin >> m[i].pret;
    }
}

void afisareMedicamente(Medicament m[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cout << endl << m[i].denumire << " "
             << m[i].recomandat << "  " << m[i].pret;
}

int cautaMedicament(Medicament m[], int n, char x[])
{
    int i;
    for(i = 0; i < n; i++)
        if(strcmp(x, m[i].denumire) == 0)
            return i;
    return -1;

}

Medicament MinimPret(Medicament med[], int n)
{
    Medicament minim = med[0];
    int i;
    for(i = 1; i < n; i++)
        if(med[i].pret < minim.pret)
             minim = med[i];
    return minim;
}

int main()
{
   Medicament med[20];
   char x[30];
   int n;
   cout << "n = "; cin >> n;
   citireMedicamente(med, n);
   cout << endl << "Medicamente: " << endl;
   afisareMedicamente(med, n);
   cin.get();

   //1 - marirea cu 50% a pretului medicamentului x
   cout << endl << "Introduceti denumirea medicamentului cautat: ";
   cin.get(x, 30);
   int poz = cautaMedicament(med, n, x);
   if(poz != -1)
      med[poz].pret += 0.5*med[poz].pret;
   cout << "pretul modificat al medicamentului " << x <<" este "<< " " << med[poz].pret;

   //2 - micsorarea cu 3 ron a pretului medicamentului y
   char y[30];
   cin.get();
   cout << endl << "Introduceti numele medicamentului y: ";
   cin.get(y, 30);
   poz = cautaMedicament(med, n, y);
   if(poz != -1)
      med[poz].pret -= 3;
   afisareMedicamente(med, n);

   //3 - calcul TVA pentru medicamentul x
   poz = cautaMedicament(med, n, x);
   if (poz != -1)
   {
       cout << endl << "denumire = " << med[poz].denumire;
       float t = (float)24/100 * med[poz].pret;
       cout << endl << "TVA din x = " << t;
   }

    //4 - denumirea medicamentului cel mai ieftin
    Medicament m = MinimPret(med, n);
    cout << endl << "Medicamentul cel mai ieftin: " << m.denumire;
   return 0;
}
