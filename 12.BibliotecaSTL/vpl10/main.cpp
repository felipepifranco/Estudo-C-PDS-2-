#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "shapeFunctions.hpp"
#include <cctype>
#include <iomanip> 


int main(){
  std::vector<Shape*> shapes;
  std::string prompt;
  
  while(std::cin >> prompt){
    for(int i=0; i< (int)prompt.size(); i++){
      prompt[i] = std::toupper(prompt[i]);
    }
  
    double argument1, argument2, argument3;
    if ("CIRCLE" == prompt){
      std::cin >> argument1;
      shapes.push_back(new Circle(argument1));
    } 
    else if ("RECT" == prompt){
      std::cin >> argument1 >> argument2;
      shapes.push_back(new Rectangle(argument1, argument2));
    }
    else if ("TRIANGLE" == prompt){
      std::cin >> argument1 >> argument2 >> argument3;
      shapes.push_back(new Triangle(argument1, argument2, argument3));
    }
    else if ("LIST" == prompt){
      ShapeFunctions::printShapes(shapes); 
    }
    else if ("TOTAL" == prompt){
      std::cout <<"Total: "<< std::fixed << std::setprecision(2) << ShapeFunctions::totalArea(shapes)<< std::endl;
    }
    else if ("SORT" == prompt){
      ShapeFunctions::sortShapesByArea(shapes);
    }
    else if ("FILTER" == prompt){
      std::cin >> argument1;
      ShapeFunctions::printShapes(ShapeFunctions::getShapesWithAreaGreaterThan(shapes, argument1));
    }
    else if ("COUNT" == prompt){
      std::map<std::string, int> mapa = ShapeFunctions::countShapesByName(shapes);

      std::map<std::string, int>::iterator it;
      for (it = mapa.begin(); it != mapa.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
      }
    }
    else if ("UNIQUE" == prompt){
      for(double areas : ShapeFunctions::uniqueAreas(shapes))
        std::cout  << areas << std::fixed << std::setprecision(2) << " ";
      std::cout << std::endl;
    }
    else if("TRAVERSABLE" == prompt){
      std::cin >> argument1 >> argument2;
      ShapeFunctions::verificarTraversable(shapes, argument1, argument2);
    }
    else if("CLEAR" == prompt){
      for(Shape* forma : shapes){
        delete forma;
      }
      shapes.clear();
    }
  }

    
}