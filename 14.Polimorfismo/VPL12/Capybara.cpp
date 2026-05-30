#include "Capybara.hpp"

Capybara::Capybara(int x, int y) : Organism(x, y) {}

char Capybara::symbol() const {
  return 'C';
}

bool Capybara::isPreyFor(const Organism* predator) const {
  if(predator->symbol() == 'O')
    return true;
  else
    return false;
}

void Capybara::move(Grid& grid){
  if(!moved){
    if(tryMoveToEmpty(grid)){
        moved = true;
      }
  }
}