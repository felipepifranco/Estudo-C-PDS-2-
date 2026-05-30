#include <iostream>
#include "Grid.hpp"
#include "Capybara.hpp"
#include "Jaguar.hpp"

int main() {
  // Leitura do grid inicial
  // Para cada célula, instancie o organismo correto e insira no grid
  
  int N, M, T;
  std::cin >> N >> M >> T;
  // N = número de linhas
  // M = número de colunas
  // T = número de turnos

  Grid grid(N, M);

  char simbolo;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      std::cin >> simbolo;
      if(simbolo == 'C')
        grid.set(new Capybara(j, i));
      else if(simbolo == 'O')
        grid.set(new Jaguar(j, i));
    }
  }
  // Loop de simulação — T turnos
  // A cada turno:
  //   1. resete a flag de movimento de todos os organismos
  //   2. todos os predadores agem primeiro
  //   3. todas as presas agem depois
  
  
  for(int turno=0; turno<T; turno++){
    std::cout << "----------------------------------" << std::endl << "Rodada " << turno +1 << std::endl;
    grid.resetMoved();
    std::cout << "----------------------------------" << std::endl << "Vez das oncas" << std::endl;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(grid.get(j, i) != nullptr && grid.get(j, i)->symbol() == 'O'){
          grid.get(j, i)->move(grid);
          std::cout << "(" << j << " " << i << ")" << std::endl << grid << std::endl;
        }
      }
    }
    std::cout << "----------------------------------" << std::endl << "Vez das capivaras" << std::endl;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(grid.get(j, i) != nullptr && grid.get(j, i)->symbol() == 'C'){
          grid.get(j, i)->move(grid);
          std::cout << "(" << j << " " << i << ")" << std::endl << grid << std::endl;
        }
      }
    }
    std::cout<< grid << std::endl;
  }

  std::cout<< grid << std::endl;

  return 0;
}