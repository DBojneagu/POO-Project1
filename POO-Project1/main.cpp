#include <iostream>

using namespace std;

class Joc {
  string nume;
  int an_aparitie;
  int numar_credite;
  double media_generala;

  public:

    Joc() {
      nume = "Anonim";
      an_aparitie = 2022;
      numar_credite = 0;
      media_generala = 0.5;
    };
  ~Joc() {
    delete this;
  };
  Joc & operator = (Joc & j);

  friend istream & operator >> (istream & in , Joc & j) {
    cout << "Supraincarcare citire " << endl; in >> j.nume >> j.an_aparitie >> j.numar_credite >> j.media_generala;
    cout << endl;

    return in;
  }
  friend ostream & operator << (ostream & out,
    const Joc & j) {
    out << "Supraincarcare afisare" << endl << "Nume : " << j.nume << endl << "An Aparitie : " << j.an_aparitie << endl << "Numar credite : " << j.numar_credite << endl << "Media Generala: " << j.media_generala << endl << endl;
    return out;
  }

  void set_nume(Joc & j);
  void set_an_aparitie(Joc & j);
  void set_numar_credite(Joc & j);
  void set_media_generala(Joc & j);

  void afis_nume(Joc & j);
  void afis_an_aparitie(Joc & j);
  void afis_numar_credite(Joc & j);
  void afis_media_generala(Joc & j);

};

class Grupa {

  int nr_studenti;
  double media_grupei;
  Grupa();
  ~Grupa();
  public:

  void elim_student();
  void add_student();
  void check_by_name();

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

  B.afis_numar_credite(B);

  B.afis_media_generala(B);

  return 0;
}

void Joc::afis_nume(Joc & j) {
  cout << "Nume: " << j.nume << endl;
}
void Joc::afis_an_aparitie(Joc & j) {
  cout << "An Aparitie: " << j.an_aparitie << endl;
}
void Joc::afis_numar_credite(Joc & j) {
  cout << "Numar credite: " << j.numar_credite << endl;
}
void Joc::afis_media_generala(Joc & j) {
  cout << "Media Generala: " << j.media_generala << endl;
}

void Joc::set_nume(Joc & j) {
  cout << "Nume " << endl;
  cin >> j.nume;
}
void Joc::set_an_aparitie(Joc & j) {
  cout << "An Aparitie " << endl;
  cin >> j.an_aparitie;
}
void Joc::set_numar_credite(Joc & j) {
  cout << "Numar credite: " << endl;
  cin >> j.numar_credite;
}
void Joc::set_media_generala(Joc & j) {
  cout << "Medie Generala " << endl;
  cin >> j.media_generala;
}

Joc & Joc::operator = (Joc & j) {
  if (this != & j) {
    cout << "operator de atribuire explicit: ";
    nume = j.nume;
    an_aparitie = j.an_aparitie;
    numar_credite = j.numar_credite;
    media_generala = j.media_generala;

  }
  return *this;
}
