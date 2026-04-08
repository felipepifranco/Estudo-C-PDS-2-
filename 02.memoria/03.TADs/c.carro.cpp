#include "c.carro.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Carro::Carro(double x, double y, double th){
  this->x = x;
  this->y = y;
  this->th = th;
}

double Carro::getX(){
  return this->x;
}
double Carro::getY(){
  return this->y;
}
double Carro::getTH(){
  return this->th;
}

void Carro::girar(double w, double t){ // w é velocidade angular e t é tempo
  double angulo = w*t;
  this->th += angulo;
}

void Carro::mover(double v, double t){
  double vx = v*cos(this->th);
  double vy = v*sin(this->th);

  this->x += vx*t;
  this->y += vy*t;
}

double Carro::calcular_angulo_pessoa(Pessoa* pessoa){
  //double tg = (pessoa->y - this->y) / (pessoa->x - this->x);
  
  double tg = atan2(pessoa->y - this->y, pessoa->x - this->x);
  double carro = this->th;
  return tg - carro;
}

double Carro::calcular_distancia_pessoa(Pessoa* pessoa){
  double y = pessoa->y - this->y; 
  double x = pessoa->x - this->x; 
  return sqrt(y*y + x*x);
}

bool Carro::movimentacao_permitida(Pessoa** pessoas, int n){
  double graus45 = 45;
  double ang;
  double dist;
  bool pode = true;

  for(int i=0; i<n; i++){
    ang = calcular_angulo_pessoa(pessoas[i]) *(180 / acos(-1.0)); // transformacao para graus
    dist = calcular_distancia_pessoa(pessoas[i]);

    if( ang <= graus45 && ang >= -1*graus45 && dist <5){
        cout << "Alerta! " << i << '\t' << ang << '\t' << dist << endl;
        pode = false;
    }
  }
  if(pode)
    return true;
  else
    return false;
}

void Carro::navegar(Pessoa** pessoas, int n, double w, double v, double t){
  if(movimentacao_permitida(pessoas, n)){
    girar(w, t);
    mover(v, t);
  }
}