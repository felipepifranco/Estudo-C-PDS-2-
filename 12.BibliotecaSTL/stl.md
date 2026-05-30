Bibliotecas server para reutilizar códigos já prontos e não precisar escrever tudo "do zero". Elas são um conjunto de implementações de uso gerão, possuindo interface e comportamentos bem definidos (documentação)

A biblioteca padrão de C++ possui diversos tipos. As funcionalidades da biblioteca podem ser usadas com o `#include`. A biblioteca padrão é definida em um namespace (std)

A biblioteca padrão de C também pode ser usada (cstdlib)

Para fazer uso de uma parte da biblioteca padrão, basta incluir a ferramenta e, ao utilizar um tipo dele, usar o namespace  `std::`  na chamada. Por exemplo:

```c++
#include <iostream>

int main() {
	std::cout << "Hello world!" << std::endl;
	return 0;
}
```

Ao fazer `using namespace std` carrega toda a biblioteca, o que não é boa prática.

# Standard Template Library
Parte da ISO C++ Standard Library. Apresenta soluções para problemas que envolvem estruturas de dados. Os componentes principais são:
- containers: representa como os dados são armazenados
- iteradores: generalização de ponteiros (apontam para um elemento de container)
- algoritmos: procedimentos aplicáveis a containers

STL possui **programação genérica**: a mesma definição de função atua sobre diferentes tipos. Para utilizar, basta passar o tipo da variável como parâmetro (**Polimosfismo paramétrico**).

### Ex
```cpp
struct NodeI{
	int data;
	NodeI* next;
}

struct NodeA{
	Aluno data;
	NodeA* next;
}
```

Note que precisamos declarar duas vezes algo similar por conta do tipo. Assim, é possível usar um **template**:

```cpp
template <typename T> class NodeG{
	T data;
	NodeG* next;
}
```

( isso será mais detalhado em polimorfismo)

# Containers
Estruturas de dados que armazenam coleções de elementos de **mesmo tipo**. Podem ser tipos primitivos ou definidos pelo programados. Praticamente todos os TADs são containers

O uso de containers permite o acesso uniforme aos dados (contrato). Isso permite a reutilização.

Eles armazenam dados **por valor**.

Permite recuperação de dados baseado em:
- Índice (n-ésimo elemento)
- Valor (Elemento com valor x)
- Propriedades (Elemento com com "idade" > 18)

Vantagens:
- boa organização de dados
- padronização
- implementação correta, eficiente e bem documentada

Os containers podem ser de diferentes tipos

## Sequenciais
- Vector
- Deque
- List

São aqueles que mantem a ordem dos elementos baseados na ordem que foram inseridos. Usam arrays tradicionais ou listas encadeadas.

Não é preciso definir o tamanho imediatamente (alocação dinâmica)

Exemplos de funções:
- `front()`, `back()`
- `push_back()`, `pop_back()`
- `size()`, `empty()`

### Vector
Array genérico e dinamicamente redimensionáveis. Um dos mais simples

Vantagens:
- Acesso individual aos elementos (índice)
- Adição/remoção de elementos no final
	- no meio é possível, mas tem maior custo
- Percorre em uma ordem específica 

```cpp
#include <iostream>
#include <vector> // include de especificação

int main() {
	std::vector<int> v = {7, 5, 16, 8}; //informa o container e o tipo a ser armazenado
	
	v.push_back(25); // adicionando elementos no fim da sequencia
	v.push_back(13);

	for(int n : v) {
		std::cout << n << std::endl;
	}

	return 0;
}
```

- Também é possível tipos novos
- É possível acessar elementos do vetor com `vetor[i]` ou `vetor.at(i)`

### List
Lista duplamente encadeada. O acesso não é por índicie, mas sim por **iterador**. A remoção/adição é mais eficiente, considerando que já se sabe a posição e que não é necessário mover outros elementos

