#include "Jaguar.hpp"
#include "Grid.hpp"

Jaguar::Jaguar(int x, int y) : Organism(x, y){}

char Jaguar::symbol() const{
  // std::cout << "poggers2" << std::endl;
  return 'O';
}

bool Jaguar::tryPredation(Grid& grid){  
  if(moved) return false;
  if( grid.inBounds(x, y-1) &&
      !grid.isEmpty(x, y-1) && 
      grid.get(x, y-1)->isPreyFor(this)
    ){ // cima
      grid.remove(x, y-1);
      deslocar(grid,x,y-1);
      return true;
    } 
  
  if( grid.inBounds(x+1, y) &&
    !grid.isEmpty(x+1, y) && 
    grid.get(x+1, y)->isPreyFor(this)
  ){ // direita
    grid.remove(x+1, y);
    deslocar(grid,x+1,y);
    return true;
  } 
  if(grid.inBounds(x, y+1) && 
    !grid.isEmpty(x, y+1) &&
    grid.get(x, y+1)->isPreyFor(this)
  ){ // baixo
    grid.remove(x, y+1);
    deslocar(grid,x,y+1);
    return true;
  } 
  
  if(grid.inBounds(x-1, y) && 
      !grid.isEmpty(x-1, y) &&
      grid.get(x-1, y)->isPreyFor(this) 
  ){ // esquerda
    grid.remove(x-1, y);
    deslocar(grid,x-1,y);
    return true;
  } 
  
  return false;
}

void Jaguar::move(Grid& grid){
  if(!moved){
    if(!tryPredation(grid)){
      if(tryMoveToEmpty(grid)){
        moved = true;
      }
    }
  }
}