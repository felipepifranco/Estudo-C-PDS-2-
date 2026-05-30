#include "Batmovel.hpp"

using namespace std;

int main() {
  Carro *batmovel2 = new BatMovel();
  cout << batmovel2->get_num_portas() << endl;
  batmovel2->acelerar();
  // batmovel2->acelerar_turbo();
  batmovel2->frear();

  cout << endl;

  MaquinaMisterio mm;
  mm.acelerar();
  mm.investigar();

  
  return 0;
}