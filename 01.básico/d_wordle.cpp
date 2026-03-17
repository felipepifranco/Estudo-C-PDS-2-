/*
Você deverá implementar uma versão do Jogo Wordle.  O objetivo do jogo é adivinhar uma palavra de cinco letras dentro em no máximo cinco tentativas. Você insere uma palavra de cinco letras e o jogo indica se as letras estão corretas e se estão na posição correta, na posição errada ou se não estão na palavra. Com base nessas dicas, você tenta adivinhar a palavra correta antes de acabar suas tentativas. 

Mais especificamente, as instruções são as seguintes: 
    você deverá inicialmente ler um arquivo chamado "palavras.txt" que contém um conjunto de palavras. A primeira linha contém um inteiro n com o número de palavras do arquivo, seguidas pelas n palavras, uma por linha. Cada palavra possui 5 letras (para simplificar, você pode considerar que a palavra é fornecida em letras maiúsculas e não há caracteres repetidos) .
    O próximo passo é ler da entrada padrão um número de 1 a n que vai escolher a palavra a ser adivinhada. Vamos chamar essa palavra de chave.
    A partir daí começa o jogo propriamente dito... Você deverá fornecer como entrada uma palavra de 5 letras. (da mesma forma,  você pode considerar que a palavra é fornecida em letras maiúsculas e não há caracteres repetidos).
    O seu programa deverá analisar a palavra fornecida como entrada em comparação com a chave e, para cada uma das letras, fornecer uma string de saída da seguinte forma (veja um exemplo em seguida):
    - imprimir a letra em maiúscula caso ela esteja presente na chave e esteja na posição correta.
    - imprimir a letra em minúscula caso ela esteja presente na chave mas na posição incorreta.
    - imprimir um * caso a letra não esteja presente. Além disso, as letras que não estão presentes são impressas depois da palavra entre parênteses.
    (devem ser impressas as letras não presentes de todas as tentativas, sem repetição. coloque um espaço depois da palavra).  
    Caso a palavra seja igual a chave, você deve imprimir "GANHOU!" e terminar o programa. Senão, deve ler uma nova entrada.
    Depois de 5 tentativas, caso você não tenha acertado a palavra, você deve imprimir: "PERDEU!", seguido da palavra correta, separada por um espaço.

*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void tentando(string tentativa, string resposta, string* descoberta, string* erros){
  char c;
  size_t pos_r;

  for(int i=0; i<5; i++){
    c = tentativa[i];
    pos_r = resposta.find(c);

    if(pos_r == string::npos){
      if((*erros).find(c) == string::npos)
        *erros += c;
    }
    else if((int)pos_r == i) // CONFERIR se letra ta na mesma posição
      (*descoberta)[i] = c;
    else{ // conferir se ta na palavra, mas posição dierente
      (*descoberta)[i] = tolower(c, locale());}
  }
  
}

int main(){
  // encontrar a palavra no documento
  int num;
  cin >> num;
  int max;
  string palavra;

  ifstream arquivo("palavras.txt", fstream::in);
  if (!arquivo.is_open())  // conferindo se abriu
    return 1;
  
  getline(arquivo, palavra); // pegar e conferir o maximo
  stringstream s(palavra);
  s >> max;
  if( num > max)
    return 1;
  
  for(int i=0; i<num; i++){
    getline(arquivo, palavra);
  }

  // realizar um loop das partidas para conferir a palavra
  int i=0;
  bool ganhou = false;
  string tentativa;
  string descoberta = "*****";
  string erradas = "";
  
  while(i<5){
    cin >> tentativa;
    
    tentando(tentativa, palavra, &descoberta, &erradas);
    
    cout << descoberta;
    cout << " (" << erradas << ")" << endl;
    
    if(tentativa == palavra){
      ganhou = true;
      break;
    }

    descoberta = "*****";
    i++;
  }

  // imprimir resultado
  if(ganhou)
    cout << "GANHOU!";
  else
    cout << "PERDEU! " << palavra << endl;
}