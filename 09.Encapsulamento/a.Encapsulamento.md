Abstração
- simplificação de um problema difícil
- Representar características **essenciais** sem incluir os detalhes

Encapsulamento -> mecanimo que coloca juntos os dados e suas funções associadas, mantendo-os controlados em relação ao seu nível de acesso (visibilidade)
- proporciona abstração

Beneficios do encapsulamento:
no desenvolvimento:
- Melhor compreensão de cada classe
- facilita a realização 
- protege a integridade dos dados do Objeto
- reduz a chance de erros por parte 
na manutenção:
- interface deve ser o mais constante possível
- impacto reduzido ao modificar uma classe

## Introdução
escopo de uma variável
- região dentro da qual uma variável "existe"
- pode ser referencuada pelo nome

relação com a memória?
- define quando o sistema aloca e libera memória para a variável
- variáveis alocadas na pilha são liberadas ao sair do escopo
- variáveis alocadas no heap continuam lá mesmo fora do escopo

ex:
```cpp
class ClasseTeste {
	public:
		int var1;
		std::string var2;

		void metodo(int param) {
			int x = 1;
			int y = 9;
			
			if (param % 2 == 0) {
				int result = 12;
			}
		}
};
```
Quais escopos temos aqui?
	▪ Classe, Método, If
O que acontece quando:
- Entra/sai do if?
	- result entra/sai da pilha
- O método termina?
	- param,x e y saem da pilha
- A classe é destruída?
	- var1 e var2 saem da pilha

## Encapsulamento
O encapsulamento ocorre nas classes. É um conjunto de escopos que são estruturados dentro da classe.
Interface (contrato) e comportamento definidos pelos membros.
Definição baseada em **modificadores de acesso** (tem em linguagens de maneira geral)
- Public
- Protected
- Private
Os membros são declarados após o modificador. 
Checagem em tempo de compilação
### Public
Mais liberal. Determina que tudo que é definido nesse escopo podem ser acessados por qualquer outra parte do código.
Deve ser usado com muita responsabilidade!
De **maneira geral**: apenas métodos devem ser públicos. Atributos, não.
EX:
```cpp
class Ponto {
	public:
		int x;
		int y;
		
		Ponto(int x, int y) {
			this->x = x;
			this->y = y;
	}
};
```
### Protected
 > para saber mais sobre isso, é preciso entender herança. Isso será visto mais a frente
 
Os membros definidos neste escopo podem ser acessados dentro da própria classe e por outras classes que:
▪ Fazem parte da hierarquia (derivadas)
	▪ Com acesso público ou protegido (calma!)
▪ Classes “amigas” (friends)
	▪ Algo bem específico em C++
▪ Membros um pouco mais “reservados” que os públicos
 
EX:
```cpp
class Base {
	protected:
		int i = 99;
};

class Derived : public Base {
	public:
		int f() {
			i++; // pode só pq tem herança
			return i;
		}
};

int main() {
	Base b;
	// cout << b.i << endl; -> da erro de compilação!
	
	Derived d;
	cout << d.f() << endl; // funciona
	
	return 0;
}

```

### Private
O mais restritivo. Os membros definidos nesse escopo **só** podem ser acessados por métodos da mesma classe
Deve ser empregado sempre que possível. Utilizar métodos auxiliares de acesso
Se não declarar nada como modificador de acesso:
- struct -> public
- class -> private

```cpp
class Ponto {
	private:
		int _x;
		int _y;
	
	public:
		Ponto(int x, int y) : _x(x), _y(y) {}
};
```
EX 2:
```cpp
class Base {
	int i = 99;
};

class Derived : public Base {
	public:
	int f() {
		i++; // isso da ERRO! Não tem acesso
		return i;
	}
};

int main() {
	Base b;
	cout << b.i << endl; // isso da erro! Não tem acesso

	Derived d;
	cout << d.f() << endl;
	
	return 0;
}
```

- Não é possível chamar um construtor que está no escopo private
	- Deixar sempre o construtor fora do private
	- Ou criar um auxiliar
		-  utilizar membro estático
		- assim, é possível acessar através do tipo

```cpp
class Ponto {
	private:
		int _x;
		int _y;
		
		Ponto(int x, int y) : _x(x), _y(y) {}
	public:
	
	static void metodo(){
	Ponto ponto(1, 1);
	}
};

int main(){
	Ponto::metodo(); // isso funciona!
}
```
- ver sobre singleton

## Acessando
De preferência, atributos devem ficar em private
Assim, para modificar e ver eles, utilizar métodos
- melhor controle das alterações
- acesso centralizado (programação defensiva)

- **Get** - método usado para consultar (obter) atributos
- **Set** - método usado para alterar (definir) atributos

```cpp
class Ponto {
	private:
		double _x;
		double _y;
	
	public:
		Ponto(double x, double y) : _x(x), _y(y) {}

		void setX(double x) { this->_x = x; }
		void setY(double y) { this->_y = y; }

		double getX() { return this->_x; }
		double getY() { return this->_y; }
};
```

Há exceções!
- Booleanos -> utiliza prefixo "is" 
- Coleção -> métodos de adicionar, remover membros específicos

Usar static faz também com que ocupe menos espaço