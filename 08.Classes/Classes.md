Classes representam uma **categoria de elementos**. 
- "Não existem" em contexto da execução
- Definem uma lógica estática (compilação)
- Relacionamentos entre classes não mudam
Objetos representam **itens em particular**
- Estado, comportamento, identidade
- relacionamentos entre objetos são dinâmicos

As classes suportam/utilizam conceitos de: abstração, encapsulamento, herança, polimorfismo (serão vistos depois).
- As structs são semelhantes, mas devem ser usadas apenas para guardar dados (atributos)

#### Abstração
Diz respeito a simplificação, separação entre conceitos e detalhes. É utilizar algo complexo sem entender o funcionamento

# Membros
### Membros de **instância**:
- espaço de memória alocado para **cada** objeto
- somente são chamados através do objeto

#### Atributos de instância:
- estado do objeto definido pelo valor dos atributos
- apresenta valores padrões (0 para numéricos, false para bool), mas não confiar!
- demais atributos não são automaticamente inicializados (ponteiros apontam para lixo)
	- programador deve criar valor default

EX:
```cpp
class Casa {
	public:
		int numero;
		string cor;
};

int main() {
	Casa c1;
	c1.numero = 77;
	c1.cor = "verde";
	
	Casa c2;
	c2.numero = 55;
	c2.cor = "vermelho";
	
	Casa c3;
	c3.numero = 11;
	c3.cor = "amarelo";
	
	return 0;
}
```
#### Métodos de instância
- Responsáveis por manipular o **estado do objeto**
	- dependem de uma instância para serem usados!
- Definem os comportamentos específicos (de acordo com as informações infdividuas do objeto).
- Podem alterar atributos se instância ou da classe (estáticos)
- Podem ser sobrecarregados e sobrescritos

O operador `this` serve para fazer referenciamento. É utilizado dentro de qualquer método **não estático** para acessar a posição de memória do objeto (instância) atual.
É usado mais para:
- informar a referência para o objeto atual
- evitar conflitos de nome
- facilitar a compreensão do código

EX:
```cpp
class Aluno; // declaração do tipo

class Curso {
	public:
		string nome;
		vector<Aluno*> alunos;

		void inserir_aluno(Aluno *aluno) {
			this->alunos.push_back(aluno);
		}
};

class Aluno { // definição do tipo
	public:
		int matricula;
		string nome;
		
		void fazer_inscricao(Curso &curso) {
			curso.inserir_aluno(this);
		}
};

int main() {
	Curso curso;
	curso.nome = "PDS2";
	
	Aluno aluno;
	aluno.matricula = 2020111222;
	aluno.nome = "Douglas";
	aluno.fazer_inscricao(curso);
	
	cout << "Alunos de " << curso.nome << ": " << endl;
	for (Aluno* aluno : curso.alunos)
		cout << aluno->matricula << "\t" << aluno->nome << endl;
	
	return 0;
}
```
**Métodos sobrecarrecados:**
- 2 ou mais métodos com o mesmo nome (polimorfismo)
- A lista de parâmetros (tipos) deve ser diferente
	- a ordem dos tipos de parâmetros é importante
EX:
```cpp
class Calculadora {
public:
    // Soma de inteiros
    int somar(int a, int b) { return a + b; } 

    // SOBRECARGA VÁLIDA
    double somar(double a, double b) { return a + b; }
    
	// SOBRECARGA VÁLIDA
    int somar(double a, int b) { return a + b; } 
    
    // SOBRECARGA VÁLIDA
    int somar(int a, double b) { return a + b; } 

    // SOBRECARGA VÁLIDA: 
    int somar(int a, int b, int c) { return a + b + c; }
    
    // SOBRECARGA INVÁLIDA:  compilador vê só tipo, não nome
    int somar(int c, int d) { return c + d; }
    
    // SOBRECARGA INVÁLIDA: compilador não vê tipo de retorno
    double somar(int a, int b) { return (double) a + b; }
    
    
};
```

### Membros de **classe** (estáticos):
- espaço de memória único para todos os objetos
- podem ser chamados mesmo sem um objeto

#### Atributos estáticos
Não estão associados a um objeto (instância)
- atributos de **Classe**
Atributos (valores) **compartilhados** pelas instâncias
- ocupam um espaço **único** na memória durante a execução
Geralmente utilizados para constantes

ACESSO DE NOME FEITO ATRAVÉS DA CLASSE
- não usar o `this`, já que não está associado a nenhum objeto
EX:
```cpp
class ClasseAtributoEstatico {
	public:
		static int numero;
		
		ClasseAtributoEstatico() {
			ClasseAtributoEstatico::numero++; // acesso 
		}

		void imprimirNumero () {
			cout << ClasseAtributoEstatico::numero << endl;
		}
};

int ClasseAtributoEstatico::numero = 0; // inicilização deve ser feita no arquivo.cpp, não no .hpp, pois isso geraria múltiplas definições (toda vez que desse include)



int main() {
	ClasseAtributoEstatico c1;
	c1.imprimirNumero(); // imprime 1
	
	ClasseAtributoEstatico c2;
	c2.imprimirNumero(); // imprime 2
	
	c1.imprimirNumero(); // imprime 2
	cout << ClasseAtributoEstatico::numero << endl; // imprime 2
	
	return 0;
}
```
#### Métodos estáticos
- Parecidos com funções globais 
	- não demandam uma instância da Classe
