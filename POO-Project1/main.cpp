#include <iostream>

using namespace std;

class Student {
  string nume;
  int an_nastere;
  int numar_credite;
  double media_generala;

  public:

    Student() {
      nume = "Anonim";
      an_nastere = 2022;
      numar_credite = 0;
      media_generala = 0.5;
    };
  ~Student() {
    delete this;
  };
  Student & operator = (Student & s);

  friend istream & operator >> (istream & in , Student & s) {
    cout << "Supraincarcare citire " << endl; in >> s.nume >> s.an_nastere >> s.numar_credite >> s.media_generala;
    cout << endl;

    return in;
  }
  friend ostream & operator << (ostream & out,
    const Student & s) {
    out << "Supraincarcare afisare" << endl << "Nume : " << s.nume << endl << "An nastere : " << s.an_nastere << endl << "Numar credite : " << s.numar_credite << endl << "Media Generala: " << s.media_generala << endl << endl;
    return out;
  }

  void set_nume(Student & s);
  void set_an_nastere(Student & s);
  void set_numar_credite(Student & s);
  void set_media_generala(Student & s);

  void afis_nume(Student & s);
  void afis_an_nastere(Student & s);
  void afis_numar_credite(Student & s);
  void afis_media_generala(Student & s);

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

  Student A;

  Student C;
  cin >> A;
  C = A;
  cout << A;
  cout << C;

  Student B;

  B.afis_nume(B);

  B.set_an_nastere(B);
  B.afis_an_nastere(B);

  B.afis_numar_credite(B);

  B.afis_media_generala(B);

  return 0;
}

void Student::afis_nume(Student & s) {
  cout << "Nume: " << s.nume << endl;
}
void Student::afis_an_nastere(Student & s) {
  cout << "An nastere: " << s.an_nastere << endl;
}
void Student::afis_numar_credite(Student & s) {
  cout << "Numar credite: " << s.numar_credite << endl;
}
void Student::afis_media_generala(Student & s) {
  cout << "Media Generala: " << s.media_generala << endl;
}

void Student::set_nume(Student & s) {
  cout << "Nume " << endl;
  cin >> s.nume;
}
void Student::set_an_nastere(Student & s) {
  cout << "An Nastere " << endl;
  cin >> s.an_nastere;
}
void Student::set_numar_credite(Student & s) {
  cout << "Numar credite: " << endl;
  cin >> s.numar_credite;
}
void Student::set_media_generala(Student & s) {
  cout << "Medie Generala " << endl;
  cin >> s.media_generala;
}

Student & Student::operator = (Student & s) {
  if (this != & s) {
    cout << "operator de atribuire explicit: ";
    nume = s.nume;
    an_nastere = s.an_nastere;
    numar_credite = s.numar_credite;
    media_generala = s.media_generala;

  }
  return *this;
}
