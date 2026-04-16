#ifndef CANHAOORBITAL_HPP
#define CANHAOORBITAL_HPP
#include "Canhao.hpp"

class CanhaoOrbital : public Canhao{
  private:
    double _multiplicadorGravitacional;

  public: 

  CanhaoOrbital(int id, double energia, double intensidade, double gravidade);

  void atacar(double &danoAcumulado) override;

};

#endif