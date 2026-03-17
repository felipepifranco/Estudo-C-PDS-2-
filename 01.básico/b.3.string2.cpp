#include <iostream>
#include <string>

using namespace std; //fazendo isso, não precisa informar o escopo antes das variáveis (usar com cuidado!)

int main() {
  string a;
  a = "123456";
  
  string b;
  b = "123456";

  bool igual = (a == b); // é possível comparar e salvar o retrorno em uma variável Booleana, retorna 1 se true
  cout << igual << endl;
  
  cout << a[0] << endl; // manipulação de cada caractere similar a array
  cout << b[5] << endl;

  a[0] = '0';
  cout << a << endl;

  string c = a + b; //concatenação
  cout << c << endl;
  
  return 0;
}