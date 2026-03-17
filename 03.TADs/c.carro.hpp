#include <cmath>
#include <numbers>
#include <iostream>
#include "c.pessoa.hpp"

using namespace std;

struct Carro{
  double x;
  double y;
  double th; // angulo da orientação do veículo

  Carro(double x, double y, double th);

  double getx();
  double gety();
  double getTH();

  void girar(double w, double t);

  void mover(double v, double t);

  double calcular_angulo_pessoa(Pessoa* pessoa);

  double calcular_distancia_pessoa(Pessoa* pessoa);

  bool movimentacao_permitida(Pessoa** pessoas, int n);
  void navegar(Pessoa** pessoas, int n, double w, double v, double t);
};