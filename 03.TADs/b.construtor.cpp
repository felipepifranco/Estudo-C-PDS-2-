#include <iostream>

struct Ponto3D {
  double x;
  double y;
  double z;

  Ponto3D(double a) { // CONSTRUTOR
    this->x = -1.0;
    this->y = a;
    this->z = -1.0;
  }
};

// Chamando um construtor
int main() {
  Ponto3D* p = new Ponto3D(2);
  // os valores já são atribuidos
  std::cout << p->x << std::endl << p->y << std::endl << p->z << std::endl;
  return 0;
  }