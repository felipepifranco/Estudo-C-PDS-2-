# Construtores
se um atributo não for inicializado na declaração do construtor, o compilador irá atribuir algum valor antes de entrar no construtor.
```cpp
class Estudante {
	public:
		int matricula;
		
		Estudante() {
			cout << matricula << endl;
			matricula = 2020123456;
			cout << matricula << endl;
			cout << "Estudante()" << endl;
		}
};
```


```cpp
class Curso {
	public:
		string nome;
		
		Curso() {
			cout << "Curso()" << endl;
		}
};

class Estudante {
	public:
		Curso curso; // funciona pq o construtor não recebe parâmetros
		
		Estudante() {
			cout << "Estudante()" << endl;
		}
};

int main() {
	Estudante e;
	return 0;
}
```
imprime:
> Curso()
> Estudante()

Isso ocorre pois primeiro ele tenta criar curso e, só depois, cria estudante. Assim, é possível notar que ele inicializa os atributos antes de inicializar o construtor. Então, tomar cuidado quando **construtor de classe usada de atributo tem parâmetro**, pois o construtor padrão não existe mais.

Para isso, é preciso definir a **lista de inicialização**
- colocar o **nome do atributo** após a chamada do construtor
- usar ":" para iniciar a lista de inicialização
- passar os devidos parâmetros necessários

Note que:
- tenta sempre chamar o default
- usa a lista de inicialização (resolve o problema de não ter um default)
- inicializa na ordem da lista
```cpp
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
```
imprime:
> Curso(PDS2)
> Estudante()

# Herança simples
## Construtores
- Uma subclasse possui suas propriedades e as da classe base
- A duas (ou mais) partes precisam ser construídas, e agora?
-  A parte base sempre é construída antes da derivada
- Classe filha executa o construtor do pai antes do próprio
	- Chamado mesmo que implicitamente (padrão)
	- Pode estar explícito na lista de inicialização (se necessário)

```cpp
#include <iostream>
using namespace std;

class Pessoa {
  public:
    string nome;
    Pessoa() {
      cout << "Pessoa()" << endl;
    }
};

class Estudante : public Pessoa {

  public:

    int matricula;

    Estudante() {

      cout << "Estudante()" << endl;

    }

};

  

int main() {

  Estudante e;

  return 0;

}

```

imprime:
> Pessoa()  
> Estudante()

O compilador sabe chamar implicitamente o construtor padrão (não declarado) ou sem parâmetros.

EX:

```cpp
class Base {
	public:
		int var_base;
		Base(int vb) : var_base(vb) {};
};

class Derivada : public Base {
	public:
		int var_derivada;
		Derivada(int vb, int vd) : Base(vb), var_derivada(vd) {}; // só funciona por causa disso!
		// porém, note que não há mais construtor padrão!
};

int main() {
	Base base(55);
	cout << base.var_base << endl;
	Derivada derivada(77, 99);
	cout << derivada.var_base << endl;
	cout << derivada.var_derivada << endl;
	return 0;
}
```
imprime:
> 55  
> 77  
> 99

## Destrutores
- nem sempre é necessário
- é ideal para quando se aloca memória a mais ou se quer um comportamento específico

- A parte base sempre é destruída depois da derivada
- Classe filha executa o destrutor do pai depois do próprio
	- Não recebe parâmetros, logo, não pode ser sobrecarregado

EX:
```cpp
class A {
	public:
		A() { cout << "A()" << endl; }
		~A() { cout << "~A()" << endl; }
		};

class B : public A {
	public:
		B() { cout << "B()" << endl; }
		~B() { cout << "~B()" << endl; }
};

class C : public B {
	public:
		C() { cout << "C()" << endl; }
		~C() { cout << "~C()" << endl; }
};

int main() {
	cout << "Alocando B:" << endl;
	B b1;
	
	cout << "Alocando C:" << endl;
	C* c1 = new C();
	
	cout << "Deleting C:" << endl;
	delete c1;

	cout << "Quitting..." << endl;
	return 0;
}
```
imprime:
> Alocando B:  
> A()  
> B()  
> Alocando C:  
> A()  
> B()  
> C()  
> Deleting C:  
> ~C()  
> ~B()  
> ~A()  
> Quitting...  
> ~B()  
> ~A()  

# Classes Abstratas
```cpp
class Animal {
	public:
		string nome;
		
		virtual void fale() {
			cout << "Fale padrao!" << endl;
		};
};

class Gato : public Animal {
	public:
		void fale() override {
			cout << "Miau!" << endl;
		}
};

class Cachorro : public Animal {
	public:
		void fale() override {
			cout << "Au! Au!" << endl;
		}
};
```

- Você sabe parte do comportamento desejado
- Não irá implementar objetos nem utilizar os métodos
	- método que quer ser redefinido -> interface

Usar as **classes abstratas**
- Você sabe parte do comportamento desejado
- Definem um conjunto de métodos
	- Totalmente implementados (lógica)
		- Apenas com a especificação do contrato
- Pelo menos uma função virtual pura
	- Quando é usado um especificador-puro (f() = 0)
- Classes abstratas não podem ser instanciadas
	- Apenas classes concretas podem ser instanciadas

