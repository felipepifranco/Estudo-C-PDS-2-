#include <iostream>
#include <iomanip>
#include <cmath>
 
using namespace std;

int main() {
 
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    double distancia = (x2 -x1)*(x2 -x1) + (y2-y1)*(y2-y1);
    distancia = sqrt(distancia);
    
    cout << fixed << setprecision(4) << distancia << '\n';
    
    return 0;
}