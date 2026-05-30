#include "Organism.hpp"
#include "Grid.hpp"

Organism::Organism(int x, int y) : x(x), y(y){
  moved = false;
}
Organism::~Organism(){}

bool Organism::tryMoveToEmpty(Grid& grid){
  if(grid.inBounds(x, y-1) && grid.isEmpty(x, y-1)){ // cima
    deslocar(grid,x,y-1);
    return true;
  } 
  else if(grid.inBounds(x+1, y) && grid.isEmpty(x+1, y)){ // direita
    deslocar(grid,x+1,y);
    return true;
  } 
  else if(grid.inBounds(x, y+1) &&grid.isEmpty(x, y+1)){ // baixo
    deslocar(grid,x,y+1);
    return true;
  } 
  else if(grid.inBounds(x-1, y) && grid.isEmpty(x-1, y)){ // esquerda
    deslocar(grid,x-1,y);
    return true;
  } 
  else
    return false;
}

bool Organism::tryPredation(Grid& grid){
  return false;
}

bool Organism::isPreyFor(const Organism* predator) const{
  return false;
}

void Organism::setMoved(bool m){
  moved = m;
}

bool Organism::hasMoved() const{
  return moved;
}

int Organism::getX() const{
  return x;
}

int Organism::getY() const{
  return y;
}

void Organism::setPosition(int nx, int ny){
  x = nx;
  y = ny;
}

void Organism::deslocar(Grid& grid, int novoX, int novoY){
  grid.clear(x, y);
  x = novoX;
  y = novoY;
  grid.set(novoX, novoY, this);
  moved = true;
}