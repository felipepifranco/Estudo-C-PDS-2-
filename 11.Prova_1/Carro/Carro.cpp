#include "Carro.hpp"

Carro::Carro(int num_portas) : _num_portas(num_portas) {}

void Carro::acelerar() {
  this->acionar_motor();
}

void Carro::frear() {
  this->acionar_discos_freio();
}

int Carro::get_num_portas() {
  return this->_num_portas;
}

void Carro::acionar_motor() {
  this->_motor.injetar_gasolina();
}

void Carro::acionar_discos_freio() {
  std::cout << "Acionando discos de freio." << std::endl;
}