- Acessados diretamente pela Classe
- Muito utilizados em classes do tipo "Util"
	- classes com funções relacionadas
	- ex: Math

- Resolvidos em tempo de compilação
	- não dinamicamente como em métodos de instância que são resolvidos baseados no tipo do objeto em tempo de execução
- Não pode ser sobrescritos (herança)
- Dentro de métodos static (de classe) não se consegue acessar/usar atributos e métodos que são de instância

EX:
```cpp
class MathUtils {
	public:
		static double calcularMedia(double a, double b) {
			return (a + b)/2;
		}
};

int main() {
	cout << MathUtils::calcularMedia(10, 20) << endl;
	
	return 0;
}
```

# Construtores/destrutores
### Construtor
- Método chamado dura a *instanciação*
	- Classe declara **zero ou mais** construtores
	- Possui um construtor padrão  (sem parâmetros) da própria linguagem
- Devem possuir o mesmo nome da Classe
	- Selecionados através da lista de parâmetros
- Nunca declaram tipo de retorno

EX:
```cpp
class Ponto{
	public:
		int x;
		int y;
		
		Ponto(int x, int y){
			this->x = x;
			this->y = y;
		}
		
		Ponto(int xy){
			this->x = xy;
			this->y = xy;
		}
};
```

**Quando um novo construtor com parâmetros é declarado, o padrão não é mais acessível**
```cpp
int main() {
	//Ponto p1; -> NÃO É MAIS VÁLIDO
	Ponto p2(50, 50);
	Ponto* p3 = new Ponto(50);
	return 0;
}
```

É possível **reutilizar** construtores, delegando partes específicas
- definir um construtor como o "principal"
- útil para caso seja necessário renomear atributo
- considere o exemplo anterior, mas com um outro construtor:
```cpp
Ponto() {
	this->x = -1;
	this->y = -1;
}
```

Poderíamos construir os 3 dessa forma:
```cpp
class Ponto {
	public:
		int x;
		int y;
		
		Ponto() : Ponto(-1, -1) {}

		Ponto(int xy) : Ponto(xy, xy) {}
		
		Ponto(int x, int y) {
			this->x = x;
			this->y = y;
		}
};
```

### Destrutor
Método chamado para a finalização. Ele é **sempre** chamado:
- maneira explícita -> heap (`delete obj`)
- maneira implícita -> stack (sai do escopo / `return 0`)
	- nesse caso, é feito desempilhando, então lembrar do LIFO (last in first out)
Deve possuir o mesmo nome da classe (semelhante aos construtores), mas precedido por '~'

EX:
```cpp
class TestObject {
	public:
		int atributo;
		
		TestObject(int valor) : atributo(valor) {}
		
		~TestObject() {
			cout << "~TestObject" << atributo << endl;
		}
};

int main() {
	TestObject o1(1);
	TestObject* o2 = new TestObject(2);
	
	delete o2;
	return 0;
}
```
A saída será :
> ~TestObject2  
> ~TestObject1



## Exemplo
Como reimplementar o TAD Circunferência?
Perguntas:
- Quais as classes?
	- Ponto, Circunferência
- Quais os atributos e métodos?
	- Ponto -> x, y
	- Circunferência -> pontoCentro, raio, calcularArea
- Por onde começar?
	- Definir contratos -> .hpp

Ponto.hpp
```cpp
#indef PONTO_H
#define PONTO_H
Class Ponto {
	public:
		double _x;
		double _y;
		Ponto();
		Ponto(double x, double y);
	};
#endif
```
Circunferencia.hpp
```cpp
#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H
#include <cmath>
#include "Ponto.hpp"
class Circunferencia {
	public:
		Ponto* _centro;
		double _raio;
		
		Circunferencia(Ponto* centro, double raio);
		double calcularArea();
};
#endif
```
Ponto.cpp
```cpp
#include "Ponto.hpp"
Ponto::Ponto() : Ponto(0.0, 0.0) {}
Ponto::Ponto(double x, double y) : _x(x), _y(y) {}
```
Circunferencia.cpp
```cpp
#include "Circunferencia.hpp"
Circunferencia::Circunferencia(Ponto* centro, double raio) : _centro(centro), _raio(raio) {}
double Circunferencia::calcularArea() {
	return M_PI * pow(this->_raio, 2);
}
```
main.cpp
```cpp
#include <iostream>
#include "Ponto.hpp"
#include "Circunferencia.hpp"

using namespace std;

int main() {
	Circunferencia* c1 = new Circunferencia(new Ponto(), 10);
	cout << c1->calcularArea() << endl;
	
	Ponto p(5.0, 5.0);
	Circunferencia* c2 = new Circunferencia(&p, 10);
	cout << c2->calcularArea() << endl;
	
	delete c1;
	delete c2;
	
	return 0;
}
```