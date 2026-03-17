/*
Read a value of floating point with two decimal places. This represents a monetary value. After this, calculate the smallest possible number of notes and coins on which the value can be decomposed. The considered notes are of 100, 50, 20, 10, 5, 2. The possible coins are of 1, 0.50, 0.25, 0.10, 0.05 and 0.01. Print the message “NOTAS:” followed by the list of notes and the message “MOEDAS:” followed by the list of coins.
Input

The input file contains a value of floating point N (0 ≤ N ≤ 1000000.00).
Output

Print the minimum quantity of banknotes and coins necessary to change the initial value, as the given example.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  double num;
  cin >> num;

  int notas[] = {100, 50, 20, 10, 5, 2};
  int moedas[] = {100, 50, 25, 10, 5, 1};
  int qtd[6];

  cout << "NOTAS:" << endl;
  for(int i=0; i<6; i++){
    if(num/notas[i] <=0)
      qtd[i] =0;
    else{
      qtd[i] = (int)num/notas[i];
      num = num - qtd[i]*notas[i];
    }
    cout << qtd[i] << " nota(s) de R$ " << notas[i] << ".00" << endl;
  }

  num = num*100;
  cout << "MOEDAS:" << endl;
  for(int i=0; i<6; i++){
    if(num/moedas[i] <=0)
      qtd[i] =0;
    else{
      qtd[i] = (int)num/moedas[i];
      num = num - qtd[i]*moedas[i];
    }
    cout << qtd[i] << " moeda(s) de R$ ";
    cout << fixed << setprecision(2) << (double)moedas[i]/100 << '\n';
  }

  return 0;
}