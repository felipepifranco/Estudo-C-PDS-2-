#include "Batmovel.hpp"

void Turbina::ligar_turbo() {
  std::cout << "Ligando turbo." << std::endl;
}

BatMovel::BatMovel() : Carro(1) {}

void BatMovel::acelerar_turbo() {
  this->acelerar();
  this->acionar_turbina();
}

void BatMovel::frear(){
  std::cout << "Acionando freios especiais." << std::endl;
}

void BatMovel::acionar_turbina() {
  this->_turbina.ligar_turbo();
}


MaquinaMisterio::MaquinaMisterio() : Carro(3){
  this->pistas = 0;
}

void MaquinaMisterio::investigar(){
  pistas ++;
  std::cout << "Nova pista encontrada! Agora temos: " << pistas << std::endl;
}

void MaquinaMisterio::acelerar() {
  std::cout << "Indo atras dos monstros!" << std::endl;
}

