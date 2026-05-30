#include "Estoque.h"
#include "EstoqueInsuficienteException.h"
#include <stdexcept>
#include <iostream>

// Lembre de usar EstoqueInsuficienteException nos blocos try-catch

void Estoque::adicionar_item(const std::string& nome, int quantidade_inicial) {
  if(quantidade_inicial <=0){
    throw std::invalid_argument("Erro: quantidade invalida");
  }
  
  for(Item &item : _itens){
    if(item.nome == nome){
      throw std::domain_error("Erro: item duplicado");
    }
  }

  _itens.push_back(Item(nome, quantidade_inicial));
}

void Estoque::registrar_entrada(int indice, int quantidade) {
    if( quantidade <= 0){
      throw std::invalid_argument("Erro: quantidade invalida");
    }
    if(_itens.empty() || (unsigned long int)indice >  _itens.size() -1){
      throw std::out_of_range("Erro: indice invalido");
    }

    _itens[indice].quantidade += quantidade;
    // std::cout << "nova quantida de " << _itens[indice].nome << ": " << _itens[indice].quantidade << std::endl;
}

void Estoque::registrar_saida(int indice, int qtd_pedida) {
  if( qtd_pedida <= 0){
    throw std::invalid_argument("Erro: quantidade invalida");
  }
  if(_itens.empty() ||(unsigned long int)indice > _itens.size() -1){
    throw std::out_of_range("Erro: indice invalido");
  }
  if(qtd_pedida >_itens[indice].quantidade){
    throw EstoqueInsuficienteException(_itens[indice].nome, _itens[indice].quantidade, qtd_pedida);
  }

  _itens[indice].quantidade -= qtd_pedida;
}

void Estoque::consultar(int indice) const {
  if(_itens.empty() ||(unsigned long int)indice > _itens.size() -1){
    throw std::out_of_range("Erro: indice invalido");
  }
  
  std::cout << "Nome: " << _itens[indice].nome << std::endl << "Quantidade: " << _itens[indice].quantidade << std::endl;
}

void Estoque::listar() const {
  if(_itens.size() == 0){
    std::cout << "Estoque vazio!" << std::endl;
    return;
  }

  int i =0;
  for(Item unidade : _itens){
    std::cout << "[" << i << "] " << unidade.nome << " " << unidade.quantidade << std::endl;
    i ++;
  }
}