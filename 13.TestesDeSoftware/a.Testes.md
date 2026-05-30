Modificar um programa é difícil: pode gerar novos erros, modificar cadeias de eventos. Pode ser mais difícil do que implementar do 0. Para isso, é importante **testar** o código **durante** o desenvolvimento.

# Teste
Um teste de software é uma atividade responsável por avaliar as capacidades de um programa, verificando se esse alcança os resultados esperados

> o que fazer para tentar **quebrar** o programa?

Assim, o teste tem a função de 
- detectar problemas mais rapidamente 
- diminuir os erros que chegam para o usuário final
- fazer uma modelagem mais precisa

Lembre que testar é **diferente de depurar**! O teste indica que tem um erro, enquanto a depuração serve para identificar a **fonte** do erro
## Princípios
Um bom teste identifica erros. Note que um teste não achar erros não indica a falta de erros!

## Métodos de teste
- black box: 
- white box:
## Tipos de testes
- Testes de unidade: feito durante a programação. Específico para cada módulo
- Testes de integração: feito durante o projeto, testa diferentes méto
- Testes de validação: requisitos
- Teste de sistema (End to end, user interface): todos os elementos
### Teste de unidade
Trecho de código feito pelo desenvolvedor que chama outro trecho de código para testá-lo. Quando o teste falha, ele achou um erro!

Uma unidade é o menor bloco de código testável (método ou trecho em código). O teste verifica **uma hipótese para um método** 

Casos de teste são um conjunto de inputs, condições de execução e os resultados esperados. Os casos podem ser:
- positivos: utilizar dados e condições esperados para demonstrar que o requisito é atendido
- negativos: utilizar dados e condições inaceitáveis, para testar se o código consegue lidar com eles (retornar erro, tratamento de excessão, etc)

também existem:
- casos bases: onde o código funciona com certeza
- casos edge: condições extremas, pouco esperadas mas válidas
- valores inválidos

Os testes devem ser:
- reproduzíveis: mesmos resultados sempre que executado
- isolados: testam apenas uma funcionalidade por vez e não dependem de outros testes
- completo: maior cobertura possível do código
#### Cobertura de código
Métrica **quantitativa** que avalia o grau que o código do programa é executado

### Framework Doctest
Framework utilizada para realizar testes.

- Fazer um arquivo para cada classe
- testar os métodos para casos bases, gerais, extremos e inválidos
- Pode colocar tudo em 1 teste case ou vários
	- normalmente 1 teste case por método

EX:

Factorial.hpp
```cpp
#ifndef FACTORIAL_H
#define FACTORIAL_H
int factorial(int n);
#endif
```

```cpp
#include "Factorial.hpp"

int factorial(int number) {
  if (number <= 1) {
	return number;
  } else {
	return number * factorial(number -1);
  }
}
```

```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Factorial.hpp"

TEST_CASE("Teste Factorial - Casos Base") {
  CHECK(factorial(0) == 0);
  CHECK(factorial(1) == 1);
  CHECK(factorial(2) == 2);
}

TEST_CASE("Teste Factorial - Casos Gerais") {
  CHECK(factorial(3) == 6);
  CHECK(factorial(5) == 120);
  CHECK(factorial(10) == 3628800);
}

TEST_CASE("Teste Factorial - Casos excepcionais") {
  CHECK_THROWS_AS(factorial(-2), ExcecaoEntradaNegativa); // cria excessão
}
```

Para compilar, faz-se:
```console
foo@bar:~$ whoami
foo
```

#### Coberturas de código
Existem ferramentas para encontrar áreas do código que não são executadas e testadas

Por exemplo, há o `gcovr`. Para usá-lo:
 1. Compilar todos os arquivos com o parâmetro “--coverage” (saída arquivos ‘.gcno’).
	 - `$ g++ -c --coverage Factorial.cpp`
	 - `$ g++ --coverage -o TesteFactorial TesteFactorial.cpp Factorial.o`
 2. Execute o arquivo executável (saída arquivos ‘.gcda’).
	 - `$./TesteFactorial` 
 3. Gerar o relatório em html*.
	 - `$ gcovr -r . --html --html-details -o relatorio.html 

Note que cobertura de código != cobertura de teste!
- **cobertura de teste:** Métrica qualitativa que visa medir a eficácia dos testes perante
os requisitos testados, avaliando se os casos de testes são “bons”