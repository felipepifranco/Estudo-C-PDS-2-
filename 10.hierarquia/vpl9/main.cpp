#include "BaseMilitar.hpp"
#include "CanhaoOrbital.hpp"
#include "LancadorMissil.hpp"

using namespace std;

int main(){
  char comando = ' ';
  bool roda = true;
  BaseMilitar tropinha;

  int id =0;
  double energia =0.0;
  double intensidade =0.0;
  double vidaInim = 0.0;
  double gravidade = 0.0;
  int qtdM = 0;

  while(roda){
    cin >> comando;

    switch(comando){
      case 'c': // c ID ENERGIA INTENSIDADE: Cria um Canhao e adiciona como defesa da Base.
        cin >> id >> energia >> intensidade ;
        tropinha.adicionarDefesa(new Canhao(id, energia, intensidade));
        break;
      case 'o':
        cin >> id >> energia >> intensidade >> gravidade;
        tropinha.adicionarDefesa(new CanhaoOrbital(id, energia, intensidade, gravidade));
        break;
      case 'm':
        cin >> id >> energia >> qtdM;
        tropinha.adicionarDefesa(new LancadorMissil(id, energia, qtdM));
        break;
      case 'd':
        cin >> vidaInim;
        tropinha.defender(vidaInim);
        break;
      case 's':
        roda = false;
        break;
    }

  }

  return 0;
}
