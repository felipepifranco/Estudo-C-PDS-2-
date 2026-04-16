#ifndef LANCADORMISSIL_HPP
#define LANCADORMISSIL_HPP
#include "Defesa.hpp"

class LancadorMissil : public Defesa{
  private:
    int _misseis;
  
  public:
    LancadorMissil(int id, double energia, int misseis);

    void atacar(double &danoAcumulado) override; // consome 1 missil e 5 unidades de energia
    // cada missil é +40 danoAcumulado
};

#endif