#include <iostream>
#include <string>

int main() {
  std::string curto = "Hello World!";
  std::string longo = "Essa é uma string grande para o exemplo!";

  std::cout << curto << std::endl;
  std::cout << longo << std::endl;

  std::cout << longo.length() << std::endl;
  // metodo de strings que retorna o tamanho dela
}