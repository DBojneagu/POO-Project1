#include <iostream>

#include <vector>

#include <string>

using namespace std;

class Joc {
  string nume;
  int ore_totale_de_joc;

  public:

    Joc(string, int);

  Joc() {
    nume = "Anonim";
    ore_totale_de_joc = 0;
  };

  string getName() const;
  int getHours() const;

  friend istream & operator >> (istream & in , Joc & j) {
    cout << "Introduceti numele : "; in >> j.nume;
    cout << "Introduceti numarul total de ore de joc : "; in >> j.ore_totale_de_joc;
    cout << endl;

    return in;
  }

  friend ostream & operator << (ostream & out,
    const Joc & j) {
    out << "Game Name : " << j.nume << endl << "Total Game Hours : " << j.ore_totale_de_joc << endl;
    return out;
  }

  friend void fillVector(vector < Joc > & );
  friend void printVector(const vector < Joc > & );
};

void fillVector(vector < Joc > & );

void printVector(const vector < Joc > & );

int main() {
  int choice;

  vector < Joc > myClass;

  do {
    cout << "Salut! Ce doresti sa faci mai departe?" << endl << "1. Incarca jocurile " << endl << "2. Afiseaza Jocurile" << endl << "3. Iesi din program" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      fillVector(myClass);
      break;
    case 2:
      printVector(myClass);
      break;
    case 3:
      return 0;

    }

  }
  while (choice != 3);

}

void fillVector(vector < Joc > & newMyClass) {
  Joc aux;

  cout << " Introduceti numarul total de jocuri : ";
  int classSize;
  cin >> classSize;

  for (int i = 0; i < classSize; i++) {
    cin >> aux;

    Joc newJoc(aux.nume, aux.ore_totale_de_joc);
    newMyClass.push_back(newJoc);
    cout << endl;
  }
  cout << endl;
}

Joc::Joc(string name, int hours) {
  nume = name;
  ore_totale_de_joc = hours;

}

void printVector(const vector < Joc > & newMyClass) {

  unsigned int size = newMyClass.size();

  for (unsigned int i = 0; i < size; i++) {
    cout << "--------Game number " << i + 1 << "----------" << endl << newMyClass[i] << endl;

  }
}

string Joc::getName() const {
  return nume;
}

int Joc::getHours() const {
  return ore_totale_de_joc;
}
