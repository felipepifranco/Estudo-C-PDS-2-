# Programação defensiva
Abordagem de desenvolvimento de software que visa escrever um código que seja mais robusto seguro e capaz de lidar com situações inesperadas ou entradas inválidas. O
objetivo é minimizar os erros e falhas durante a execução do programa, melhorando sua confiabilidade e manutenção.

- **Robustez**: garantir que o software continue operando, mesmo que isso leve a resultados imprecisos
- **Corretude**: nunca retornar um resultado impreciso. Não retornar é melhor do que errar

Depende qual deve ser priorizado.

**Estratégias:**
- validação das entradas
- asserções
- programação por contato
- barricadas
- **tratamento de exceções**

# Tratamento de exceções
Exceção é um evento inesperado que ocorre no contexto da execução do programa (não necessariamente lógico). É importante **tratar e gerenciar** esses eventos. Eles demandam **alteração no fluxo** de execução

O que pode erar exceções: erros de código, entradas inválidas, falhas de hardware
- timeout ao enviar dados pela rede
- abrir um arquivo existente
- acessar posição inválida em um vetor
- divisão por zero

### Como tratar
- Ignorar: é um alarme falso, continuar a execução
- Reportar: escrever uma mensagem na tela/arquivo
- Reparar: corrigir e tentar se recuperar (prosseguir)
- Terminar: interromper completamente a execução

Definir valor de uma variável global

## Exceções
maneira estruturada de informar/tratar que o programa (rotina) não deve (pode) continuar a executar
- Sinalização da existência de um problema
	- é criada uma **variável que representa a exceção**
	- a exceção (variável) deve então ser "lançada"
	- o código é **desviado** do fluxo normal de execução
- Tratamento
	- a **captura** da exceção é feita e um comporta é escolhido
### Em C++

- throw -> sinalização da exceção
	- sempre dentro de um try
	- se nada tratar (catch), o programa terminará
- catch -> captura da exceção

- As exceções são definidas como classes (ou outro tipo)
	- previamente instanciado (raro) ou na hora do lançamento
- Podem ser pré-definidas ou criadas pelo programador
- contém informações sobre o erro

```cpp

double metodo(double d) {
	if (d > 1e7) {
		throw std::overflow_error("Valor acima do esperado!");
	}
	return d*d;
}

int main() {
	try {
		double x = metodo(1e10);
		std::cout << x << std::endl;
	} catch (std::overflow_error& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
}

```

#### Stack Unwinding
Stack Unwinding (desenrolamento da pilha): quanto há uma exceção em uma chamada de função, ele faz o desenrolamento da pilha:
- Procurar primeiro catch apropriado para tratar a exceção
- Variáveis no escopo entre o throw e o catch são destruídas (incluindo a própria função)
	- atentar com vazamento de memória!
- execução continua a partir desse catch encontrado

```cpp
class ClasseB {
	public:
	ClasseB() { cout << "Construtor::B" << endl; }
	~ClasseB() { cout << "Destrutor::B" << endl; }
	void metodoB() {
		throw exception(); // classe pai, aceita qualquer excessão
		// não aceita passar o .what()
	}
};

class ClasseA {
	public:
	ClasseA() { cout << "Construtor::A" << endl; }
	~ClasseA() { cout << "Destrutor::A" << endl; }
	void metodoA() {
		ClasseB b;
		b.metodoB();
	}
};

int main() {
	try {
		ClasseA a;
		a.metodoA(); // gera exceção!
		// sai de metodoB, destruindo
		//sai de metodoA, destruindo
		// acha o catch e executa
	} catch(exception& e) {
		cout << e.what() << endl;
	}
}
```

imprime:
```console
Construtor::A
Construtor::B
Destrutor::B
Destrutor::A
std::exception
```

- algumas linguagens possuem um comando `finally` para garantir que algumas partes sejam executadas mesmo com exceção (para delete e afins)
- C++ não possui isso!
	- Responsabilidade do programador
	- stl vectors, smart pointers, etc

### Exceções múltiplas
Um método pode lançar *diferentes tipos de exceções*, e um bloco try pode ter *vários blocos catch associados a ele*

O bloco será selecionado pelo tipo de exceção
- será usado o primeiro tratador com o mesmo tipo da exceção
- C++ possui **hierarquia de exceções** pré-definidas

| Exception            | Description                                                         |
| -------------------- | ------------------------------------------------------------------- |
| `std::exception`     | it is an exception and parent class of all standard C++ exceptions. |
| `std::logic_failure` | It is an exception that can be detected by<br>reading a code.       |
| `std::runtime_error` | It is an exception that cannot be<br>detected by reading a code.    |
| `std::bad_exception` | It is used to handle the unexpected<br>exceptions in a c++ program. |
| `std::bad_cast`      | This exception is generally be thrown<br>by dynamic_cast.           |
| `std::bad_typeid`    | This exception is generally be thrown<br>by typeid.                 |
| `std::bad_alloc`     |  This exception is generally be thrown<br>by new.                   |

