
#include <iostream>

using namespace std;

class Student {
      string nume ;
      int an_nastere ;
      int numar_credite ;
      double media_generala ;
      Student();
      ~Student();
  public :
    friend istream& operator>>(istream &i, Student&s);
    friend ostream& operator<<(ostream &o, Student&s);
    void afis_nume();
    void afis_an_nastere();
    void afis_numar_credite();
    void afis_media_generala();
    void afis_student();


};

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


  return 0 ;
}

istream& operator>>(istream &i, Student&s)
{
    i >> s.nume >> s.an_nastere >> s.numar_credite >> s.media_generala ;
    return i;
}

ostream& operator<<(ostream &o, Student&s)
{
    o << s.nume << s.an_nastere << s.numar_credite << s.media_generala ;
}
