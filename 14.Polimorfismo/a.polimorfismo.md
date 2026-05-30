Classes podem assumiur "múltiplas formas" no mesmo contexto. Objetos de **classes (tipos) diferentes** respondem a uma **mesma mensagem** (chamada) de diferentes maneiras

Polimorfismo:
- Universal
	- Paramétrico
		- Implícito
		- Explícito
	- Inclusão
- Ad-Hoc
	- Sobrecarga - métodos, operadores
	- Coerção

# Polimorfismo Univesal
## Paramétrico

### Implícito
- os tipos são identificados pelo compilador
- são passados implicitamente à função

```cpp
int get_max(int a, int b){
	return (a > b ? a :b);
}

string get_max(string a, string b){
	return (a > b ? a : b);
}
```

```cpp
template <typename T>
T get_max(T a, T b){
	return (a > b ? a : b)
}

int main(){
	int x =10, y = 99, r;
	r = get_max<int>(x, y);
	
	string a = "poggers", b = "W", c;
	c = get_max<string>(a, b);
	
	return 0;
}
```

> [!INFO] Atente-se aos operadores
> Para tipos que não possuem o operador bem definido, não é possível usar! (**Erro de compilação**) . É preciso declarar explicitamente o operador

### Explícitos
- Modela herança e subtipagem
	- redefinição (especialização) em classes descendentes

## Inclusão
- Programação de tipos **abstratos**
- Usar um tipo abstrato (classe abstrata, interface) ser utilizada sem conhecer a implementação concreta
	- independência de implementação
- **Mesmo nome para diferentes comportamentos**

```cpp
class Animal{
	public:
	virtual void fale(){
		cout << "Fale padrao!" << endl;
	}
};

class Cachorro : public Animal{
	public:
	void fale() override{
		cout << "Au Au" << endl;
	}
};

class Gato : public Animal{
	public:
	void fale() override{
		cout << "Miau Miau" << endl;
	}
};

int main() {
	Animal* c = new Cachorro(); // imprime "Au Au"
	c->fale();
	
	Animal* g = new Gato(); // imprime  "Miau Miau"
	g->fale();
}
```

Existem 2 tipos de ligação:
- Ligação prematura: decisões são feitas durante a compilação
	- padrão do C++
- Ligação tardia: decisões feitas durante a execução. Chave do polimorfismo!
	- só usado quando tem `virtual` e é um ponteiro

Note que é possível **interromper o `virtual`** ao não redefinir o método, procurando uma redefinição no pai até procurar. Isso pode ser feito de forma explícita também com `final`

```cpp
class C : public A {
	public:
	void m() overide final{
		cout << "C:m()" << endl;
	}	
	// nenhuma classe que herda de C poderá redefinir esse método
	// (daria erro de compilação)
}
```

# Ad-hoc
Ad-hoc (ou aparente) é quando a função ou tipo *parece* trabalhar com tipos diferentes e se comportar de formas diferentes para cada um desses tipos

Número finito de entidades diferentes
- todas com mesmo nome, mas **códigos distintos**
- para trabalhar com outro tipo é preciso alterar o código
## Sobrecarga
O **mesmo identificador** denota **diferentes funções** que operam sobre elementos distintos (diferentes **parâmetros**)

É resolvido esteticamente (em tempo ed compilação)
- difere no número e no tipo

```cpp
class Ponto {
	private:
	double _x;
	double _y;
	
	public:
	Ponto() : Ponto(-1.0, -1.0) {}
	Ponto(double xy) : Ponto(xy, xy){}
	Ponto(double x, double y) : _x(x), _y(y) {}
	
	void add(double n){
		this->_x +=n;
		this->_y +=n;
	}
	
	void add(Ponto& p){
		this->_x += p._x;
		this->_y += p._y;
	}
}
```

É possível fazer esse "add" de maneira mais intuitiva -> sobrecarga de operadores
### Sobrecarga de operadores
Método para permitir o uso de operadores com tipos próprios

```cpp
class Ponto{
	Ponto operator + (double n){
		Ponto aux;
		aux._x = this->_x +n;
		aux._y = this->_y +n;
		return aux;
	}
	
	Ponto operator + (const Ponto& p){
		Ponto aux;
		aux._x = this->_x +p._x;
		aux._y = this->_y +p._y;
		return aux;
	}
	
	bool operator == (const Ponto& p){
		return (this->_x == p.x && this->_y == p._y)
	}
};

// deve estar FORA da classe
ostream& operator << (ostream& os, const Ponto&){
	return os << "(" << p._x << "," << p._y << ")";
}


// o primeiro ponto de
```

