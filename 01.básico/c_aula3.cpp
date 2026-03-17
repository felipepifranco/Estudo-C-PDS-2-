/*
Escreva um programa que peça ao usuário para inserir os elementos de uma matriz 3 × 3 e depois exiba a matriz na tela.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
  int matriz[3][3];
  int temp =0;
  cout << "Insira os elementos da matriz: ";
  for (int i=0; i<3; i++){
    for (int j=0; j< 3; j++){
      cin >> temp;
      matriz[i][j] = temp;
    }
  }

  cout << "Sua matriz eh:" << endl;
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout << "[" << matriz[i][j] << "]";
    }
    cout << endl;
  }
}