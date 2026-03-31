#include "Processo.hpp"


Processo::Processo(int id, std::string nome, int prioridade){
  this->_id = id;
  this->_prioridade = prioridade;
  //BAIXA (0), MÉDIA (1), ALTA (2)
  this->_nome = nome;
  this->next = nullptr;
  this->prev = nullptr;
} 

int Processo::getID(){
  return this->_id;
} 

int Processo::getPrioridade() {
  return this->_prioridade;
}

std::string Processo::getNome(){
  return this->_nome;
} 

double Processo::tempo_reservado_processo(){
  if(this->_prioridade == 0)
    return 0.5;
  else if(this->_prioridade == 1)
    return 1.5;
  else if(this->_prioridade == 2)
    return 3.0;
  else
    return -1; // erro
}

void Processo::imprimir_dados(){
  std::cout << this->_id << "\t" << this->_nome << "\t";
  if(this->_prioridade == 0)
    std::cout << "BAIXA" << std::endl;
  else if(this->_prioridade == 1)
    std::cout << "MEDIA" << std::endl;
  else if(this->_prioridade == 2)
    std::cout << "ALTA" << std::endl;
  else
    std::cout << "ERRO" << std::endl;
}
