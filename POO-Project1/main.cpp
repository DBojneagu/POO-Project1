
#include <iostream>

using namespace std;

class Student {
      string nume ;
      int an_nastere ;
      int numar_credite ;
      double media_generala ;

  public :


     Student() { nume = "Anonim" ; an_nastere = 2022; numar_credite = 0; media_generala = 0.5 ;};

    friend istream & operator >> (istream & in, Student & s)

    {
        cout << "Supraincarcare citire " << endl;
        in >> s.nume >> s.an_nastere >> s.numar_credite >> s.media_generala  ;
        cout << endl ;

        return in;
    }

    friend ostream & operator << (ostream & out , const Student & s)
        {
            out <<  "Supraincarcare afisare" << endl << "Nume : " << s.nume << endl << "An nastere : " << s.an_nastere << endl << "Numar credite : "  << s.numar_credite << endl << " Media Generala: "  << s.media_generala << endl << " " ;
            return out;
        }



    int nr_studenti;
    double media_grupei ;
    Grupa();
    ~Grupa();
   public :

} ;


class Grupa {

    int nr_studenti;
    double media_grupei ;
    Grupa();
    ~Grupa();
   public :

    void elim_student();
    void add_student();
    void check_by_name();

};

int main() {

    Student A;
    cin >> A;
    cout << A;
    return 0 ;
}


