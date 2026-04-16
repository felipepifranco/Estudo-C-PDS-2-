#include <iostream>

using namespace std;


class Animal { // não pode mais ser instanciado (ERRO DE COMPILAÇÃO!)
	public:
		string nome;
		virtual void fale() = 0;
// Podemos ter tb um construtor e métodos que manipulam o atributo nome
// o construtor serve apenas para a classe filha chamar o construtor
};

class Gato : public Animal {
	public:
		void fale() {
			cout << "Miau!" << endl;
		}
};

class Cachorro : public Animal {
	public:
		void fale() override {
			cout << "Au! Au!" << endl;
		}
		
};

int main() {
	Animal* lista[5];
	
	for(int i=0; i<5;i++) {
		if (i % 2 == 0)
			lista[i] = new Cachorro();
		else
			lista[i] = new Gato();
	}
	
	for(int i=0; i<5; i++)
		lista[i]->fale();
	return 0;
}