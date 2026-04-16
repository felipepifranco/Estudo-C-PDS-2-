#include <iostream>

using namespace std;

class Curso {
	public:
		string nome;
	
		Curso(string nome) : nome(nome) { // nome surge como "nome"
			cout << "Curso(" << this->nome << ")" << endl;
		}
};

class Estudante {
	public:
		Curso cso;
	
		Estudante() : cso("PDS2") { // curso surge com o atributo nome = "PDS2"
			cout << "Estudante()" << endl;
		}
};

int main() {
	Estudante e;
	return 0;
}