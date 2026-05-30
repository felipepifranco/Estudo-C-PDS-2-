#ifndef R2D2_HPP
#define R2D2_HPP
#include "energia.hpp"

class R2D2 {
private:
    Energia bateria_;
    int posicao_;
    int limite_corredor_;
    int obstaculo_;
    bool tocou_terminal_;

public:
    R2D2(int energia_inicial, int limite_corredor, int obstaculo = -1); // se o ultimo valor for omitido, use -1 como padrão

    int getPosicao() const;

    int getEnergiaRestante() const;
    
    bool mover(int distancia);
};

#endif