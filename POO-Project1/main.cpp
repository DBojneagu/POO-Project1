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
    nume_companie = "Anonim";
    gen_joc = "Anonim";
    rating = 0;
  };

  string getName();
  string getGame_engine();
  string getNume_Companie();
  string getGen_Joc();
  int getHours();
  double getRating();

  void setName(string n) {
    nume = n;
  }
  void setGame_engine(string g) {
    game_engine = g;
  }
  void setNume_Companie(string nc) {
    nume_companie = nc;
  }
  void setGen_Joc(string g) {
    gen_joc = g;
  }
  void setHours(int h) {
    ore_totale_de_joc = h;
  }
  void setRating(double r) {
    rating = r;
  }

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

void RemoveLastGame(vector < Joc > & );

void RecomandaJoc(vector < Joc > & );

void Shooter(vector < Joc > & );
void Shooter_Multiplayer(vector < Joc > & );
void Shooter_Singleplayer(vector < Joc > & );
void Moba(vector < Joc > & );
void Moba_Multiplayer(vector < Joc > & );
void Moba_Singleplayer(vector < Joc > & );
void Adventure(vector < Joc > & );
void Adventure_Multiplayer(vector < Joc > & );
void Adventure_Singleplayer(vector < Joc > & );

int Menu(vector < Joc > myClass) {

  int choice;

  do {
    cout << "Salut! Ce doresti sa faci mai departe?" << endl << "1. Incarca jocurile " << endl << "2. Afiseaza Jocurile" << endl << "3. Sterge ultimul joc " << endl << "4. Lasa sa-ti recomand un joc!" << endl << "5. Iesi din program" << endl << endl;
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
      RecomandaJoc(myClass);
      break;
    case 5:
      return 0;

    }

  }
  while (choice != 5);
}
int main() {

  vector < Joc > myClass;
  Menu(myClass);

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

void RemoveLastGame(vector < Joc > & newMyClass) {
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

void RecomandaJoc(vector < Joc > & myClass) {
  cout << "Iti voi adresa o serie de intrebari, iar pe baza acestor raspunsuri iti voi recomanda un joc!" << endl << "Pentru inceput : Ce gen de jocuri preferi? " << endl << "1.Shooter " << endl << "2. Moba " << endl << "3. Adventure " << endl;
  int choice;
  cin >> choice;
  switch (choice) {
  case 1:
    Shooter(myClass);
    break;
  case 2:
    Moba(myClass);
    break;
  case 3:
    Adventure(myClass);
    break;

  }
}

void Shooter(vector < Joc > & myClass) {
  cout << "Shooter sa inteleg, buna alegere! Ai dorii ca acesta sa fie multiplayer sau singleplayer?" << endl << "1. Multiplayer" << endl << "2. SinglePlayer" << endl;
  int choice;
  cin >> choice;
  switch (choice) {
  case 1:
    Shooter_Multiplayer(myClass);
    break;
  case 2:
    Shooter_Singleplayer(myClass);
    break;
  }
}

void Moba(vector < Joc > & myClass) {
  cout << "Moba sa inteleg, buna alegere! Ai dorii ca acesta sa fie multiplayer sau singleplayer?" << endl << "1. Multiplayer" << endl << "2. SinglePlayer" << endl;
  int choice;
  cin >> choice;
  switch (choice) {
  case 1:
    Moba_Multiplayer(myClass);
    break;
  case 2:
    Moba_Singleplayer(myClass);
    break;
  }
}

void Adventure(vector < Joc > & myClass) {
  cout << "Adventure sa inteleg, buna alegere! Ai dorii ca acesta sa fie multiplayer sau singleplayer?" << endl << "1. Multiplayer" << endl << "2. SinglePlayer" << endl;
  int choice;
  cin >> choice;
  switch (choice) {
  case 1:
    Adventure_Multiplayer(myClass);
    break;
  case 2:
    Adventure_Singleplayer(myClass);
    break;
  }
}

void Shooter_Singleplayer(vector < Joc > & myClass ) {
  cout << "Iti recomand jocul : Halo " << endl << endl << "Numele jocului : Halo " << endl << "Game Engine-ul Jocului : Halo: Combat Evolved " << endl << "Numele Companiei : Bungie Inc " << endl << "Genul Jocului : Shooter " << endl << "Numar total ore de joc : 10 ore " << endl << "Rating : 8.7 " << endl << endl;
  Menu(myClass);

}

void Shooter_Multiplayer(vector < Joc > & myClass) {
  cout << "Iti recomand jocul : Call of duty 4 " << endl << endl << "Numele jocului : Call of duty 4 " << endl << "Game Engine-ul Jocului : Unreal " << endl << "Numele Companiei : Activision Blizard " << endl << "Genul Jocului : Shooter " << endl << "Numar total ore de joc : 13 ore " << endl << "Rating : 9.3 " << endl << endl;
  Menu(myClass);
}

void Moba_Singleplayer(vector < Joc > & myClass) {
  cout << "Iti recomand jocul : Dota 2 " << endl << endl << "Numele jocului : Dota 2  " << endl << "Game Engine-ul Jocului : Source 2" << endl << "Numele Companiei : Valve " << endl << "Genul Jocului : Moba " << endl << "Numar total ore de joc : 1800 ore " << endl << "Rating : 9 " << endl << endl;
  Menu(myClass);

}
void Moba_Multiplayer(vector < Joc > & myClass) {
  cout << "Iti recomand jocul : League Of Legends " << endl << endl << "Numele jocului : League Of Legends " << endl << "Game Engine-ul Jocului : Unity" << endl << "Numele Companiei : Riot Games " << endl << "Genul Jocului : Moba " << endl << "Numar total ore de joc : 2000 ore " << endl << "Rating : 7.8 " << endl << endl;
  Menu(myClass);
}

void Adventure_Singleplayer(vector < Joc > & myClass) {
  cout << "Iti recomand jocul : The Witcher 3 " << endl << endl << "Numele jocului : The Witcher 3  " << endl << "Game Engine-ul Jocului : REDEngine" << endl << "Numele Companiei : CD Projekt Red " << endl << "Genul Jocului : Adventure " << endl << "Numar total ore de joc : 50 ore " << endl << "Rating : 9.3 " << endl << endl;
  Menu(myClass);

}
void Adventure_Multiplayer(vector < Joc > & myClass) {
  cout << "Iti recomand jocul : Minecraft " << endl << endl << "Numele jocului : Minecraft " << endl << "Game Engine-ul Jocului : Lightweight Java Game Library" << endl << "Numele Companiei : Mojang Studios " << endl << "Genul Jocului : Adventure " << endl << "Numar total ore de joc : 90 " << endl << "Rating : 8.1 " << endl << endl;
  Menu(myClass);
}

string Joc::getName() {
  return nume;
}

string Joc::getGame_engine() {
  return game_engine;
}

string Joc::getGen_Joc() {
  return gen_joc;
}

string Joc::getNume_Companie() {
  return nume_companie;
}

int Joc::getHours() {
  return ore_totale_de_joc;
}

double Joc::getRating() {
  return rating;
}
