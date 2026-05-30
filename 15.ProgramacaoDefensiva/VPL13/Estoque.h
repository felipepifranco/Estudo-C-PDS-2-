#pragma once
#include <vector>
#include <string>
#include "Item.h"

class Estoque {
private:
    std::vector<Item> _itens;

public:
    void adicionar_item(const std::string& nome, int quantidade_inicial);
    void registrar_entrada(int indice, int quantidade);
    void registrar_saida(int indice, int quantidade);
    void consultar(int indice) const;
    void listar() const;
};