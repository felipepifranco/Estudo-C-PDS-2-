#pragma once // semelhante a um include guard, ele impede de incluir mais de uma vez o arquivo
#include <string>

struct Item {
    std::string nome;
    int quantidade;
    Item(const std::string& nome, int quantidade) : nome(nome), quantidade(quantidade){}
};