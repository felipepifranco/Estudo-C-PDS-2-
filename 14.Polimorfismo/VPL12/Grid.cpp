#include "Grid.hpp"

Grid::Grid(int r, int c) : rows(r), cols(c) {
  for (int i = 0; i < r; i++) {
    std::vector<Organism*> row;
    for (int j = 0; j < c; j++) {
      row.push_back(nullptr);
    }
    cells.push_back(row);
  }
}

Grid::~Grid(){
  for(int i =0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(cells[i][j] != nullptr)
        delete cells[i][j];
    }
    cells[i].clear();
  }
  cells.clear();
}

bool Grid::inBounds(int x, int y) const{
  if( x< 0 || x >= cols){
    return false;
  }
  else if (y < 0 || y >= rows){
    return false;
  }
  else
    return true;
}

bool Grid::isEmpty(int x, int y) const{
  if(cells[y][x] == nullptr)
    return true;
  else 
    return false;
}

Organism* Grid::get(int x, int y) const{
  return cells[y][x];
}

void Grid::set(int x, int y, Organism* o){
  cells[y][x] = o;
}

void Grid::set(Organism* o){
  cells[o->getY()][o->getX()] = o;
}

void Grid::clear(int x, int y){
  cells[y][x] = nullptr;
}

void Grid::remove(int x, int y){
  delete cells[y][x];
  clear(x,y);
}

void Grid::resetMoved(){
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(cells[i][j] != nullptr)
        cells[i][j]->setMoved(false);
    }
  }
}

int Grid::getRows() const{
  return rows;
}

int Grid::getCols() const{
  return cols;
}

std::ostream& operator<<(std::ostream& os, const Grid& g){
  for(int i =0; i<g.rows; i++){
    for(int j=0;j<g.cols; j++){
      if(g.cells[i][j] != nullptr)
        os << g.cells[i][j]->symbol();
      else
        os << ".";
    }
    os << std::endl;
  }
  os << std::endl;
  return os;
}