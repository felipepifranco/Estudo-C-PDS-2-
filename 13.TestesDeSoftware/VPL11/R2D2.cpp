#include "R2D2.hpp"
#include <cmath>

R2D2::R2D2(int energia_inicial, int limite_corredor, int obstaculo) 
    : bateria_(energia_inicial), posicao_(0), limite_corredor_(limite_corredor), 
      obstaculo_(obstaculo), tocou_terminal_(false) {}

int R2D2::getPosicao() const {
    return posicao_;
}

int R2D2::getEnergiaRestante() const {
    return bateria_.getCarga();
}

bool R2D2::mover(int distancia) {
    if (bateria_.getCarga() <= 0 || distancia == 0){
        return false;
    }
    
    int nova_posicao = posicao_ + distancia;

    if (nova_posicao < 0){ // tratamente limite
        nova_posicao = 0;
    }
    if (nova_posicao > limite_corredor_){
        nova_posicao = limite_corredor_;
    }

    // Responsavel pela movimentacao do R2-D2
    if (obstaculo_ != -1) { // com obstaculo
        if ((posicao_ <= obstaculo_ && nova_posicao >= obstaculo_) || 
            (posicao_ >= obstaculo_ && nova_posicao <= obstaculo_)) { // passou pelo obstaculo

            if (posicao_ < obstaculo_) {
                nova_posicao = obstaculo_ - 1;
            } 
            else {
                nova_posicao = obstaculo_ + 1;
            }
        }
    }
    
    int distancia_real = std::abs(nova_posicao - posicao_);

    if (distancia_real > bateria_.getCarga()) {
        distancia_real = bateria_.getCarga();

        if (distancia > 0) {
            nova_posicao = posicao_ + distancia_real;
        } else {
            nova_posicao = posicao_ - distancia_real;
            }
    }

    if (nova_posicao == limite_corredor_) {
        tocou_terminal_ = true;
    }


    
    bateria_.consumir(distancia_real); 
    posicao_ = nova_posicao;

    if (tocou_terminal_ == true && posicao_ == 0) {
        return true;
    }
    return false;
}