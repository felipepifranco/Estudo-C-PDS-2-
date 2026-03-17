# Tipos Abstratos de Dados
**Algoritmos:**
- sequências de ações executáveis
- transformam uma entrada em uma saída 
- trabalham sobre estruturas de dados
**Estruturas de dados** 
- informações que representam uma situação real
- abstraem da realidade 
- suportam as operações dos algoritmos

> **ALgoritmo != Programa**
> um programa é uma realização concreta de um algoritmo abstrato, baseado em representações de dados específico.  
> Programas precisam ser implementados numa linguagem que pode ser entendida e seguida pelo computados (C, C++, Java, Python)

### Liguagens e tipos
> Nem todas as linguagens precisam de tipo ao declarar (python)  
Os tipos definem as operações e os tamanhos que as variáveis vão utilizar. Os sistemas já vem com os tipos primitivos (int, double, char, ...).  
Bons programas utilizam da **abstração** (simplificação, tornar algo real em ideia):
- conceito (ideia) -> implementação (concreto)
- identificação e definição dos tipos específicos

Os tipos abstratos de dados auxiliam o entendimento, que facilitam o funcionamento.

## TADs
- Generalização de tipos primitivos
- Encapsula diferentes elementos (membros)
    - conjunto de **valores** (atributos)
    - conjunto de **operações** (métodos)
- Código com perspectivas diferentes
    - visão de quem quer construir x quem quer usar o tipo

Desvincular a especificação da sua implementação:
- Especificação (interface, contrato)
    - o que isso representa/
    - quais operações podem ser feitas
- Implementação (código)
    - como essa "coisa" deve ser implementada?
    - como as operações funcionam internamente?

> Importante planejar, modelar o tipo. Só depois é executar.  
>"O que o TAD representa e faz é mais importante do que como ele faz."

O uso de TADS permitem mudar o código sem que a especificação seja mudada.

Isso garante integridade, facilidade de manutenção, reutilização.

O TAD só deve incluir aquilo que é útil para ele -> se é inútil, delete

## Implementação
Em linguagens estruturadas, a implementação é feita com definição de tipos e implementação de função (structs / typedef).  
Já em linguagens orientadas a objetos a implementação é feita através das **classes** (C++, Java, C#)

Em C++, struct é similar a uma classe (diferença só no nível de proteção). Vamos ver, inicialmente, structs.

## Structs
- conjuntos de variáveis e métodos juntos/acessíveis em um único nome 

```c++
#include <iostream>
#include <cmath>
using namespace std;

struct Ponto3D{
  // dados/atributos:
  double x;
  double y;
  double z;

  // operações/métodos
  double calcularDistancia(Ponto3D* p2){
    double dx = p2->x - this->x; //ponteiro para a prórpia estrutura
    double dy = p2->y - this->y;
    double dz = p2->z - this->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
  }
};
```

```c++
int main() {
  Ponto3D* p1 = new Ponto3D();
  p1->x = 0.0;
  p1->y = 0.0;
  p1->z = 0.0;
  
  Ponto3D* p2 = new Ponto3D();
  p2->x = 5.0;
  p2->y = 5.0;
  p2->z = 5.0;
  
  cout << p1->calcularDistancia(p2) << endl;
  
  delete p1;
  delete p2;

  return 0;
}
```

O `this` é o ponteiro para a própria estrutura. Não é obrigarório, mas facilita o entendimento. Refere-se ao proprio elemento que faz a chamada.

### Construtores
Os construtores são membros especiais do TAD. Podem ser explícitos ou implícitos. Eles têm como função inicializar um TAD e são chamados ao declarar/alocar.


```c++
// Declaração de um contrutor:
struct Ponto3D {
  double x;
  double y;
  double z;

  Ponto3D() { // CONSTRUTOR
    this->x = -1.0;
    this->y = -1.0;
    this->z = -1.0;
  }
};

// Chamando um construtor
int main() {
  Ponto3D* p = new Ponto3D(); // n precisa dos parênteses
  // os valores já são atribuidos
  return 0;
  }
```
Assim que a variável é criada, ele já executa a função.

### Sobrecarga
utilizar diversos métodos com o mesmo nome. Isso facilita e deixa o código mais limpo (será visto depois)
```c++
struct Ponto3D {
  double x;
  double y;
  double z;

  Ponto3D() {
    this->x = -1.0;
    this->y = -1.0;
    this->z = -1.0;
  }

  Ponto3D(double v) {
    this->x = v;
    this->y = v;
    this->z = v;
  }
  
  Ponto3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
};
```