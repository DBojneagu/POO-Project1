#include <iostream>

using namespace std;

class Joc {
  string nume;
  int an_aparitie;
  int ore_totale_de_joc;
  double rating;

  public:

    Joc() {
      nume = "Anonim";
      an_aparitie = 2022;
      ore_totale_de_joc = 0;
      rating = 0.5;
    };
  ~Joc() {
    delete this;
  };
  Joc & operator = (Joc & j);

  friend istream & operator >> (istream & in , Joc & j) {
    cout << "Supraincarcare citire " << endl; in >> j.nume >> j.an_aparitie >> j.ore_totale_de_joc >> j.rating;
    cout << endl;

    return in;
  }
  friend ostream & operator << (ostream & out,
    const Joc & j) {
    out << "Supraincarcare afisare" << endl << "Nume : " << j.nume << endl << "An Aparitie : " << j.an_aparitie << endl << "Numar ore de joc : " << j.ore_totale_de_joc << endl << "rating : " << j.rating << endl << endl;
    return out;
  }

  void set_nume(Joc & j);
  void set_an_aparitie(Joc & j);
  void set_ore_totale_de_joc(Joc & j);
  void set_rating(Joc & j);

  void afis_nume(Joc & j);
  void afis_an_aparitie(Joc & j);
  void afis_ore_totale_de_joc(Joc & j);
  void afis_rating(Joc & j);

};

int main() {

  Joc A;

  Joc C;
  cin >> A;
  C = A;
  cout << A;
  cout << C;

  Joc B;

  B.afis_nume(B);

  B.set_an_aparitie(B);
  B.afis_an_aparitie(B);

  B.afis_ore_totale_de_joc(B);

  B.afis_rating(B);

  return 0;
}

void Joc::afis_nume(Joc & j) {
  cout << "Nume: " << j.nume << endl;
}
void Joc::afis_an_aparitie(Joc & j) {
  cout << "An Aparitie: " << j.an_aparitie << endl;
}
void Joc::afis_ore_totale_de_joc(Joc & j) {
  cout << "Numar ore totale de joc : " << j.ore_totale_de_joc << endl;
}
void Joc::afis_rating(Joc & j) {
  cout << "rating :  " << j.rating << endl;
}

void Joc::set_nume(Joc & j) {
  cout << "Nume " << endl;
  cin >> j.nume;
}
void Joc::set_an_aparitie(Joc & j) {
  cout << "An Aparitie " << endl;
  cin >> j.an_aparitie;
}
void Joc::set_ore_totale_de_joc(Joc & j) {
  cout << "Numar ore totale de joc: " << endl;
  cin >> j.ore_totale_de_joc;
}
void Joc::set_rating(Joc & j) {
  cout << "rating " << endl;
  cin >> j.rating;
}

Joc & Joc::operator = (Joc & j) {
  if (this != & j) {
    cout << "operator de atribuire explicit: ";
    nume = j.nume;
    an_aparitie = j.an_aparitie;
    ore_totale_de_joc = j.ore_totale_de_joc;
    rating = j.rating;

  }
  return *this;
}