```cpp
#include <iostream>
#include <list>

int main() {
	std::list<int> l = {7, 5, 16, 8};
	
	// Adicionar um número inteiro no início (frente) da lista
	l.push_front(25);
	// Adicionar um número inteiro no final da lista
	l.push_back(13);
	
	for (std::list<int>::iterator it=l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
	
	return 0;
}
```

É possível fazer coleções de tipos e coleções de ponteiros:

```cpp
#include <iostream>
#include <list>

struct TAD {
	int x;
};

int main() {
	std::list<TAD> lista_ref;
	std::list<TAD*> lista_ptr;
	
	TAD t1;
	t1.x = 10;
	lista_ref.push_back(t1);

	TAD* t2 = new TAD();
	t2->x = 20;
	lista_ptr.push_back(t2);

	t1.x = 99;
	t2->x = 99;
	std::cout << lista_ref.front().x << std::endl; // imprime 10, pois faz cópia
	std::cout << lista_ptr.front()->x << std::endl; // imprime 99, pois é ponteiro

	return 0;
}
```
### Qual usar?
**Vector**: 
- tipos de sequência que deve ser usado por padrão
- muitos acessos em posições aleatórias da sequência (através de índice)
**List**:
- muitas inserções e remoções que não serão feitas no fim

Apresentam também custo computacional, mas isso será cobrado em outra disciplina.
## Associativos
- Set
- Map
- Multiset
- Multimap

Mantém uma organização interna, independente da ordem de inserção. Fazem uso de árvores binárias de pesquisa para armazenar os dados

- Elementos não possuem ordem específica
- Suportam o acesso direto aos elementos usando chaves

Vantagens:
- `insert()`, `earase()`
- `find()`, `count()`

### Set
Guarda uma coleção de elementos **distintos**, não permitindo duplicatas. Assim, os elementos são comparáveis de acordo com algum critério. São ordenados.

- existem variações com elementos repetidos (multisets)

```cpp
#include <iostream>
#include <set>

int main() {
	std::set<int> s;
	for(int i = 10; i >= 1; i--) {
		s.insert(i); // insere inteiros de 1 a 10
	}
	
	s.insert(7); // não faz nada! 7 já está presente
	for(int i = 2; i <= 10; i += 2) {
		s.erase(i); // apaga os pares
	}
	
	std::cout << "(" << s.size() << ")" << std::endl;
	for (int e : s) {
		std::cout << e << std::endl;
	}
	return 0;
}
```


```cpp
#include <iostream>
#include <set>

int main() {
	std::set<int> s = {1, 3, 5, 7, 9};
	
	if(s.find(6) != s.end()) { // confere se o elemento está no conjunto
		//faz nada
	} else {
		s.insert(6);
	}

	if(s.insert(6).second) { // retorna um par, em que o segundo item informa se a inserção foi realmente feita
		// Element INSERTED in set
	} else {
		// Element NOT INSERTED in set
	}

	for (int e : s) {
		std::cout << e << std::endl;
	}
	return 0;
}
```

Para tipos novos, é preciso criar uma **função de comparação** e passar ela na declaração do set

```cpp
struct Pessoa {
	string nome;
	int idade;
} 

//comparador verifica apenas < (outros baseados nele)
// função especial do tipo functor
struct compara_pessoa_f {
	bool operator() (const Pessoa& p1, const Pessoa& p2) const{
		return p1.idade < p2.idade
		}
}

#include <iostream>
#include <set>
using namespace std;

int main() {
	std::set<Pessoa, compara_pessoa_f> pessoas;
	
	// essa inicialização não é recomendada! Só para simplificar:
	pessoas.insert({"Douglas", 30}); 
	pessoas.insert({"Pedro", 18});
	pessoas.insert({"Ana", 25});]
	
	for (Pessoa p : pessoas)
		std::cout << p.nome << std::endl;
	
	return 0;
}
```

- operator serve para ordenar os elementos. Se operator(p1, p2) é true, então p1 vem antes de p2
- ele testa o normal e o inverso. Se ambos forem false, ele não insere, já que não permite duplicatas
- é possivel fazer comparações compostas (se uma falhar, faz a outra)
### Map
Array associativo ou dicionário. É feito com um conjunto de pares: `<chave, valor>`

