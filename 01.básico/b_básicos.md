A linguagem C++ é uma continuação de C. Permite ter acesso a recursos de baixo nível, como manipular memória, e de alto nível, como programação oritentada em objeto.

Não é possível fazer em C++ tudo que se faz em C.

C++ é uma linguagem multiparadigma

## Passos básicos
1. usar um editor qualquer para criar codigos fonte e os de cabeçalho
2. passar para o compilador, responsável por traduzir o código. Se tudo estiver ok, é criado um arquivo em linguagem de máquina
3. um ligador é usado para combinar arquivos gerados com outros módulos e bibliotecas.
4. um arquivo executável é criado

EXEMPLO DE CÓDIGO (diferença de C para C ++):
``` c
// em c:
#include <stdio.h>
int main(){
  print("Hello WOrld\n");
  return 0;
}
```
compilar com `gcc hello.c -o hello`  
```c++
// em c++:
#include <iostream> // sem necessidade de extensão para bibliotecas externa

using namespace std; // escopo (namespace) específico

int main(){
  cout << "Hello world!" << endl;
  // cout é stream da saída padrão
  // endl é a quebra de linha
  return 0;
}
```
compilar com `g++ gello.cpp -o hello`


> note que ambos são parecidos, mas há diferenças, como podem ser vistas no comentário do código de c++

> O usernamespace serve para que não seja necessário especificar a qual escopo aquele tipo ou operador deve pertencer

### Versão
Para utilizar diferentes versões do c++ ao compilar, só fazer
```$ g++ -std=c++11 -Wall hello.cpp -o hello```

nesse caso, a versão é a C++11.
Note também a flag `-Wall`, que serve para relatar warnings que ocorram em códigos

## Tipos de Dados
C++ apresenta tipos de dados similares a outras linguagens de programação:
- Primitivos: int, float, double, char, **bool**, void, Wide CHaracter
- Derivados: array, função, ponteiro
- Definidos pelo usuário: Structure, Union, Enum, **Class**

Temos com destaque os em negritos, que não estão presentes em C:
- bool: valor booleano, que serve para guardar os valores lógicos verdadeiro ou falso (`True`ou `False`)
- Class: cria os próprios tipos de dados a partir da definição de classe.

### cadeia de caracteres
Em C++, há um tipo específico para armazenar e manipular cadeias de caracteres - o string. Para utilizar, basta incluir a biblioteca `string`, padrão do C++.

Ex:
```c++
#include <iostream>
#include <string>

int main() {
  std::string curto = "Hello World!";
  std::string longo = "Essa é uma string grande para o exemplo!";

  std::cout
}
```

```c++
#include <iostream>
#include <string>

using namespace std; //fazendo isso, não precisa informar o escopo antes das variáveis (usar com cuidado!)

int main() {
  string a;
  a = "123456";
  
  string b;
  b = "123456";

  bool igual = (a == b); // é possível comparar e salvar o retrorno em uma variável Booleana, retorna 1 se true
  cout << igual << endl;
  
  cout << a[0] << endl; // manipulação de cada caractere similar a array
  cout << b[5] << endl;

  a[0] = '0';
  cout << a << endl;

  string c = a + b; //concatenação
  cout << c << endl;
  
  return 0;
}
```

### Entrada e Saída
Streams (fluxos) são uilizados para comunicação. O stream é uma abstração utilizada para fazer a comunicação entre o programa e um dispositivo de entrada ou um de saída (input stream / output strem).

Essa função está incluída na biblioteca principal `<iostream>`. Além disso, a biblioteca principal possui outros módulos mais específicos, como o `<fstream>`, para manipular arquivos (files), e o `<sstream>`, para strings.

O stream é uma sequência de bytes que representa uma cadeia de caracteres de tamanho indefinido que fluem para dentro ou para fora.
- Stream de entrada pode receber informação do teclado, de arquivos, da rede, de programas,...
- Stream de saída pode enviar informações para o console, para arquivos, para a rede, para programas...
É possível usar printf também (mas melhor evitar)

