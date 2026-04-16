#include "BaseMilitar.hpp"
#include <iomanip>

BaseMilitar::BaseMilitar() : _qtdAtual(0){}

void BaseMilitar::adicionarDefesa(Defesa *d){
  this->_defesas[this->_qtdAtual] = d;
  this->_qtdAtual ++;
}

void BaseMilitar::defender(double &saudeInimigo){
  double dano =0;
  for(int i=0; i< this->_qtdAtual; i++){
    this->_defesas[i]->atacar(dano);
  }

  saudeInimigo -= dano;
  std::cout << "Saude Inimigo: " << std::fixed << std::setprecision(2) << saudeInimigo << std::endl;
}

BaseMilitar::~BaseMilitar(){
  for(int i=0; i<this->_qtdAtual; i++){
    delete this->_defesas[i];
  }
}