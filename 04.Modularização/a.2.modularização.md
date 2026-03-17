# Modularização
Com o aumento no tamanho e complexilidade dos programas, é preciso facilitar o reuso e o entendimento do código e suas classes.  

Logo, pode-se agrupar elementos inter-relacionados, a fim de melhor compreender e manter o código. Isso se relaciona à técnica de **programação modular**, técnica de desenvolvimento que buscar organizar e separar aspectos da funcionalidade em módulos diferentes e intercambiaveis.  

### Módulo
- propósito único
- interfaceapropriada com outros módulos
- pode ser compilado separadamente
- reutilizável e modificável

*Quais classes devem ser agrupadas?*  
- classes na mesma hierarquia
- classes relacionadas por composição ("tem um")
- classes com muita colaboração (propósito comum)

(note que isso não é obrigatório)

### Princípios
Conceitos fundamentais para estruturar  

**Coesão**
- medida de grau de dependência entre elementos internos ao módulo
- funções, responsabilidades (mesmo objetivo)

**Acoplamento**
- grau de interdependência entre módulos
- alteração em um demanda alteração no outro

> **Buscar sempre alta coesão e baixo acoplamento!!**

## Reutilização
As bibliotecas foram criadas com os princípios da modularização.

Bibliotecas x frameworks
| Bibliotecas | Frameworks |
| ------------| -----------|
| conjunto de implementações ja prontas | conjunto de ferramentas que define a estrutura da aplicação |
| o códgido chama a biblioteca | a framework chama o código escrito e define o fluxo |
| "caixa de ferramentas" | "esqueleto de casa" |
| coleção organizada de funcionalidades uteis | atua como suporte para construção de programas
| o programa funcionna sem ela (precia reescrever) | programa vive dentro dela | 
| `math.hpp`, `string` | Unreal Engine, React |

## Implementação
### Namespace
define uma região declarativa. Delimitador abstrato que fornece um contexto para os item que armazena (tipos, funções, variáveis)

Organizam em grupos lógicos

Ele pode ser declarado através de um bloco
```c++
#include <iostream>

namespace Modulo1 {

  class ClasseA{
    public:
      ClasseA(){
        std::cout << "Modulo1::ClasseA" << std::endl;
      }
  };
}

namespace Modulo2 {

  class ClasseA{
    public:
      ClasseA(){
        std::cout << "Modulo2::ClasseA" << std::endl;
      }
  };
}
```

> é possível fazer namespaces aninhados!

Para utilizar um elemento de um namespace em outro, é preciso especificar o caminho do namespace (do global até ele)

```c++
int main(){
  Modulo1::ClasseA c1;
  Modulo2::ClasseA c2;
}
```

É possível incorporar tudo de um namespace para o escopo atual utilizando o `using namespace`

É possível "redeclarar" um namespace de modo que o novo elemento declarado seja incorporado
```c++
namespace Modulo1{
  class ClasseB {
    public:
      ClasseB(){
        std::cout << "Modulo1::ClasseB" << std::endl;
      }
  };
}
```

### Compilação
Em sistemas grandes, código estará distribuido em vários arquivos fontes. Logo, não é conveniente recompilar partes do proograma que não foram alteradas

**Especificações (interface) x Implementação:**
- arquivo `.hpp` -> contém a **especificação** das funçõe se tipos de dados. è a parte conhecida/importada por outros módulos
- arquivo `.cpp` -> contém a **implementação** das funções. Ao mudar a implementação, somente esse arquivo é recompilado.

Assim, ao usar bibliotecas, compila um vez e usa várias outras

Ao compilar arquivos `.cpp`, serão gerados arquivos `.o`, os quais serão linkados (pelo linker durante a compilação) ao arquivo principal. Essas especificações são:

Compilar e ligar:
```
g++ -o Executavel aquivo1.cpp arquivo2.cpp 
```

Compilar apenas (gera o `.o`):
```
g++ -c aquivo.cpp
```

Ligar apenas:
```
g++ -o Executavel aquivo1.o arquivo2.o 
```

### Arquivos Makefile
Arquivos **makefiles** funcionam como um roteiro para compilação
- arquivos de texto especialmente formatado (tabs)
- entrada para um utilitário Unix chamado "make"

Ele contém uma lista de requisitos para que um programa seja considerado "up to date" (versão mais recente).  
O programa make examina esses requisitos, verifica os *timespamps* em todos os arquivos listados no makefile e recompila apenas os arquivos com regitro desatualizado

Ele possuí variáveis, comentários e regras 
- targets -> nome do arquivo resultante que desejamos obter. Para cada um deles, falar as dependências (quais arquivos serão necessários para gerar ele), além dos comandos necessários
- informa dependências entre os arquivos
- indica os comandos necessários para compilação

Modelo:
```makefile
target 1 target 2... : dependecia 1 dependencia 2...
<TAB> comando1
<TAB> comando2
...
```

EX:
```makefile
hellworld: helloworld.cpp
    g++ -o helloworld helloworld.cpp
```

EX MAIS COMPLEXO:  
(note que comentários são feitos com #)
```makefile
# variáveis auxiliares:
CC=g++
CFLAGS=-std=c++11 -Wall # definindo a versão (usa - para comando e -Wall para imprimir warnings)

all: main # faz pular para a regra de main. Precisa ser o primeiro! regra do resto não importa tanto

Ponto.o: Ponto.hpp Ponto.cpp
    ${CC} ${CFLAGS} -c Ponto.cpp

main.o: Ponto.hpp main.cpp
    ${CC} ${CFLAGS} -c main.cpp

main: main.o Ponto.o
    ${CC} ${CFLAGS} -o main main.o Ponto.o

# Regra para limpar arquivos gerados durante a compilação
# Chame 'make clean' para usar
clean:
  rm -r main *.o
```

### Organização 
separação em diferentes diretórios:
- agrupar arquivos compilados
- agrupar arquivos de especificação
- agrupar arquivos de implementação

Representar isso por meio de uma árvore de estruturas:

```text
.
├── Makefile
├── build/
│   └── [objects]
├── include/
│   └── modulo1/
│       ├── mod1c1.hpp
│       └── mod1c2.hpp
├── src/
│   ├── main.cpp
│   └── modulo1/
│       ├── mod1c1.cpp
│       └── mod1c2.cpp
└── test/
```

Essa árvore pode ser gerada no linux/mac/git do windows com o comando `tree`, executado na pasta principal do projeto

Para ignorar pastas, usar a lag -I:
```tree -I 'build|node_modules'```