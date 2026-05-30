#ifndef BATMOVEL_HPP
#define BATMOVEL_HPP
#include "Carro.hpp"


class Turbina{
  public:
    void ligar_turbo();
};

class BatMovel : public Carro {
  private:
    Turbina _turbina;
  
  public:
    BatMovel();

    void acelerar_turbo();
  
    void frear() override;

  private:
    void acionar_turbina();

};

class MaquinaMisterio : public Carro{
  private:
    int pistas;
  
  public: 
    MaquinaMisterio();

    void acelerar() override;

    void investigar();
};

#endif