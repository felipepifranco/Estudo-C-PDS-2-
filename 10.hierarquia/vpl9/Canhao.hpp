#ifndef CANHAO_HPP
#define CANHAO_HPP
#include "Defesa.hpp"

class Canhao : public Defesa{
  private:
    double _intensidade;
  
  public:
    Canhao(int id, double energia, double intensidade);

    void atacar(double &danoAcumulado) override;
};


#endif