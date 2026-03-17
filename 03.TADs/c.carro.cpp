#include <cmath>

#include <iostream>
#include "c.pessoa.hpp"
#include "c.carro.hpp"

using namespace std;

struct Carro{
  double x;
  double y;
  double th; // angulo da orientação do veículo

  Carro(double x, double y, double th){
    this->x = x;
    this->y = y;
    this->th = th;
  }

  double getx(){
    return this->x;
  }
  double gety(){
    return this->y;
  }
  double getTH(){
    return this->th;
  }

  void girar(double w, double t){ // w é velocidade angular e t é tempo
    double angulo = w*t;
    this->th += angulo;
  }

  void mover(double v, double t){
    double vx = v*cos(this->th);
    double vy = v*sin(this->th);

    this->x += vx*t;
    this->y += vy*t;
  }

  double calcular_angulo_pessoa(Pessoa* pessoa){
    //double tg = (pessoa->y - this->y) / (pessoa->x - this->x);
    
    return atan2(pessoa->y - this->y, pessoa->x - this->x);
  }

  double calcular_distancia_pessoa(Pessoa* pessoa){
    double y = pessoa->y - this->y; 
    double x = pessoa->x - this->x; 
    return sqrt(y*y + x*x);
  }

  bool movimentacao_permitida(Pessoa** pessoas, int n){
    double graus45 = 45;
    double ang;
    double dist;

    for(int i=0; i<n; i++){
      ang = calcular_angulo_pessoa(pessoas[i]) *(180 / acos(-1.0)); // transformacao para graus
      dist = calcular_distancia_pessoa(pessoas[i]);

      if( ang <= graus45 && ang >= -1*graus45){
        if(dist <5){
          cout << "Alerta! IDX" << i << '\t' << ang << '\t' << dist << endl;
          return false;
        }
        else return true;
      }else return true;
    }
  }

  void navegar(Pessoa** pessoas, int n, double w, double v, double t){
    if(movimentacao_permitida(pessoas, n)){
      girar(w, t);
      mover(v, t);
    }
  }
};