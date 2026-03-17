#include <iostream>
#include <cmath>
using namespace std;

struct Ponto3D{
  // dados/atributos:
  double x;
  double y;
  double z;

  // operações/métodos
  double calcularDistancia(Ponto3D* p2){
    double dx = p2->x - this->x; //ponteiro para a prórpia estrutura
    double dy = p2->y - this->y;
    double dz = p2->z - this->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
  }
};

int main() {
  Ponto3D* p1 = new Ponto3D();
  p1->x = 0.0;
  p1->y = 0.0;
  p1->z = 0.0;
  
  Ponto3D* p2 = new Ponto3D();
  p2->x = 5.0;
  p2->y = 5.0;
  p2->z = 5.0;
  
  cout << p1->calcularDistancia(p2) << endl;
  
  delete p1;
  delete p2;

  return 0;
}