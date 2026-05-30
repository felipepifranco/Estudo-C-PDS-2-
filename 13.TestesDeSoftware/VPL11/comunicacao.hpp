#ifndef COMUNICACAO_HPP
#define COMUNICACAO_HPP
#include <string>

class Comunicacao {
public:
    Comunicacao();

    std::string gerarRelatorio(int posicao, int bateria, bool completou_missao);
    
    bool enviarSinal(std::string mensagem, int bateria, bool completou_missao);
};

#endif