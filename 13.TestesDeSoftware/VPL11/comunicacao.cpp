#include "comunicacao.hpp"

Comunicacao::Comunicacao(){}

std::string Comunicacao::gerarRelatorio(int posicao, int bateria, bool completou_missao){
    std::string resposta = "R2D2 em " +  std::to_string(posicao) + ", Bateria: " + std::to_string(bateria) + "%, Missao: ";

    if(completou_missao == true)
        resposta += "Concluida";
    else
        resposta += "Pendente";

    return resposta;
}

bool Comunicacao::enviarSinal(std::string mensagem, int bateria, bool completou_missao){
    if(bateria < 5)
        return false;
    else if (completou_missao == false)
        return false;
    else 
        return true;

}
