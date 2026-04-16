#include <iostream>

using namespace std;

class Pessoa {
  public:
    string nome;
    
    Pessoa() {
      cout << "Pessoa()" << endl;
    }
};

class Estudante : public Pessoa {
  public:
    int matricula;
    
    Estudante() {
      cout << "Estudante()" << endl;
    }
};

int main() {
  Estudante e;
  return 0;
}