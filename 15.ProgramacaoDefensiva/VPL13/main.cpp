#include <iostream>
#include <string>
#include <stdexcept>
#include "Estoque.h"
#include "EstoqueInsuficienteException.h"

int main() {
  Estoque estoque;
  std::string cmd;

  while (std::cin >> cmd && cmd != "quit") {
    if(cmd == "add"){
      std::string nome;
      int qtd_inicial;
      std::cin >> nome >> qtd_inicial;
      
      try{
        estoque.adicionar_item(nome, qtd_inicial);
      }catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
        continue;
      } catch(std::domain_error& e){
        std::cout << e.what() << std::endl;
        continue;
      }
      std::cout << "OK: item " << nome << " cadastrado" << std::endl;

    }else if(cmd == "entrada"){
      int indice, qtd;
      std::cin >> indice >> qtd;

      try{
        estoque.registrar_entrada(indice, qtd);
      } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
        continue;
      } catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
        continue;
      }
      std::cout << "OK: entrada concluida" << std::endl;

    }else if(cmd == "saida"){
      int indice, qtd;
      std::cin >> indice >> qtd;

      try{
        estoque.registrar_saida(indice, qtd);
      } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
        continue;
      } catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
        continue;
      } catch(EstoqueInsuficienteException& e){
        std::cout << e.what() << std::endl;
        std::cout << "Item: " << e.get_nome() << std::endl << 
                  "Disponivel: " << e.get__num_disponivel() << std::endl << 
                  "Pedido: " << e.get_num_pedido() << std::endl;
        continue;
      }

      std::cout << "OK: saida concluida" << std::endl;

    }
    else if( cmd == "consulta"){
      int indice;
      std::cin >> indice;      
      try{
        estoque.consultar(indice);
      } catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
      }

    }else if(cmd == "list"){
      estoque.listar();

    }else if(cmd == "quit"){
      break;
    }

  }

  return 0;
}
