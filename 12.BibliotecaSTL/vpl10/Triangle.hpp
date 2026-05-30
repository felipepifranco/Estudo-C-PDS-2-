#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape{
  private:
  double a, b, c;

  public:
  Triangle(double s1, double s2, double s3);

  void set_a(double x);
  void set_b(double x);
  void set_c(double x);
  double get_a();
  double get_b();
  double get_c();

  std::string name() const override; // retorna triangulo

  double area() const override;
};

#endif
