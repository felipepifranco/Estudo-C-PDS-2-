#include "shapeFunctions.hpp"
#include <numeric>
#include <algorithm>
#include <iomanip> 
  
void ShapeFunctions::printShapes(const std::vector<Shape*>& shapes){
  for(Shape* forma : shapes){
    std::cout << forma->name() << " com area " << std::fixed << std::setprecision(2) << forma->area() <<std::endl;
  }
}

double ShapeFunctions::totalArea(const std::vector<Shape*>& shapes){
  // a operação binária de accumulate recebe primeiro o valor acumulado e, em seguida, o valor seguinte. Logo, será usada uma função lambda que se adeque a isso
  return std::accumulate(shapes.begin(), shapes.end(), 0.0, 
                          [](double soma, Shape* proximo){
                            return (double)soma + proximo->area();
                          }
                        );
}

std::vector<Shape*> ShapeFunctions::getShapesWithAreaGreaterThan(const std::vector<Shape*>& shapes, double minArea){
  std::vector<Shape*> novo;
  
  for(Shape* forma : shapes){
    if(forma->area() > minArea)
      novo.push_back(forma);
  }

  return novo;
}

bool less_than_key(const Shape* a, const Shape* b){
    return (a->area() < b->area());
}

void ShapeFunctions::sortShapesByArea(std::vector<Shape*>& shapes){
  //sort recebe manda na função de comparação 2 elementos
  std::sort(shapes.begin(), shapes.end(), less_than_key);
}

std::map<std::string, int> ShapeFunctions::countShapesByName(const std::vector<Shape*>& shapes){
  std::map<std::string, int> contagem;
  std::set<std::string> chaves;

  for(Shape* forma : shapes){
    contagem[forma->name()]++;
  }

  return contagem;
}

std::set<double> ShapeFunctions::uniqueAreas(const std::vector<Shape*>& shapes){
  std::set<double> areas;
  for(Shape* forma : shapes){
    areas.insert(forma->area());
  }

  return areas;
}

void ShapeFunctions::verificarTraversable(const std::vector<Shape*>& shapes, double area_ambiente, double tolerancia){
  double area_livre = area_ambiente - totalArea(shapes);
  if(area_livre > tolerancia)
    std::cout << "Ambiente trafegavel. Area livre: " << std::fixed << std::setprecision(2) << area_livre << std::endl;
  else 
    std::cout << "Ambiente nao trafegavel. Area livre insuficiente: " << std::fixed << std::setprecision(2) << area_livre << std::endl;

}
