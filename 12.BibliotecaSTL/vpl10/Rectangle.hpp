#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape{
  private:
  double width;
  double height;

  public:
  Rectangle(double w, double h);

  void set_width(double x);
  double get_width();
  void set_height(double x);
  double get_height();

  std::string name() const override; // retorna retangulo

  double area() const override;
};

#endif
