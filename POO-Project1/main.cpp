#include <iostream>

using namespace std;

class Carte {

   string titlu;
   string autor_p;
   string autor_s;
   int nr_pag;
   int pret;
   int rating;


 public:
      void citire();
      void afisare();

};

int main()
 {
     {


   Carte a;
   a.citire() ;
   a.afisare() ;


     }

   return 0;

 }
void Carte::citire(){cin >> titlu >> autor_p >> autor_s >> nr_pag >> pret >> rating;}
void Carte::afisare(){cout << " Titlul cartii este : " << titlu << " scrisa de " << autor_p ;}
