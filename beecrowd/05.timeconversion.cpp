/*
Read an integer value, which is the duration in seconds of a certain event in a factory, and inform it expressed in hours:minutes:seconds.

Input
The input file contains an integer N.

Output
Print the read time in the input file (seconds) converted in hours:minutes:seconds like the following example.
*/

#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  int minutos = n/60;
  n = n%60;
  int horas = minutos/60;
  minutos = minutos%60;

  cout << horas << ":" << minutos << ":" << n << endl;
}