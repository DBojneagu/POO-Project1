#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Joc {
  string nume;
  int ore_totale_de_joc;

  public:

    Joc(string,int);

    Joc() {
      nume = "Anonim";
      ore_totale_de_joc = 0;
    };

    string getName() const;
    int getHours() const;
};

void fillVector(vector<Joc>&);


void printVector(const vector<Joc>&);


int main() {

   vector<Joc> myClass;

   fillVector(myClass);
   printVector(myClass);

   return 0;
}

void fillVector(vector<Joc>& newMyClass) {
    string name;
    int hours;

    cout << " Introduceti numarul total de jocuri : " ;
    int classSize;
    cin >> classSize ;

    for (int i = 0;i < classSize; i++){
        cout << "Enter Game Name : ";
        cin >> name ;
        cout << "Enter total hours : " ;
        cin >> hours ;


        Joc newJoc(name, hours);
        newMyClass.push_back(newJoc);
        cout << endl;
    }
    cout << endl;
}

Joc::Joc(string name, int hours){
    nume = name ;
    ore_totale_de_joc = hours ;

}

void printVector(const vector<Joc>& newMyClass) {

    unsigned int size = newMyClass.size();

    for ( unsigned int i = 0; i < size; i++) {
            cout << "Game Number " << i + 1 << endl ;
            cout << "Game name : " << newMyClass[i].getName() << endl;
            cout << "Total hours of gameplay : " << newMyClass[i].getHours() << endl;
            cout << endl ;

    }
}

string Joc::getName() const {
       return nume;
}

int Joc :: getHours () const {
       return ore_totale_de_joc;
}

