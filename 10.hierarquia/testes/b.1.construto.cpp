#include <iostream>

using namespace std;
class Curso {
	public:
		string nome;
		
		Curso() {
			cout << "Curso()" << endl;
		}
};

class Estudante {
	public:
		Curso curso;
		
		Estudante() {
			cout << "Estudante()" << endl;
		}
};

int main() {
	Estudante e;
	return 0;
}