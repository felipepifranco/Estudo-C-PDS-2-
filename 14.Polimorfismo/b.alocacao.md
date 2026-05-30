# Alocação de memória
Polimorfismo estático:
- tempo de compilação
- ligação prematura (early/static binding)
- sobrecarga
- **mais eficiente**
- implementado com static dispatch


Polimorfismo **dinâmico**
- tempo de execução
- ligação tardia
- sobrescrita[[]]
- **mais flexível**
- implementado com dynamic dispatch
	- precisa de ser ponteiro e ter virtual

## Static vs Dynamic Dispatch
Method Dispatch: como a linguagem decide qual **implementação** usar

### Destrutores
```cpp
class ClasseBase {
	public:
	ClasseBase() {
	cout << "BASE Constructor..." << endl;
	}
	
	~ClasseBase() {
	cout << "BASE Destructor..." << endl;
	}
};

class ClasseDerivada : public ClasseBase {
	public:
	ClasseDerivada() {
	cout << "DERIVADA Constructor..." << endl;
	}
	
	~ClasseDerivada() {
	cout << "DERIVADA Destructor..." << endl;
	}
};

int main() {
	method();
	cout << "-----------" << endl;
	ClasseBase *b = new ClasseDerivada();
	delete b;
	return 0;
}
```

imprime:
```
BASE Constructor...
DERIVADA Constructor...
DERIVADA Destructor...
BASE Destructor...
-----------
BASE Constructor...
DERIVADA Constructor...
BASE Destructor...
```

Não chamou o destrutor da derivada! 

- **Destrutor** de classes base devem sempre ser virtuais
	- se pretende utilizar de maneira polimórfica e desalocar o objeto do tipo derivado
	- ocorre um static dispatch se não for virtual

 Tipo estático vs. Tipo dinâmico:
 - Tipo da variável declarada (contrato/referência)
- Tipo do objeto na memória (comportamento)

# Geral
é preciso gerenciar memória bem
- new / delete
- new[] / delete[]

Mau gerenciamento de memória:
- usar variáveis (posições de memória) não inicializadas
- alocar memória e não excluí-la quando necessário
- tentar acessar um valor que não é mais válido

Boas práticas
- sempre inicializar variáveis (verificar antes de usar)
- sempre liberar a memória após o uso
- certificar que o acesso existe

## Construtores
Os construtores fazem a inicialização dos membros após a alocação na memória. É baseado nos parâmetros informados na assinatura

O **construtor de cópia** recebe um objeto (referência) e copia os valores dos atributos. Pode ser padrão ou user-defined

Tipos:
- **Shallow copy**: apenas copia os valores/referências no novo objeto
- **Deep copy**: caso demandado, faz uma nova alocação antes da cópia.
	- quando se quer copiar um objeto que tem ponteiro, mas não quer apontar para o mesmo endereço

```cpp
class A {
	public:
	int campo;
	
	A(int n) : campo(n)
};

int main(){
	A a(2);
	A b = a; // construtor de cópia
}
```

O construtor de cópia é chamado quando:
- objeto é retornado ou passado por valor como argumento
- objeto construído com base em outro objeto
- compilador precisar gerar um objeto temporário

Usar o deep copy quando:

```cpp
class ClasseTeste{
	public:
	int x, *p;
	
	ClasseTeste(){
		this->p = new int; // não é destruído!	
	}
	
	void display(){
		cout << this->x << " " << *p << endl;
	}
}

int main(){
	ClasseTeste c1;
	c1.x = 10;
	*c1.p = 20;
	c1.display(); // 10 20
	
	ClasseTeste c2 = c1;
	*c2.p = 30;
	c2.display(); // 10 30
	
	c1.display(); // 10 30
}
```

```cpp
class ClasseTeste{
	public:
	int x, *p;
	
	ClasseTeste(){
		this->p = new int; // não é destruído!	
	}

	ClasseTeste(ClasseTeste &source){
		this->x = source.x;
		this->p = new int;
		*this->p = *source.p;
	}	
	
	void display(){
		cout << this->x << " " << *p << endl;
	}
}

int main(){
	ClasseTeste c1;
	c1.x = 10;
	*c1.p = 20;
	c1.display(); // 10 20
	
	ClasseTeste c2(c1);
	*c2.p = 30;
	c2.display(); // 10 30
	
	c1.display(); // 10 20
}
```

Essas duas implementações dependem do comportamento desejado!

