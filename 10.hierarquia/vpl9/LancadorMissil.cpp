#include "LancadorMissil.hpp"

LancadorMissil::LancadorMissil(int id, double energia, int misseis) : Defesa(id, energia), _misseis(misseis){}

void LancadorMissil::atacar(double &danoAcumulado){
    if(this->GetEnergia() >=5 && this->_misseis >=1){
      danoAcumulado += 40;
      this->_consumirEnergia(5);
      this->_misseis --;
    }
}