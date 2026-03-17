# Hierarquia de Memória
A memória é a estrutura interna que armazena informções. Existem 2 tipos:
- **Memória Principal:** DRAM (Dynamic Random-Acces Memory). Memória de armazenamento temporário , durante a execução do sistema (volátil). Mais rápida
- **Memória Secundária:** tecnologias magnéticas e ópticas. Armazenamento não volátil

Esses tipos são usados para definir a hierarquia de memória. Ela tem relação com o tempo de gasto para acessar uma informação e com a quantidade de informação possível gastar.  
É importante pois memória mais rápida tem alto custo, então guarda pouca informação. Mais rápida, mais perto da **CPU**

HIERARQUIA:
1. Registradores e cache
2. Memória RAM
3. Memória secundária

Ao acessar uma informação, o processador segue a hierarquia. Se não achar em uma camada, vai para a próxima camada até chegar na secundária.

## Princício da localidade
- temporal e espacial
sempre que o processador precisa de uma inforamação, ela será transferida entre os níveis, agilisando o processo

### TEMPORAL
- um dado acessado recentemente tem mais chance de ser usado novamente do que dados usados a mais tempo.
- ex: comandos de repetição e funções
- mantem os dados e instruções usados recentementes no topo da HIerarquia

### ESPACIAL
- Probabilidade de acesso maior para dados e instruções em endereços próximos àqueles acessados recentemente
- ex: posições de um vetor
- variáveis são armazenadas próximas e vetores/matrizes são armazenadas em sequencia
- mantem dados e instruções próximos aos que estão sendo executados no topo da Hierarquia

## Memória virtual
Há uma maior demanda da memória principal (programas cada vez maiores)
A memória virtual é a técnica de utilizar a memória secundária como uma extensão da memória virtual
- Ram -> HD
- Segue a hierarquia, enviando dados não utilizados para a memória virtual e dados demandados pelo CPU para a principal
- Gera Custo

### Ciclo de Fetch-Decode-Execute
O armazenamento e manipulação de dados é feito pelo ciclo
- Fetch -> recupera as informações necessárias e salva nos registradores
- Decode -> determina os componentes necessários para a correta execução
- Execute -> atribui as ações necessárias a cada um desses componentes.

> Isso é mais aprofundado em outras diciplinas

# Alocação de Memória
Quando o programa é carregado, ele é armazenado em segmentos da memória:
- Código/globais -> guarda o código compilado do programa e outras variáveis
- Stack -> espaço que variáveis dentro de funções são alocados
- Heap -> espaço mais estável de armazenamento, mais geral
  
> O ponteiro é uma variável que guarda um endereço de memória. A variável fica armazenada no stack, mas o endereço apontado fica no heap.


| Stack | Heap |
|-------|------|
| alocação **estática** (automática) | alocação **dinâmica**| 
|tamanho limitado (stack overflow) | tamanho muito grande (limitada pela RAM) |
|rápida | lenta|
|porção **sequencial** de memória, mais organizado| sem padrão de alocação (**fragmentação**), menos organizado
| escopo da variável só dura a iteração, quando acaba função, é liberada| variável dura até ter memória liberada manualmente 
|LIFO (last-in-firt-out) | sem ordem de alocação/desalocação
| compilador/SO cuida da alocação e liberamento | programador responsável pela alocação e liberamento

## Alocação estática
- acesso/manipulação sem alterar o endereço
- sabe o espaço de memória durante o desenvolvimento (compile time) e persiste até o fim

EX:
```c++
#include <iostream>
#include <iomanip>

int valor_global = 100; // variável global -> code/data

double dobrar_valor(double input) {
  double dobro = input * 2.0; // variável local -> stack
  return dobro;
}

int main() {
  int idade = 30; // var local -> stack
  double salario = 12345.67; // var local -> stack
  double lista[3] = {1.2, 2.3, 3.4}; // var local -> stack
  
  std::cout << std::fixed << std::setprecision(2) << dobrar_valor(salario);
  return 0;
}
```
> 
> Site python tutor para acompanhas a memória
> 
## Alocação dinâmica
- maior controle na manipulação (mais responsabilidade)
- armazenamento de grandes quantidades de dados com tamanho máximo é desconhecido (não fixo) na implementação (execução)
- tamanho pode variar após início da execução
- sem escopo específico
Em C++:
- uso de ponteiros
- manuseio da memória de maneira explícita

