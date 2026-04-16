#ifndef DEFESA_HPP
#define DEFESA_HPP
#include <iostream>

class Defesa{
  private:
    int _id;
    double _energia; // quando consome

  protected:
    Defesa(int id, double energia);

    void _consumirEnergia(double qtd); // subtrai qtd de energia, não deixar neg
  
  public: 
    virtual void atacar(double &danoAcumulado) =0;

    double GetEnergia();

    ~Defesa();
};


#endif