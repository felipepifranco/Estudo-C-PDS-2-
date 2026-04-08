#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

class Tabuleiro{
  private:
    char tabuleiro[3][3]; // armazena cada celula, que pode ser 'X', 'O', ' '
    int tamanhoTabuleiro = 3;
  public:
    Tabuleiro();

    bool validaJogada(int linha, int coluna, char simbolo); // verifica se é válida a jogada, ou seja:
    // posição da jogada ta no limite
    // simbolo é x ou o
    // a posição jogada está vazia

    void fazerJogada(int linha, int coluna, char simbolo); // registra jogada

    char verificaEstadoPartida(); // ve se alguem ganhou ou está empatado

    void imprimir();
};

#endif