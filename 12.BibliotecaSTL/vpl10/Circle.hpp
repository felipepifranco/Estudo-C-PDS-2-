#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape{
  private:
  double radius;

  public:
  Circle(double r);

  void set_radius(double r);
  double get_radius();

  std::string name() const override;

  double area() const override;
};

#endif