# Ponteiros
Armazenam um endereço de memória
declarar com um asterisco após o tipo: `int* var`
| Operador de Referência | Operador de Deferência|
|------------------------|-----------------------|
| &var | *var |
| **endereço** de memória da variável var | **conteúdo** do endereço apontado por var |

- É possível fazer um ponteiro de ponteiro

## Alocação
- Alocação: `new`
- Liberação: `delete`

EX:
```c++
int *a, b; //a é ponteiro, b é int

b =10;
a = new int;

*a =20; //o conteúdo do endereço de a passa a ser 20
a = &b; // a começa a apontar para b
*a =30; // o valor de b passa a ser 30
```
*note que, nesse código, o endereço antigo de a (que contem 20) não pode mais ser referenciado! Assim, não pode ser desalocado até o fim do programa. Isso pode encher a memória!*

CODIGO MELHORADO:
> BOAS PRÁTICAS:
> - informe apenas uma variável por declaração
> - dê um valor inicial para as variáveis
> - libere a memória alocada dinamicamente
```c++
int*a = nullptr; // flag para ponteiro vazio
int b = 10;

a = new int;
*a = 20;
delete a;
a = &b;
*a = 30;
```

### Vetores
- criar vetores em tempo de execução (só ocupar memória quando necessário)
- ponteiro guarda o endereço da **primeira posição** do vetor
- usar **colchetes** na desalocação

EX:
```C++
int main(){
  int *p = new int[10];

  p[0] = 99;

  delete[] p;

  return 0;
}
```
### Ponteiros nulos
Ponteiros nulos: `nullptr`.  
Constante símbolida (NULL = 0),semanticamente igual, mas nullptr é mais seguro.  
Nenhum ponteiro válido possui esse valor, e esse valor não pode ser acessado (falha de segmentação)

EX:
```C++
#include <iostream>
using namespace std;

int main() {
  int *ptr_a = nullptr;
  // ptr_a = new int;
  if (ptr_a == nullptr) {
    cout << "Memoria nao alocada!" << endl;
    exit(1);
  }
  cout << "Endereco de ptr_a: " << &ptr_a << endl;
  *ptr_a = 90;
  cout << "Conteudo de ptr_a: " << *ptr_a << endl;
  delete ptr_a;
  return 0;
}
``` 

### Ponteiro void
Valor coringa (pode apontar para qualquer coisa), mas não é boa prática (perda de precisão)

EX:
```C++
int i=10;
int *intptr;
void *void_ptr;
double *doubleptr;

int_ptr = &i;
void_ptr = int_ptr; // OK
double_ptr = int_ptr; // !
double_ptr = void_ptr; // OK
```

### Ponteiro structs
> estruturas são semelhantes a vetores, pois a memoria é alocada de maneira conjunta
```c++
struct data {int dia; int mes; int ano;}
struct data d1;
struct data *ptr = *d1;
int i=0;

// ACESSO AOS CAMPOS:
d1.dia = 8;
d1.mes =3;
d1.ano =2012;

ptr->dia =7;
ptr->mes = 11;
ptr->ano = 2020;
```

## Passagem de parâmetros
### Valor
- parâmetro recebido é uma cópia do parâmtro real 
- variáveis **independentes**  

EX:
```C++
#include <iostream>

using namespace std;
void addOneValue(int x) {
  x = x + 1;
}

int main() {
  int a = 0;
  cout << "Antes: " << a << endl;
  
  addOneValue(a);
  cout << "Depois: " << a << endl;
  
  return 0;
}
```
> imprime:  
> 0  
> 0
### Referência (ponteiro)
- parâmetro recebido é uma referência para o real
- variáveis **iguais**

EX:
``` C++
#include <iostream>
using namespace std;

void addOneReference(int &x) { // referência não pode ser null 
// menos usada
  x = x + 1;
}
void addOnePointer(int *x) { // ponteiro pode ser NULL
// mais usada
  *x = (*x) + 1;
}

int main() {
  int a = 0;
  cout << "Antes: " << a << endl;
  //addOneReference(a);
  //addOnePointer(&a);
  cout << "Depois: " << a << endl;
  
  return 0;
}
```
### Boar práticas erros comuns:
- Usar referência sempre que possível, ponteiro só quando necessário
- Usar `const` para aquilo que não pode ser alterado 

- Não acessar o conteúdo de uma posição não alocada/já desalocada
- Copiar o valor do ponteiro e não o valor da variável apontada
- Desalocar a memória (cuidado com loops!)