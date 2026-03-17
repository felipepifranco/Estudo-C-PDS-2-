/*
In this problem you have to read an integer value and calculate the smallest possible number of banknotes in which the value may be decomposed. The possible banknotes are 100, 50, 20, 10, 5, 2 and 1. Print the read value and the list of banknotes.
Input

The input file contains an integer value N (0 < N < 1000000).
Output

Print the read number and the minimum quantity of each necessary banknotes in Portuguese language, as the given example. Do not forget to print the end of line after each line, otherwise you will receive “Presentation Error”.

*/

#include <iostream>

using namespace std;

int main(){
  int num;
  cin >> num;
  
  int num_notas = 7;
  int notas[] = {100, 50, 20, 10, 5, 2, 1};
  int *quant = new int[num_notas];

  cout << num << endl;
  for(int i=0; i<num_notas; i++){
    if(num/notas[i] <= 0){
      quant[i] =0;
    }
    else{
      quant[i] = num/notas[i];
      num = num%notas[i];
    }
    cout << quant[i] << " nota(s) de R$ " << notas[i] << ",00" << endl;
  }

  delete[] quant;
  return 0;
}