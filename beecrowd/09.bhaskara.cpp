/*
Read 3 floating-point numbers. After, print the roots of bhaskara’s formula. If it's impossible to calculate the roots because a division by zero or a square root of a negative number, presents the message “Impossivel calcular”.

Input
Read 3 floating-point numbers (double) A, B and C.

Output
Print the result with 5 digits after the decimal point or the message if it is impossible to calculate.
*/
#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  double a =0.0;
  double b =0.0;
  double c =0.0;
  double x1 =0.0;
  double x2 =0.0;
  cin >> a >> b >> c;

  if(a<=0 || b<=0 || c<=0){
    cout << "Impossivel calcular" << endl;
    return 0;
  }


  double delta = b*b -4 * a * c;

  if(delta < 0)
    cout << "Impossivel calcular" << endl;
  else{ //-b -+raizdelta / 2a
    x1 = (-b + sqrt(delta))/ (2*a);
    x2 = (-b - sqrt(delta))/ (2*a);

    cout << "R1 = " << fixed << setprecision(5) << x1 << endl << "R2 = " << x2 << endl;
  }

  return 0;
}