### Tratamento
Como tratar esse erro?
```cpp
int factorial(int n) {
	if (n < 0)
		throw std::invalid_argument("Não existe fatorial de n < 0.");
	if (n >= 20)
		throw std::overflow_error("Não consigo computar para n >= 20.");
	if(n <= 1)
		return 1;
	return n * factorial(n-1);
}

int main(){
	int x;
	std::cin >> x;
	try{
		std::cout << factorial(x);
	}
	catch(std::invalid_argument &e){
		std::cout << e.what() << std::endl;
	}
	catch(std::overflow_error &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Tratada!" << std::endl;
	
	return 0;
}
```

Note que é possível fazer, de maneira genérica:
```cpp
int main(){
	int x;
	std::cin >> x;
	try{
		std::cout << factorial(x);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Tratada!" << std::endl;
	
	return 0;
}
```

- Também é possível ter **Os dois níveis de exceção** (Usar tanto tipo específico quanto exception)
	- Se tiver mais uma cláusula `catch`, devem estar ordenadas do tipo **mais específico** para o **mais genérico**
	- deixa o exception por último

## Criando as próprias exceções
Em C++, é possível criar exceções de qualquer tipo. Porém, é usual criar exceções especializadas usando OO
- Herdar de `std::exception` (ou subclasse)
- sempre que puder, usar as mais específicas

```cpp
class ExcecaoSaldoInsuficiente : public std::exception {
	public:
	double info;
	ExcecaoSaldoInsuficiente(double saldo) :info(saldo){}
	
	// reescreve o método what()
	virtual const char* what() const throw() {
		return "Erro: SaldoInsuficiente.";
	}
};

class Conta {
	int _agencia; int _numero; double _saldo = 0;
	
	private:
	bool possuiSaldoSuficiente(double valor) {
		return (_saldo - valor) >= 0;
	}
	
	public:
	void sacar(double valor) {
		if (!possuiSaldoSuficiente(valor)) {
			throw ExcecaoSaldoInsuficiente(_saldo);
		}
	this->_saldo -= valor;
	}
};
```

```cpp
int main() {
	try {
		Conta c;
		c.sacar(100);
	} catch (ExcecaoSaldoInsuficiente& e) {
		std::cout << e.what() << std::endl;
		std::cout << e.info() << std::endl;
	}
	return 0;
}
```

### Exceção não herdada
```cpp
class MinhaExcecao {
	public:
	std::string mensagem() {
		return "Erro: MinhaExcecao.";
	}
};

int main() {
	try {
		throw MinhaExcecao();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	} catch (...) { // pegar QUALQUER EXCEÇÃO 
		std::cout << "Excecao desconhecida!" << std::endl;
	}
	return 0;
}
```

## Propagação de exceção
 - Não se quer (ou sabe) tratar uma determinada exceção em um escopo (bloco catch) ou deseja-se fazer um tratamento parcial
 - "Relançar” (rethrow) a exceção capturada
 
 Para fazer isso, chamar novamente throw
- Não passar parâmetros (mesmo tipo do catch)
- Podem ser passados parâmetros, mas cuidado!
- Comportamentos inesperados (herança)
- Novos objetos de exceção gerados (cópia)

```cpp
class MyException : public std::exception { // nova exceção
	public:
	virtual const char* what() const throw() {
		return "Erro: MyException.";
	}
};

void metodoTeste() {
	try {
		throw MyException(); // dispara MyException
	} catch (MyException& e) { // pega ela
		std::cout << "Dentro -> " << e.what() << std::endl;
		throw; // propaga a exceção de novo! Permitindo ela pegar novamente em outro catch
		// se n propagasse, só trataria na função, não trataria na main
	}
}

int main() {
	try {
		metodoTeste();
	} catch (MyException& e) {
		std::cout << "Fora -> " << e.what() << std::endl;
	}
	return 0;
}
```

## Especificações de exceções
Indicar a intenção do programador sobre os tipos das exceções que podem ser lançadas por um método.

Em, C++, isso só é testado em tempo de execução, não de compilação

 Adicionadas às assinaturas dos métodos de C++:
 
-  C++11: throw() / throw(type)
```cpp
void f() throw(); // NÃO lança exceções
void f() throw(std::invalid_argument); // Se lançar, é desse tipo específico
```

- C++17: noexcept(true) / noexcept(false)
```cpp
void f() noexcept(true); // NÃO lança exceções
void f() noexcept(false); // Pode lançar alguma exceção
void f() throw(std::invalid_argument); // Se lançar, é desse tipo específico
```

EX:
```cpp
class Conta {
	int _agencia;
	int _numero;
	double _saldo = 0;
	
	private:
	bool possuiSaldoSuficiente(double valor) {
		return (_saldo - valor) > 0;
	}

	public:
	void sacar(double valor) throw() {
		if (!possuiSaldoSuficiente(valor)) {
			throw ExcecaoSaldoInsuficiente();
		}
	this->_saldo -= valor;
	}
};
```

## Possíveis problemas
- misturar outros tratamentos
- não entender o processo de stack unwinding
- lançar exceções nos destrutores
- não capturar exceções por referência
	- dispara por valor, captura por referência