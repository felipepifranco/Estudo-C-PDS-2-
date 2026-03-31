#ifndef PROCESSO
#define PROCESSO
#include <iostream>

struct Processo{
  int _id; 
  int _prioridade;
  std::string _nome;
  Processo* next;
  Processo* prev;
  
  Processo(int id, std::string nome, int prioridade);

  int getID();

  int getPrioridade();

  std::string getNome();

  double tempo_reservado_processo();

  void imprimir_dados();
};
#endif