## Coerção
Conversão automática de tipo
- usada para satisfazer o contexto atual
- considera a **definição** para escolher o **tipo**

Compilador possui mapeamento interno (primitivos)
- Widening (promoção) -> transformar variável menor em uma variável maior
- Narrowing (redução) -> transformar variável maior em menor
	- mais perigoso!
	- necessita de truncamento

```cpp
void f(double x){
	cout << x << endl;
}

int main(){
	f(3.1416); // 3.1416
	f((short) 2); // 2
	f('a'); // 97
	
	return 0;
}

```

```cpp
void sum(int a, int b){
	cout << "Soma de inteiros: " << (a + b) << endl;
}

void sum(double a, double b){
	cout << "Soma de doubles: " << (a + b) << endl;
}

int main(){
	sum(1,2); // Soma de inteiros: 3
	sum(1.1,2.2); // Soma de doubles: 3.3
	sum(1,2.2); // ERRO DE COMPILAÇÃO!!!!
	sum((int) 1.1, (int) 2.2); // Soma de inteiros: 3
}

// se tivesse só o primeiro caso, funcionaria, só faria conversão implícita para inteiro
```

### Conversão de tipo - Classe
#### Upcasting
Ocorre no sentido Subclasse -> superclasse
- feito automaticamente
- princípio de substituição de liskov

#### Downcasting
Ocorre no sentido **Superclasse -> Subclasse**
- Não é feito de maneira automática
```cpp
  ClasseBase *b = new ClasseDerivada(); // upcasting
  Classe *d = new (Classe Derivada*) b; // downcasting
```
- Nem sempre isso é válido
	- subclasse tem características específicas

```cpp
class ClasseBase {
	public:
	virtual void metodoA() { cout << "ClasseBase->MetodoA." << endl; }
};
	
class ClasseDerivada : public ClasseBase {
	public:
	int atributo;
	
	ClasseDerivada(int valor) : atributo(valor) { }
	
	void metodoA() override { cout << "ClasseDerivada->MetodoA" << endl; }
	void metodoB() { cout << atributo << endl; }
};
```

```cpp
int main() {
	ClasseBase *b = new ClasseDerivada(123);
	b->metodoA(); // "ClasseDerivada->MetodoA"
	b->metodoB(); // ERRO!

	ClasseDerivada *d = (ClasseDerivada*) b;
	d->metodoA(); // "ClasseDerivada->MetodoA"
	d->metodoB(); // 123
	
	delete d;
	return 0;
}
```

- Mas nem sempre a superclasse pode assumir o tipo da subclasse
	- Todo Gato é Animal, mas nem todo Animal é Gato
- Assim, C++ oferece mecanismos para fazer um downcasting "seguro"
- operador `dynamic_cast`
	- retorna um apontador nulo ou Exceção dependendo do caso
	- utilizado na **declaração** do objeto

```cpp
class Animal {
	public:
	virtual void fale() {
		cout << "Animal::fale()" << endl;
	}
};

class Cachorro : public Animal {
	public:
	void fale() override {
		cout << "Au au!" << endl;
	}
};

class Gato : public Animal {
	public:
	void fale() override {
		cout << "Miau!" << endl;
	}
};
```

```cpp 
int main() {
	Cachorro cao;
	cao.fale(); // au au
	
	Animal* p_ani = (Animal*) &cao;
	p_ani->fale(); // au au
	
	Cachorro* p_cao = (Cachorro*) p_ani;
	p_cao->fale(); // au au
	
	Gato* p_gato1 = (Gato*) p_ani;
	p_gato1->fale(); // au au
	
	Gato* p_gato2 = (Gato*) &cao;
	p_gato2->fale(); // au au
return 0;
}
```

```cpp
int main() {
Cachorro cao;
cao.fale();
Animal* p_ani = dynamic_cast<Animal*>(&cao);
if (p_ani != nullptr)
p_ani->fale();
if (Cachorro* p_cao = dynamic_cast<Cachorro*>(p_ani))
p_cao->fale();
if (Gato* p_gato1 = dynamic_cast<Gato*>(p_ani)) {
cout << "Essa chamada eh valida!" << endl;
p_gato1->fale();
} else {
cout << "Essa chamada NAO eh valida!" << endl;
}
try {
Gato& p_gato2 = dynamic_cast<Gato&>(*p_ani);
p_gato2.fale();
} catch (bad_cast& e) {
cout << e.what() << endl;
}
return 0;
}
```
