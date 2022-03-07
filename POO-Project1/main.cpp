#include <iostream>

using namespace std;

/******************* constructori si destructori ********************/
/*** Orice clasa are IMPLICIT un constructor de initializare, un constructor
de copiere, un operator de atribuire si un destructor ***/

class Carte
{
    string titlu;
    string autor_principal;
    string autor_secundar;
    int pagini;
    int pret;
    int rating;
public:
    void citire();
    void afisare();
};

int main()
{
    {
        Carte c1;   /// orice clasa are, by defaut, constructor de initializare
        c1.citire();
        c1.afisare();

        Carte c2 = c1;  /// orice clasa are, by defaut, constructor de copiere
        c2.afisare();

        Carte c3(c1);  /// orice clasa are, by defaut, constructor de copiere
        c3.afisare();

        Carte c4;
        c4 = c1;  /// orice clasa are, by defaut, operator de atribuire (=)
        c4.afisare();
    }
    /// orice clasa are, by default, un destructor
      /// cand nu mai e nevoie de obiecte, se distrug automat,
    /// de aceea c1 nu mai e recunoscut dupa ce compilatorul termina blocul {}
    return 0;
}

void Carte::citire(){cin>>titlu>>pret>>rating;}
void Carte::afisare(){cout<<titlu<<" "<<pret<<" "<<rating<<"\n";}