Os disposivos de entrada são o **cin** (entrada) ou o **cout** (saída).  
Para manipular entrada e saída, usa-se os **operadores de inserção** `<<`, ou o de **extração** `>>`, que inserem ou extraem streams.
- O `cout <<` é simples, basicamente faz uma impressão no terminal daquilo que é passado para ele.
- O `cin >>` é mais complexo: para fazer a manipulação da stream, é preciso informar o nome de uma variável que irá receber. Porém, o operador faz uma extração de acordo com tipo - aguardando a entrada do tipo da variável -, pega informação ate espaço em branco, tab ou quebra de linha

Note que é possível fazer uma saída encadeada

**conversão de tipo**

EXEMPLO:
```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
  string nome;
  int idade;
  
  cout << "Digite o seu nome: ";
  cin >> nome; // aguarda uma string
  
  cout << "Digite sua idade: ";
  cin >> idade; // aguarda um inteiro, similar a scanf("%d", &idade);
  
  cout << endl;
  cout << "Ola " << nome << " voce tem " << idade << " anos." << endl; // saída encadeada

  return 0;
}
```

EX 2:
```C++
#include <iostream>
using namespace std;
int main() {
  int x;
  while(cin >> x) { //enquanto ainda recebe conteudo, o loop continua
    cout << "[" << x << "]" << endl;
  }
  return 0;
}
```

>É possível passar arquivos na hora de executar um programa:
>`[nome do .exe] < [nome do arquivo passado]`

Para pegar uma linha inteira de uma string, usar a função `getline()`. Porém, tome cuidado ao utilizar o getline, pois, dependendo da entrada, pode haver um comportamento indesejado.  
O getline() retorna False se chega no fim do arquivo. 
É comum utilizar o getline junto da biblioteca `<sstream>`, usada para manipular strings como se fossem streams

EX 3:
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
  string nome_completo;
  cout <<"Digite o seu nome completo: ";
  getline (cin, nome_completo);
  cout << "Ola " << nome_completo << endl;
  return 0;
}
```

EX 4:
```c++
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {

    stringstream info(line); //criando um stream de entrada/saida local a partir da linha lida

    string aux;
    while (getline(info, aux, ';')) { // lendo o stream considerando um delimitador
      cout << aux << endl;
    }
  }
  return 0;
}
```

```c++
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  string frase = "Lorem ipsum dolor sit amet";
  string palavra;
  
  stringstream s(frase);
  
  while (s >> palavra) // utilizando o operador de extração como se fosse o cin
    cout << palavra << endl;
  
  return 0;
}
```

### Entrada e Saídas de Arquivos
Utilizar a biblioteca `<fstream>` para entrada e saída em arquivos. Para receber um arquivo:
- O tipo deve ser `ifstream`(input file stream, para entrada) ou `ofstream`(output file stream, para saída)
- Colocar o nome deste arquivo
- Passar, em um parênteses após o nome, o nome do arquivo e a flag. Esses dois são parâmetros do construtor, um método da classe que os tipos são. Serve para criar uma entidade
    - nome do arquivo em aspas e, se não estiver na mesma pasta, passar o caminho completo
    - flag indicando como o arquivo será aberto. As principais são: `::in` (leitura), `::out` (escrita), `::app` (append), `::ate` (abre e vai para o final), `::trunc` (trunca o arquivo), `::binary` (abre em binário). Note que não é necessário utilizar in e out quando se especifica o tipo.

EX:
```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream in("entrada.txt", fstream::in); 
  ofstream out("saida.txt", fstream::out);
  string line;

  while (getline(in, line)) {
    cout << "*" << line << "*" << endl;
    out << "[" << line << "]" << endl;
  }

  return 0;
}
```

> **Boas práticas:**
> Para evitar os erros de abertura de arquivo (como arquivo não existir ou o espaço da memória for insuficiente para criar outro), utiliza-se um confirmação de abertura,.
> Outra boa práticas é fechar os streams, mas isso não é necessário, pois o próprio objeto vai cuidar disso quando o escopo for encerrado

``` c++
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ifstream in("entrada.txt", fstream::in);
  if (!in.is_open()) { // conferindo se abriu
    return 1;
  }
  
  ofstream out("saida.txt", fstream::out); 
  if (!out.is_open()) { // conferindo se criou
    return 1;
  }
  
  string line;
  while (getline(in, line)) {
    cout << "*" << line << "*" << endl;
    out << "[" << line << "]" << endl;
  }
  in.close();
  out.close();
  return 0;
}
```