```cpp
class Animal { // não pode mais ser instanciado (ERRO DE COMPILAÇÃO!)
	public:
		string nome;
		virtual void fale() = 0;
// Podemos ter tb um construtor e métodos que manipulam o atributo nome
// o construtor serve apenas para a classe filha chamar o construtor
};

class Gato : public Animal {
	public:
		void fale() override {
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
			lista[i] = new Cachorro(); // so imprime metodo de Cachorro pois método fale é virtual e o objeto é um ponteiro
		else
			lista[i] = new Gato();
	}
	
	for(int i=0; i<5; i++)
		lista[i]->fale();
	return 0;
}
```
imprime:
>Au! Au!  
> Miau!  
> Au! Au!  
> Miau!  
> Au! Au!

Note que:
- se herdar método virtual puro de uma classe, a classe também se torna virtual
- é possível ter uma parte base e uma parte abstrata

> Lembrete  
> "virtual" significa que pode ser sobrescrito    
> "virtual puro" significa que PRECISA ser sobrescrito, já que a definição base não existe. Ela tem um =0 no fim


### Princípios de Abertura e fechamento (OCP)
As classes devem estar abertas para extensão (ser herdada), mas devem ser fechadas para modificação. Ou seja, classes não deveriam ser modificadas, apenas **estendidas**
## Interfaces
Classe  abstrata que só apresenta métodos virtuais puros.
- Em outras linguagens, pode ser diferente, como O Java e implements
ex:
```cpp
class IPrintable {
	public:
		virtual void print() = 0;
};

class ExcelFile : public IPrintable {
	public:
		virtual void print() override {}
};
```

- **Princípio da Inversão de Dependência (DIP)** -> Você deve priorizar usar (depender) apenas da abstração e não de uma implementação concreta
	- comportamento especificado nas classes filhas

# Herança múltipla
Uma subclasse herda de várias superclasses
- nem todas as linguagens permitem isso

### Problemas 
- Dificulta a manutenção
- Dificulta o entendimento
- Reduz a modularização

### Ambiguidades
ex: 
![[Pasted image 20260414154109.png]]

```cpp
class Animal {
	public:
		Animal() { cout << "Animal()" << endl; }
};

class Herbivoro : public Animal {
	public:
		Herbivoro() { cout << "Herbivoro()" << endl; }
};

class Carnivoro : public Animal {
	public:
		Carnivoro() {cout << "Carnivoro()" << endl;}
};

class Onivoro : public Herbivoro, public Carnivoro {
	public:
		Onivoro() {cout << "Onivoro()" << endl;}
};

int main() {
	Onivoro o;
}
```
Animal()
Herbivoro()
Animal()
Carnivoro()
Onivoro()

- A onívoro será associado dois objetos de animal

#### Estudo do caso:
Se `Animal` tiver um `int a;` que é `a = 1` em `Carnivoro` e `a = 0` em `Onivoro`

- Ao pedir print de a (`cout << o.a << endl;`) dá erro!
	- ocorre pois há duas instâncias de a

#### Solução 1
- Para evitar, é possível fazer:
```cpp
cout << o.Herbivoro::a << endl;
cout << o.Carnivoro::a << endl;
```
mas esse comportamento pode não er o desejado

#### Solução 2
- Para evitar, é possível fazer **virtual inheritance** -> forçar a criar apenas uma instância da classe pai (`Animal`)
```cpp
class Animal {
	public:
		int a;
		Animal() { cout << "Animal()" << endl; }
};

class Herbivoro : virtual public Animal { // note o virtual!
	public:
		Herbivoro() { a = 0; cout << "Herbivoro()" << endl; }
};

class Carnivoro : virtual public Animal { // note o virtual!
	public:
		Carnivoro() { a = 1; cout << "Carnivoro()" << endl; }
};

class Onivoro : public Herbivoro, public Carnivoro {
	public:
		Onivoro() { cout << "Onivoro()" << endl; }
};

int main() {
	Onivoro o;
	cout << o.a << endl;
	cout << o.Herbivoro::a << endl;
	cout << o.Carnivoro::a << endl;
}
```
Imprime:  
Animal()  
Herbivoro()  
Carnivoro()  
Onivoro()  
1  
1  
1

como carnivoro foi criado foi por último, fica com o valor dele

#### Caso 4
```cpp
class Animal {
	public:
	virtual void Comer() { cout << "Tudo" << endl; }
};

class Herbivoro : virtual public Animal {
	public:
		void Comer() override { cout << "Planta" << endl; }
};

class Carnivoro : virtual public Animal {
	public:
		void Comer() override { cout << "Carne" << endl; }
};

class Onivoro : public Herbivoro, public Carnivoro {
};
	int main() {
	Animal *a = new Onivoro();
	a->Comer();
};
```

ambiguidade do método comer!

#### Solução
É preciso redefinir na classe onívoro
	- se não fizer isso, da erro de compilação
```cpp
class Animal {
public:
	virtual void Comer() { cout << "Tudo" << endl; }
};

class Herbivoro : virtual public Animal {
public:
	void Comer() override { cout << "Planta" << endl; }
};

class Carnivoro : virtual public Animal {
public:
	void Comer() override { cout << "Carne" << endl; }
};

class Onivoro : public Herbivoro, public Carnivoro {
public:
	void Comer() override { cout << "Planta e Carne" << endl; }
};

int main() {
	Animal *a = new Onivoro();
	a->Comer();
};
```
