/*
escrever um programa que lê números da entrada padrão (cin), calcula a soma e a média, e exibe os resultados. Porém, em vez de digitar os números manualmente, o programa deve ser capaz de ler os dados a partir de um arquivo usando redirecionamento (<)
*/

#include <iostream> 
#include <string>

using namespace std;

int main() {
  int num;
  int qtd =0;
  int soma =0;
  while(cin >> num){
    soma += num;
    qtd ++;
  }

  float media = (float)soma / qtd;
  cout << "A soma dos " << qtd << " numeros deu " << soma << ", resultando em uma media de " << media << endl;

  return 0;
}