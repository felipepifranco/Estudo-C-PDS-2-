#include "FilaProcessos.hpp"
#include "Processo.hpp"
#include <iomanip>

FilaProcessos::FilaProcessos(){
  this->id =1;
  this->inicio = nullptr;
  this->fim = nullptr;
}

Processo* FilaProcessos::ondeInserir(Processo* novo){ //retorna o endereço do processo que será o anterior
  Processo* atual = this->inicio;
  while(atual != nullptr){
    if(atual->_prioridade >= novo->_prioridade)
      atual = atual->next;
    else if(atual->_prioridade < novo->_prioridade)
      return atual->prev;
  }
  //se chegou até aqui, então todos são maiores do que o valor. Logo, ele deve ser o último:
  return this->fim;
}

void FilaProcessos::adicionar_processo(std::string nome, int prioridade){
  // preenche com nome e prioridade
  Processo* novo = new Processo(id, nome, prioridade); //TODO: DELETAR
  Processo* atual = this->inicio;
  

  if(this->inicio == nullptr){ // lista vazia
    this->inicio = novo;
    this->fim = novo;
    novo->next = nullptr;
    novo->prev = nullptr;
  }
  else if(prioridade > atual->_prioridade){ // se ele deve ser o primeiro elemento
    novo->next = this->inicio;
    novo->prev = nullptr;
    atual->prev = novo;
    this->inicio = novo;
  } 
  else{
    atual = this->ondeInserir(novo); // retorna o endereço que deve ser o novo->prev
    novo->prev = atual;
    novo->next = atual->next;
    if(atual == this->fim){
      this->fim = novo;
      atual->next = novo;
    } else{
      (atual->next)->prev = novo;
      atual->next = novo;
    }
  }
  
  //preenche com id certo
  novo->_id = this->id;
  this->id ++;
}


Processo* FilaProcessos::remover_processo_maior_prioridade(){
  Processo* apagado = this->inicio;

  if(this->inicio == nullptr){ // fila vazia
    return nullptr;
  }

  if(apagado->next != nullptr){
    this->inicio = apagado->next;
    (apagado->next)->prev = nullptr;
  } else{
    this->inicio = nullptr;
    this->fim = nullptr;
  }

  
  return apagado;
}


Processo* FilaProcessos::remover_processo_por_id(int id){
  Processo* atual = this->inicio;

  while(atual != nullptr){
    if(atual->_id == id){
      
      //codigo para remover 
      if(atual->prev == nullptr && atual->next == nullptr){
        this->inicio = nullptr;
        this->fim = nullptr;
        return atual;
      }

      if(atual->prev != nullptr)
        (atual->prev)->next = atual->next;
      else{
        (atual->next)->prev = nullptr;
        this->inicio = atual->next;
      }

      if(atual->next != nullptr)
        (atual->next)->prev = atual->prev;
      else{
        (atual->prev)->next = nullptr;
        this->fim = atual->prev;
      }
      //retornar qual foi removido
      return atual;

    }

    else
      atual = atual->next;
  }
  //se chegou aqui, não encontrou o id
  return nullptr;
}

void FilaProcessos::estimativa_tempo_para_execucao(int id){
  Processo* atual = this->inicio;
  double tempo =0;
  bool encontrou = false;

  while(atual != nullptr){
    if(atual->_id == id){
      encontrou = true;
      break;
    }
    else{
      tempo += atual->tempo_reservado_processo();
      atual = atual->next;
    }
  }

  if(encontrou){
    std::cout << "Tempo estimado para execução do processo " << atual->_nome << " (id="<< atual->_id << ") " << "eh " << std::fixed << std::setprecision(1) << tempo << " segundos." << std::endl;
  } else {
    std::cout << "Processo " << atual->_nome << " Não encontrado!" << std::endl;
  }
}

void FilaProcessos::imprimir_fila(){
  Processo* atual = this->inicio;

  while(atual != nullptr){
    atual->imprimir_dados();
    atual = atual->next;
  }
}