**IMPORTANTE:** sempre que o **new** for utilizado, deve-se ser capaz de identificar quando a exclusão será feita (**delete**).

Formas de evitar:
- ocultar a alocação de memória em um resource handle
- passa a ser o responsável pelo gerenciamento
- ao ser destruído, ele deve excluir essa memória
- SmartPointers (C++ 11)

## Destrutores
podem ser responsáveis por desalocar qualquer memória dinâmica associada aos atributos da classe

Entenda os riscos: **nem sempre são chamados**
- remoção por ponteiro base, sem destrutor virtual
- lançamento de exceção no construtor
- término prematuro do programa (`exit`)

```cpp
class ClasseTeste {
	public:
	int *x, *p;
	
	ClasseTeste() {
		this->x = new int;
		if (this->x == nullptr) {
			cout << "Memoria insuficiente!" << endl;
			exit(1); // impede a destrução!
		}
	
		this->p = new int;
		if (this->p == nullptr) {
			cout << "Memoria insuficiente!" << endl;
		exit(1); // impede a destrução!
		}
	}
	
	~ClasseTeste() {
		delete this->x;
		delete this->p;
	}
};
```

## Rule of three
Se uma classe precisa que um (ou mais) dos seguintes membros seja definido pelo usuário, provavelmente deverá definir todos os 3:
- destrutor
- construtor de cópia
- operador de atribuição de cópia

```cpp
class Test {
	public:
	Test() {
		cout << "Constructor called." << endl;
	}
	~Test() {
		cout << "Destructor called." << endl;
	}
	Test(const Test &t) {
		cout << "Copy constructor called." << endl;
	}
	Test& operator = (const Test &t) {
		cout << "Assignment operator called." << endl;
		return *this;
	}
};

int main() {
	Test t1, t2; // chama o construtor padrão 2 vezes
	t2 = t1; // chama o operador de atribui
	Test t3 = t1; // chama o construtor de cópia, isso é igual a Test t3(t1)
	return 0; // chama o destrutor 3 vezes
}
```
imprime:
```console
Constructor called.
Constructor called.
Assignment operator called.
Copy constructor called.
Destructor called.
Destructor called.
Destructor called.
```

# Smart Pointer
TAD que simula um ponteiro tradicional
- sobrecarregam os operadores de ponteis (`->, *, =`)
- possui **gerencialmente automático de memória**
	- quando sai do escopo, a memória é desalocada automaticamente
- biblioteca std, acessar com `<memory>`
- usar com `unique_ptr<tipo> nome(new tipo)`

Tipos Principais:
- `std::unique_ptr`
	- apenas um recurso alocado dinamicamente
- `std::shared_ptr`
	- possui um recurso alocado compartilhado
	- mantém um contador inteirno com o número de ponteiros que possuem o mesmo recurso


```cpp
class ClasseA {
	public:
	int id;
	ClasseA(int id) : id(id) {
		cout << "ClasseA::Constructor:"<< this->id << endl;
	}
	~ClasseA() {
		cout << "ClasseA::Destructor:"<< this->id << endl;
	}
};
```

```cpp
#include <memory>
#include <iostream>
using namespace std;

int main() {
	ClasseA c1(1); // ClasseA::Constructor:1
	ClasseA *c2 = new ClasseA(2); // ClasseA::Constructor:2
	
	unique_ptr<ClasseA> c3(new ClasseA(3)); // ClasseA::Constructor:3
	cout << c3->id << endl; // 3
	
	return 0;
	// ClasseA::Destructor:3
	// ClasseA::Destructor:1
}
```

```cpp
int main() {
	unique_ptr<ClasseA> c1(new ClasseA(1));
	
	// unique_ptr<ClasseA> c2 = c1;
	// Compile Error : unique_ptr object is not copyable

	shared_ptr<ClasseA> c2(new ClasseA(2));
	shared_ptr<ClasseA> c3 = c2;

	cout << c2.use_count() << endl; //imprime 2

	c3 = nullptr;
	cout << c2.use_count() << endl; // imprime 1
	c2 = nullptr; // imprime ClasseA:Destructor2
	
	return 0;
}
```

### Mais algumas funções
- `Reset()` - liberar área de memória
- `Release()` - atribuir um smart pointer para um apontador normal
- “Deleter”
- Sobrecargas
- `std::make_unique`, `std::make_shared` (C++14) -> transformar um tipo em outro