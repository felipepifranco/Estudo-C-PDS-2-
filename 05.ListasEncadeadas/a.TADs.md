Exemplo de um TAD.

### Introdução
*Como guardar uma coleção de elementos?*
Pode-se imaginar utilizar vetores (arrays)
- tamanho fixo
- acesso direto (índice)

```c++
#include <iostream>
using namespace std;

int main() {
  int vetorA[5]; // posições não inicializadas
  vetorA[3] = 99;
  for(int i=0; i<5; i++)
    cout << vetorA[i] << "\t";
  cout << endl;
  
  int vetorB[5] = {}; // posições inicializadas com 0
  for(int i=0; i<5; i++)
    cout << vetorB[i] << "\t"; 
  cout << endl;
  
  double vetorC[] = {1.1, 2.2, 3.3}; // posições alocadas e inicializadas
  cout << vetorC[1] << endl;
  
  return 0;
}
```
# Listas encadeadas
Forma alternativa de guardar coleções. Cada célula/nó possui duas informações:
- Conteúdo (valor) que se deseja armazenar
- Referência para o elemento seguinte na cadeia
| Arrays | Listas encadeadas |
| ------ | ----------------- |
| Acesso direto (índice) | Acesso sequencial |
| Tamanho fixo e conhecido | Tamanho variável (um elemento por vez) |
| T = 𝑛 x sizeof(elemento) | T = 𝑛 x sizeof(elemento) + 𝑛 x sizeof(referência) |

```c++
struct Node {
  int data;
  Node* next;
};
```

```c++
#include <iostream>
using namespace std;

int main() {
  Node a;
  Node b;
  
  a.data = 99;
  a.next = &b;
  
  b.data = 123;
  
  cout << a.data << endl;
  cout << a.next->data << endl;
  return 0;
}
```

## Operações
Operações
- Criar uma nova lista (inicialização)
- Inserir elementos
- Retirar elementos
- Localizar um elemento
- Recuperar o valor de um elemento
- Recuperar o elemento seguinte à um elemento
- ...

*Como acessar o último elemento? Preciso acessar todos os outros primeiros?*

Criar um outro tipo que gerencie as operações do nó! -> **Lista**  
Dados que ele contém:
- Referência para o primeiro Node (Head, Cabeça)
    - dsdas
- Referência para o último Node (Tail, Cauda)

Lista.hpp
```c++
#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

struct List {
  Node* head = nullptr;
  Node* tail = nullptr;
  void insertNode(int data);
  void removeNode(int data);
  void display();
};
#endif
```
### Inserção
Como inserir um novo valor na lista (final)?
1. Criar um Node
2. Se a Lista estiver vazia
    - Novo Node será Cabeça e Cauda
- Caso contrário
    - Novo Node será inserido após Cauda  
    - Esse Node agora é a Cauda

List.cpp
```c++
#include "List.hpp"
void List::insertNode(int data) {
  Node* aux = new Node;
  aux->data = data;
  aux->next = nullptr;
  
  if (head == nullptr) {
    head = aux;
    tail = aux;
  } else {
    tail->next = aux;
    tail = aux;
  }
}
```

main.cpp
```cpp
#include "List.hpp"

int main() {
  List lista;
  
  lista.insertNode(111);
  lista.insertNode(222);
  return 0;
}
```
### Remoção
*Como remover um determinado node?*  
Quantos casos?
1. Cabeça
   - Cabeça aponta para o próximo do Node removido
2. Cauda
    - Node anterior não aponta mais para ninguém
    - Node anterior vida Cauda
3. Outros
    - Node anterior aponta para o próximo do removido

Lista.cpp
```cpp
void List::removeNode(int data) {
  Node *current = head;
  Node *previous = nullptr;
  
  while (current != nullptr) {
    if (current->data == data) {
      if (previous == nullptr) { // HEAD
        head = current->next;
        if (current == tail) tail = nullptr;
      } else if (current->next == nullptr) { //TAIL
        previous->next = nullptr;
        tail = previous;
      } else {
        previous->next = current->next;
      }
      delete current;
      return;
    }
    previous = current;
    current = current->next;
  }
}
```
main.cpp
```cpp
#include "List.hpp"
int main() {
  List lista;

  lista.insertNode(111);
  lista.insertNode(222);
  lista.removeNode(222);
  return 0;
}
```
### Enumeração
*Como exibir o estado atual da Lista?*
Percorrer a lista até chegar ao último elemento
- Comparar com a Cauda

Lista.cpp
```cpp
void List::display() {
  Node *aux = head;
  while (aux != nullptr) {
    cout << aux->data << "\t";
    aux = aux->next;
  }
  cout << endl;
}
```

```cpp
#include "List.hpp"
int main() {
  List lista;
  
  lista.insertNode(111);
  lista.insertNode(222);
  lista.display();
  
  return 0;
}
```