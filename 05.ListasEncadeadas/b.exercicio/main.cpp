#include <iostream>
#include <cstring>
#include "FilaProcessos.hpp"
#include "Processo.hpp"
//#include "avaliacao_basica_controle.hpp"

using namespace std;

void deletarTudo(FilaProcessos* fila){
  Processo* atual = fila->inicio;
  Processo* temp;
  while(atual != nullptr){
    temp = atual;
    atual = atual->next;
    delete temp;
  }
  delete fila;
}

int main(){
  char indicador;
  std::string nome;
  int id;
  int prioridade;
  Processo* removido = nullptr;

  FilaProcessos* fila = new FilaProcessos();
  // usar while(cin >> indicador) no vpl
  while(true){
    cin >> indicador;

    switch(indicador){
      case 'a':
        cin >> nome >> prioridade;
        fila->adicionar_processo(nome, prioridade);
        break;
      case 'r':
        removido = fila->remover_processo_maior_prioridade();
        delete removido;
        break;
      case 'i':
        cin >> id;
        removido = fila->remover_processo_por_id(id);
        delete removido;
        break;
      case 'p':
        fila->imprimir_fila();
        break;
      case 'e':
        cin >> id;
        fila->estimativa_tempo_para_execucao(id);
        break;
      case 'b':
        //avaliacao_basica();
        break;
      case 'q':
        return 0;
        break;
      default:
        cout << "ERRO!" << endl;
    }

  }
  deletarTudo(fila);
  return 0;
}