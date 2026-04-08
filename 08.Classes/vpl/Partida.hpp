#ifndef PARTIDA_H
#define PARTIDA_H

#include "Tabuleiro.hpp"
#include "Jogador.hpp"

class Partida{
  private:
    Tabuleiro tabuleiro;
    Jogador jogador1;
    Jogador jogador2;
    Jogador* atual;
  public:
  Partida(Jogador jogador1, Jogador jogador2); // construtor, recebe nome define quem começa

  Jogador& getJogadorAtual(); // retorna o jogador

  void executarJogada(int linha, int coluna); // executa a jogada do jogador atual na posicao do tabuleiro seguindo a lógica:
  // se for válido: muda o tabuleiro
  // se não for válida, exibe "Jogada inválida!\n" e mantem a vez do msm jogador

  char statusPartida(); // retorna o estado consultando o tabuleiro. Os valores possíveis são 'X', 'O', 'E' ou 'P' (conforme definido em verificarEstadoPartida()).

  void exibirPartida(); //Exibe o estado atual do tabuleiro chamando o método imprimir() do tabuleiro
};

#endif