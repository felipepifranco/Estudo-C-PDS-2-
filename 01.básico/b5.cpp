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