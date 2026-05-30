#pragma once
#include <stdexcept>
#include <iostream>

// Implemente a classe EstoqueInsuficienteException.
// Como garantir que ela seja um 'runtime_error'?
class EstoqueInsuficienteException : public std::runtime_error {
private:
    std::string _nome_item;
    int _num_disponivel;
    int _num_pedido;

public:
  EstoqueInsuficienteException(std::string nome, int disp, int pedido) : std::runtime_error(""), _nome_item(nome), _num_disponivel(disp), _num_pedido(pedido){} 

  virtual const char* what() const noexcept override{
    return "Erro: estoque insuficiente.";
  }
  
  std::string get_nome(){ return _nome_item; }
  int get__num_disponivel(){return _num_disponivel;}
  int get_num_pedido(){ return _num_pedido; }

};



