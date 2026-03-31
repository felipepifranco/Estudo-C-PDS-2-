## Paradigmas
Paradigma de programação: visão que o programador possui sobre a estruturação (organização do código) e execução do programa. Está associado às técnicas de programação que permitem/proíbem

Tipos:
- Estruturado (Procedural)
- Funcional -> o mais usado até agora, é o uso de funções
- Lógico -> estrutura lógica, com fatos e regras e que, a partir de perguntas, é possível inferir resultados
- Orientado a objetos

Divisões:
Imperativos:
- Procedural (Fortran, C)
- Imperativo (C++, Java)

Declarativo:
- Lógico (Prolog)
- Funcional (Haskell, ML)

# Programação Orientada a Objetos
Nova forma de pensamento que buscava:
- aumentar a produtividade no desenvolvimento
- diminuir a chance de problemas na entrega
- facilitar a manutenção/extensão no futuro

Programação Estruturada
- Procedimentos implementados em blocos
- Comunicação pela passagem de dados
- Execução → Acionamento de procedimentos
Programação Orientada a Objetos
- Dados e procedimentos encapsulados (TADs)
- Execução → Comunicação entre objetos
- Não é preciso saber como funcionam (Especificação/Implementação)

Em POO, os dados/tipos têm “características humanas”, possuem conhecimento/ação sobre si próprios!

## CLasses
- Estruturada em uma unidade de compilação
- Define uma lógica estática (trecho de código)
- Representação → Conceito, ideia, abstração
- Formaliza como compreendemos algo no domínio do problema
- Conjunto de elementos com propriedades/operações semelhantes

### Objeto
Objeto é uma instância de uma Classe
- Representa um elemento específico do conjunto
- Existe em tempo de execução (está na memória)
- TAD é implementado por uma Classe que gera Objeto

Possuem alocação própria na memória
- Devem ser criados (instanciados) explicitamente
- Em algum momento serão destruídos (Explícito x Implícito)


**Propriedades:**
- Estado:
    - Valores que os atributos possuem em um certo momento
- Comportamento
    - Responsável pelas mudanças de estado
    - Relacionamento com os demais objetos
- Identidade (referência única)
    - Propriedade que o difere dos demais objetos na memória
    - Definidos a partir do endereço, não dos atributos (Estado x Identidade)

Eles são dados ocultos do “mundo externo” (Distribuídos ≠ Espalhados). Devem ser acessíveis somente via métodos internos

| Classe | Objeto |
| ------ | ------- |
| Descrição de propriedades em comum de um grupo de objetos (conjunto) | Representação das propriedades de uma única instância (elemento) |
| Um conceito | Um fenômeno (ocorrência) |
| Faz parte de um programa | Faz parte de uma execução |
| Exemplo: Pessoa, Carro | Exemplo: João, Maria /Ferrari, Fusca |


EXEMPLO:  
Esfera.hpp
```c++
#ifndef ESFERA_H
#define ESFERA_H

#include <cmath>
#include <string>

class Esfera {
  public: // MODIFICADOR DE ACESSO! (será mais detalhado no futuro)
    float massa;
    float raio;
    std::string cor;
    
    float calcular_volume();
    float calcular_densidade();
};
#endif
```

Esfera.cpp
```c++
#include "Esfera.hpp"

float Esfera::calcular_volume() {
  return (4/3)*M_PI*pow(this->raio, 3);
}

float Esfera::calcular_densidade() {
  return this->massa/this->calcular_volume();
}
```

main.cpp
```cpp
#include <iostream>
#include "Esfera.hpp"

using namespace std;

int main() {
  Esfera esf1;
  esf1.massa = 100;
  esf1.raio = 25;
  esf1.cor = "vermelho";
  
  cout << "Densidade Esf1: " << esf1.calcular_densidade() << endl;
  
  Esfera *esf2 = new Esfera();
  esf2->massa = 100;
  esf2->raio = 25;
  esf2->cor = "vermelho";
  
  cout << "Densidade Esf2: " << esf2->calcular_densidade() << endl;
  
  delete esf2;
  
  return 0;
}
```

### Herança

### Polimorfismo