/*
programa precisa ler um número inteiro, um número decimal e uma string
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
  int num;
  float num_d;
  string str;

  cout << "Insira um numero inteiro, um numero decimal e uma palavra: ";
  cin >> num >> num_d >> str;

  cout << "Inteiro: " << num << ", Decimal: " << num_d << ", Palavra: " << str << endl;
  return 0;
}