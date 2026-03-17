#include <iostream>
#include <string>

using namespace std;

int main() {
  string nome;
  int idade;
  
  cout << "Digite o seu nome: ";
  cin >> nome; // aguarda uma string
  
  cout << "Digite sua idade: ";
  cin >> idade; // aguarda um inteiro, similar a scanf("%d", &idade);
  
  cout << endl;
  cout << "Ola " << nome << " voce tem " << idade << " anos." << endl;

  return 0;
}