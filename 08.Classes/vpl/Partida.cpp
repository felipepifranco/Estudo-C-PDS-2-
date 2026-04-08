#include "Partida.hpp"
#include "Jogador.hpp"


Partida::Partida(Jogador jogador1, Jogador jogador2): jogador1(jogador1), jogador2(jogador2){  
  
  this->atual = &this->jogador1;
}

Jogador& Partida::getJogadorAtual(){
  return *(this->atual);
}

void Partida::executarJogada(int linha, int coluna){
  if(this->tabuleiro.validaJogada(linha, coluna, this->atual->getSimbolo() ) ){
    this->tabuleiro.fazerJogada(linha, coluna, this->atual->getSimbolo());
    //troca o jogador da vez
    if(this->atual == &(this->jogador1))
      this->atual = &(this->jogador2);
    else 
      this->atual = &(this->jogador1);
  }
  else{
    std::cout << "Jogada invalida!\n" ;
  }
}

char Partida::statusPartida(){
  return this->tabuleiro.verificaEstadoPartida();
}

void Partida::exibirPartida(){
  this->tabuleiro.imprimir();
}