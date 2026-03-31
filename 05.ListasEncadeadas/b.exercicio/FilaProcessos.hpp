#ifndef FILAPROCESSOS
#define FILAPROCESSOS
#include "Processo.hpp"
#include <iostream>

struct FilaProcessos{
  int id; // começa em 1
  Processo* inicio;
  Processo* fim;
  
  FilaProcessos();

  Processo* ondeInserir(Processo* novo);

  void adicionar_processo(std::string nome, int prioridade);

  Processo* remover_processo_maior_prioridade();

  Processo* remover_processo_por_id(int id);

  void estimativa_tempo_para_execucao(int id);

  void imprimir_fila();
};

#endif