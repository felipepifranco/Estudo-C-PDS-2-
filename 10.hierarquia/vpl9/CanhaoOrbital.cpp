#include "CanhaoOrbital.hpp"

void CanhaoOrbital::atacar(double &danoAcumulado){
  if(this->GetEnergia() >=10 ){
    double base = 0;
    Canhao::atacar(base);

    danoAcumulado += (base * this->_multiplicadorGravitacional);
    std::cout << "Ataque Orbital realizado!" << std::endl;
  }
}

CanhaoOrbital::CanhaoOrbital(int id, double energia, double intensidade, double gravidade) : Canhao(id, energia, intensidade), _multiplicadorGravitacional(gravidade){}