#ifndef CARRO_HPP
#define CARRO_HPP
#include <iostream>
#include "Motor.hpp"

class Carro {
  private:
    int _num_portas;
    Motor _motor;
    
  public:
    Carro(int num_portas);
    
    virtual void acelerar();
    
    virtual void frear();

    int get_num_portas();

  private:
    void acionar_motor();

    void acionar_discos_freio() ;
};

#endif