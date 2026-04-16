#include <iostream>

using namespace std;

class Base {
public:
int var_base;
Base(int vb) : var_base(vb) {};
};


class Derivada : public Base {
public:
int var_derivada;
Derivada(int vb, int vd) : Base(vb), var_derivada(vd) {};
};

int main() {
Base base(55);
cout << base.var_base << endl;
Derivada derivada(77, 99);
cout << derivada.var_base << endl;
cout << derivada.var_derivada << endl;
return 0;
}