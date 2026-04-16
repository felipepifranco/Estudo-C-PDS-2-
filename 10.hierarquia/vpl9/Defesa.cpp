#include "Defesa.hpp"

Defesa::Defesa(int id, double energia) : _id(id), _energia(energia){}

void Defesa::_consumirEnergia(double qtd){
  this->_energia -= qtd;
  if(this->_energia < 0)
    this->_energia = 0;
}

double Defesa::GetEnergia(){
  return _energia;
}

Defesa::~Defesa() {
  std::cout << "Defesa " << this->_id << " desativada" << std::endl;
} 
