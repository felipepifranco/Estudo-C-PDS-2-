#include "Canhao.hpp"

Canhao::Canhao(int id, double energia, double intensidade) : Defesa(id, energia), _intensidade(intensidade) {}

void Canhao::atacar(double &danoAcumulado) {
  if(this->GetEnergia() >= 10){
    this->_consumirEnergia(10);
    danoAcumulado += this->_intensidade;
    //std::cout << "ataque feito! energia restante: " << this->GetEnergia() << std::endl;
  }
}
