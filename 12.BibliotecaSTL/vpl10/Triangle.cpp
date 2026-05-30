#include "Triangle.hpp"
#include <math.h>


Triangle::Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}

void Triangle::set_a(double x) {this->a = x;}
void Triangle::set_b(double x) {this->b = x;}
void Triangle::set_c(double x) {this->c = x;}
double Triangle::get_a(){return a;}
double Triangle::get_b(){return b;}
double Triangle::get_c(){return c;}

std::string Triangle::name() const{
  return "Triangulo";
} 

double Triangle::area() const {
  //usando formula de heron
  double semiper = (a+b+c)/2;
  return std::sqrt((semiper)*(semiper-a)*(semiper-b)*(semiper-c));
}