- uso de iteradores

```cpp
#include <iostream>
#include <string>
#include <map>

int main() {
	std::map<int,std::string> m;
	
	m.insert(std::pair<int,std::string>(2017123456, "Joao"));
	
	//é melhor usar insert/find
	m[2016123456] = "Maria";
	m[2018123456] = "Carlos";
	m[2015123456] = "Jose";
	m[2014123456] = "Joana";
	
	std::map<int,std::string>::iterator it;
	
	for (it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
	
	return 0;

```

### Quando usar?
**Set**:
- coleção de dados de chaves exclusivas, sem nenhum valor associado
- elemento não pode ser modificado
**Map**:
- coleção de dados de chaves exclusivas e algum valor associado
- não podemos modificar a chave, mas podemos alterar o valor
## Adaptadores
- Stack
- Queue
- Priority queue

# Iteradores
Obejetos usados para acessar os elementos armazenados. Eles **apontam** para itens que estão em um container. Podemos iterar sobre os elementos (percorrer)

ex de funções:
- `begin()`, `end()`

Exemplo de operações:
- `it++` -> incrementar
- `*it` -> acessar o elemento

Nem todos os containers superam iteradores e nem todos os iteradores suportam todas as operações!

ex:
```cpp
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	
	v.push_back(5);
	v.push_back(2);
	v.push_back(9);
	
	std::vector<int>::iterator it; // declaração do iterador a partir do tipo do container
	for (it = v.begin(); it != v.end(); ++it) // limites do iterador e como ele avança
		std::cout << *it << std::endl; // elemento atual apontado pelo iterador

	return 0;
}
```

Existe o operador `auto` que passa para o compilador a responsabilidade de definir o tipo de uma variável na inicialização. Usar com moderação!

ex:
```cpp
#include <iostream>
#include <string>
#include <map>
int main() {
	std::map<int,std::string> m;

	m[2017123456] = "Joao";
	m[2016123456] = "Maria";
	m[2018123456] = "Carlos";
	m[2015123456] = "Jose";
	m[2014123456] = "Joana";
	
	// uso do auto it em vez de std::map<int,std::string>::iterator it;
	for (auto it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
return 0;
}

```

É também possível abstrair um for fazendo um "for each _element_ of _container_" ( `for(type e : c)`). Mas isso faz uma cópia de cada elemento!
- usar um laço por referência para evitar cópia:  `for(type &e : c)`

ex:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> v;
	
	v.push_back(5);
	v.push_back(2);
	v.push_back(9);
	
	for (int i : v)
		std::cout << i << std::endl;
	return 0;
}
```

# Algoritmos
Procedimentos que podem ser aplicados a containers. Eles são aplicados em um determinado **intervalo** de elementos
- range: qualquer sequência que pode ser acessada por iteradores ou ponteiros: `algorithm(begin, end, ...)`
- note que o range é intervalo semiaberto: `[first, last)`
	- first é incluído, last não!
	- last é o elemento exatamente após o range desejado
	- `begin()` aponta para o primeiro e `end()` aponta para a posição após o último.

Existem 2 tipos de algoritmos:
- não modificam os containers: `find()`, `count()`, `max_element()`
- fazem alguma alteração no container: `sort()`, `swap()`, `reverse()`

Ex:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> v = {23, 7, 5, 16, 8, 1, 12, 20, 10};
	
	for(int &n : v)
		std::cout << n << std::endl;
		
	int max = *std::max_element(v.begin(), v.end()); // encontra o maior elemento do range (atente-se para o operador de deferencia)
	
	std::cout << "Max: " << max << std::endl;
	std::cout << "Sort:" << std::endl;
	std::sort(v.begin(), v.end()); // ordena os elementos
	
	for(int &n : v)
		std::cout << n << std::endl;
	
	return 0;
}
```

se quiser mudar o intervalo, susbtituir o `end()` ou `start()` pelo ponteiro de 5 posições:
`v.end() -5`, por exemplo