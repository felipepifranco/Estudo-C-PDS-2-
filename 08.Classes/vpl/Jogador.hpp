#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>

class Jogador{
  private:
    std::string nome; // nome do jogador
    char simbolo; // X ou O

  public:
    Jogador(std::string nome, char simbolo);

    std::string getNome() const;

    char getSimbolo() const;
};

#endif