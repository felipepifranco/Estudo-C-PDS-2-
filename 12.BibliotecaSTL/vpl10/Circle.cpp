#include "Circle.hpp"
#include <math.h>


Circle::Circle(double r) : radius(r){}

void Circle::set_radius(double r){ radius = r;}
double Circle::get_radius(){return radius;};

std::string Circle::name() const{
  return "Circulo";
}

double Circle::area() const{
  double pi = std::acos(-1.0);
  return pi * radius*radius;
}
