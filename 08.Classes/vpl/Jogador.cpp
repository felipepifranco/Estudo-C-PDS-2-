#include "Jogador.hpp"
#include <iostream>

Jogador::Jogador(std::string nome, char simbolo){
  this->nome = nome;
  this->simbolo = simbolo;
}

std::string Jogador::getNome() const{
  return this->nome;
}

char Jogador::getSimbolo() const{
  return this->simbolo;
}