#ifndef ENERGIA_HPP
#define ENERGIA_HPP
 
class Energia {  
private: 
    int carga_;
public:
    Energia(int carga_inicial); //Construtor: Inicia a bateria com a carga fornecida.
    int getCarga() const; // Acesso: Retorna a quantidade de energia atual.
    void consumir(int quantidade); // Controle: Reduz a carga da bateria. (Atenção: A bateria nunca deve possuir carga negativa, o seu valor mínimo é 0
};

#endif