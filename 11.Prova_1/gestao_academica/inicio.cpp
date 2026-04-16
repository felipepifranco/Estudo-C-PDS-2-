#include <iostream>

class Pessoa{
  protected:
  std::string name;
  int cpf;

  public:
  int codificarcpf(int str){
    return str;
    Curso::
  }

  Pessoa(std::string name, int cpf) : name(name), cpf(codificarcpf(cpf)){}

  void imprime(){
    std::cout << "nome: " << this->name << std::endl << "cpf: " << this->cpf << std::endl;
  }
};

//perguntar pra ele sobre ordem
// perguntar para ele sobre questão do curso (e se eu não quiser passar o curso como parâmetro?) (posso passar como parâmetro o resultado de uma função?)
class Estudante;

class Curso {
  protected:
  std::string nome;
  Estudante** lista_std;
  int num_std;

  void AddEstudante(Estudante* estudante){

  }

};

class Estudante : public Pessoa{
  protected:
  int matricula;
  Curso* curso; // precisa botar a lista disso em algum lugar?


};

class Professor : public Pessoa{

};


class Departamento {

};