/*
escrever um programa que lê um número decimal e uma cadeia de caracteres e os imprime na tela.
*/

#include <iostream>
#include <string>

int main(){
  float d;
  std::string cadeia;

  std::cout << "Digite um número decimal e uma palavra: ";
  std::cin >> d >> cadeia;

  std::cout << "Você digitou: " << d << " e " << cadeia << std::endl;
  return 0;
}