#include "Tabuleiro.hpp"
#include <iostream>

Tabuleiro::Tabuleiro(){
  for(int i =0; i< 3; i++){
    for(int j=0; j<3; j++){
      this->tabuleiro[i][j] = ' ';
    }
  }
}

bool Tabuleiro::validaJogada(int linha, int coluna, char simbolo){
  if(linha <0 || linha >2 || coluna < 0 || coluna > 2){
    return false;
  }
  else if( simbolo != 'X' && simbolo != 'O'){
    return false;
  }
  else if( this->tabuleiro[linha][coluna] != ' '){ 
    return false;
  }
  // se não é nenhum dos casos invalidos, a jogada é válida:
  else 
    return true;
}

void Tabuleiro::fazerJogada(int linha, int coluna, char simbolo){
  this->tabuleiro[linha][coluna] = simbolo;
}

char Tabuleiro::verificaEstadoPartida(){
  int& tam = this->tamanhoTabuleiro;
  bool ganhou = false;
  // analisando linhas
  for(int i=0; i<tam; i++){
    ganhou = true;
    for(int j=0; j<(tam-1); j++){
      if(this->tabuleiro[i][j] == ' '){
        ganhou = false;
        break; // vai pra próxima linha
      }
      if(this->tabuleiro[i][j] != this->tabuleiro[i][j+1]){
        ganhou = false;
        break; // vai pra próxima linha
      }
    }
    if(ganhou) return this->tabuleiro[i][0];
  }

  // analisando colunas
  for(int i=0; i<tam; i++){
    ganhou = true;
    for(int j=0; j<(tam-1); j++){
      if(this->tabuleiro[j][i] == ' '){
        ganhou = false;
        break; // vai pra próxima linha
      }
      if(this->tabuleiro[j][i] != this->tabuleiro[j+1][i]){
        ganhou = false;
        break; // vai pra próxima linha
      }
    }
    if(ganhou) return this->tabuleiro[0][i];
  }

  // analisando as diagonais
  ganhou = true;
  for(int i=0; i<tam-1; i++){
    if(this->tabuleiro[i][i] != this->tabuleiro[i+1][i+1] || this->tabuleiro[i][i] == ' '){
      ganhou = false;
      break;
    }
  }
  if(ganhou) return this->tabuleiro[0][0];

  int auxiliar = 0;
  ganhou =true; // diagonal secundária
  for(int i=0; i<tam-1; i++){
    auxiliar = tam-(i+1);
    if(this->tabuleiro[i][auxiliar] != this->tabuleiro[i+1][auxiliar-1] || this->tabuleiro[i][auxiliar] == ' '){
      ganhou = false;
      break;
    }
  }
  if(ganhou) return this->tabuleiro[0][tam-1];

  for(int i=0; i<tam; i++){
    for(int j=0; j<tam; j++){
      if(this->tabuleiro[i][j] == ' '){
        return 'P';
        }
      }
  }

  return 'E';
}

void Tabuleiro::imprimir(){
  for (int i = 0; i < 3; i++) {
    std::cout << " " << tabuleiro[i][0] << " | "
      << tabuleiro[i][1] << " | "
      << tabuleiro[i][2] << "\n";
    if (i < 2)
      std::cout << "-----------\n";
    }
}