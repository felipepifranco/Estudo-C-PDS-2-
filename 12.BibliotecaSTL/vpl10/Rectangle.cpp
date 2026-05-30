#include "Rectangle.hpp"

Rectangle::Rectangle(double w, double h) : width(w), height(h){}

void Rectangle::set_width(double x) {width = x;}
double Rectangle::get_width(){return width;}
void Rectangle::set_height(double x){width = x;}
double Rectangle::get_height(){return height;}

std::string Rectangle::name() const{
  return "Retangulo";
}

double Rectangle::area() const{
  return width*height;
}
