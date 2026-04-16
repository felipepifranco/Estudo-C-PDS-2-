#ifndef BASEMILITAR_HPP
#define BASEMILITAR_HPP
#include "Defesa.hpp"

class BaseMilitar{
  private:
    Defesa* _defesas[100];
    int _qtdAtual;

  public:
    BaseMilitar();

    void adicionarDefesa(Defesa*d); // adiciona o ponteirno ao array

    void defender(double &saudeInimigo); //percorre as defesas, cada uma ataca. O dano total é subtraido.
    // imprimeSaude Inimigo: X.XX (com duas casas decimais).

    ~BaseMilitar();// libera tudo do array

};

#endif