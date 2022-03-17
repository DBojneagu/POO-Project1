#include <iostream>

#include <vector>

#include <string>

using namespace std;

class Joc {
  string nume;
  string game_engine;
  string nume_companie;
  string gen_joc;
  int ore_totale_de_joc;
  double rating;

  public:

    Joc(string, string, string, string, int, double);

  Joc() {
    nume = "Anonim";
    ore_totale_de_joc = 0;
  };

  string getName() const;
  int getHours() const;

  friend istream & operator >> (istream & in , Joc & j) {
    cout << "Introduceti numele : "; in >> j.nume;
    cout << "Introduceti game engine-ul : "; in >> j.game_engine;
    cout << "Introduceti numele companiei : "; in >> j.nume_companie;
    cout << "Introduceti genul jocului : "; in >> j.gen_joc;
    cout << "Introduceti numarul total de ore de joc : "; in >> j.ore_totale_de_joc;
    cout << "Introduceti rating-ul jocului : "; in >> j.rating;
    cout << endl;

    return in;
  }

  friend ostream & operator << (ostream & out,
    const Joc & j) {
    out << "Numele jocului : " << j.nume << endl << "Game Engine-ul Jocului : " << j.game_engine << endl << "Numele Companiei : " << j.nume_companie << endl << "Genul Jocului : " << j.gen_joc << endl << "Numar total ore de joc " << j.ore_totale_de_joc << endl << "Rating : " << j.rating << endl;
    return out;
  }

  friend void fillVector(vector < Joc > & );
  friend void printVector(const vector < Joc > & );
};

void fillVector(vector < Joc > & );

void printVector(const vector < Joc > & );

void RemoveLastGame(vector <Joc> &);

void RecomandaJoc();

void Shooter();
void Shooter_Multiplayer();
void Shooter_Singleplayer();
void Moba();
void Adventure();

int Menu();

int Menu() {

    int choice;

  vector < Joc > myClass;

  do {
    cout << "Salut! Ce doresti sa faci mai departe?" << endl << "1. Incarca jocurile " << endl << "2. Afiseaza Jocurile" << endl << "3. Sterge ultimul joc " << endl << "4. Lasa sa-ti recomand un joc!" << endl << "5. Iesi din Program" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      fillVector(myClass);
      break;
    case 2:
      printVector(myClass);
      break;
    case 3:
      RemoveLastGame(myClass);
      break;
    case 4:
      RecomandaJoc();

    case 5:
        return 0;

    }

  }
  while (choice != 5);
}
int main() {

  Menu();

}

void fillVector(vector < Joc > & newMyClass) {
  Joc aux;

  cout << " Introduceti numarul total de jocuri : ";
  int classSize;
  cin >> classSize;

  for (int i = 0; i < classSize; i++) {
    cin >> aux;

    Joc newJoc(aux.nume, aux.nume_companie, aux.game_engine, aux.gen_joc, aux.ore_totale_de_joc, aux.rating);
    newMyClass.push_back(newJoc);
    cout << endl;
  }
  cout << endl;
}

void RemoveLastGame(vector <Joc> & newMyClass)
{
    newMyClass.pop_back();
}

Joc::Joc(string name, string nume_comp, string engine_joc, string gen, int hours, double rating_) {
  nume = name;
  nume_companie = nume_comp;
  game_engine = engine_joc;
  gen_joc = gen;
  ore_totale_de_joc = hours;
  rating = rating_;
}

void printVector(const vector < Joc > & newMyClass) {

  unsigned int size = newMyClass.size();

  for (unsigned int i = 0; i < size; i++) {
    cout << "--------Game number " << i + 1 << "----------" << endl << newMyClass[i] << endl;

  }
}

void RecomandaJoc(){
    cout << "Iti voi adresa o serie de intrebari, iar pe baza acestor raspunsuri iti voi recomanda un joc!" << endl  << "Pentru inceput : Ce gen de jocuri preferi? " << endl << "1.Shooter " << endl << "2. Moba " << endl << "3. Adventure " << endl;
    int choice;
    cin >> choice;
    switch(choice){
case 1 :
    Shooter();
    break;
//case 2:
  //  Moba();
//case 3:
  //  Adventure();

    }
}

void Shooter(){
   cout << "Shooter sa inteleg, buna alegere! Ai dorii ca acesta sa fie multiplayer sau singleplayer?" << endl << "1. Multiplayer" << endl << "2. SinglePlayer" << endl;
   int choice;
   cin >> choice ;
   switch(choice) {
   case 1:
       Shooter_Multiplayer();
       break;
   case 2:
       Shooter_Singleplayer();
       break;
   }
}

void Shooter_Singleplayer(){
    cout << "Iti recomand jocul : Halo " << endl << endl  << "Numele jocului : Halo "  << endl << "Game Engine-ul Jocului : Halo: Combat Evolved " << endl << "Numele Companiei : Bungie Inc " <<  endl << "Genul Jocului : Shooter "  << endl << "Numar total ore de joc : 10 ore " <<  endl << "Rating : 8.7 "  << endl << endl;
    Menu();

}

void Shooter_Multiplayer(){
    cout << "Iti recomand jocul : Call of Duty" << endl << endl ;
    Menu();
    }

string Joc::getName() const {
  return nume;
}

int Joc::getHours() const {
  return ore_totale_de_joc;
}
