Como criar uma relação entre classes?
- Herança: há uma classe pai (superclasse) e filhas (subclasse)
- Composição: uma classe tem como atributos outras classes
# Herança
técnica para reutilizar características de uma classe na definição de outras classes
É uma relação hierarquica de níveis entre as classes. A relação de hierarquia deve ter significado (ficar atento ao especializar)

- Classes mais genéricas: superclasses (pai) (base)
	- Devem guardar membros em comum 
- Classes especializadas: subclasses (filha) (derivada)
	- Acrescentam novos membros (método, atributos) (**estendem**)
	- Redefinem comportamentos (sobrescrever métodos do superclasse)(**especializam**)


###### EX:
SUPERCLASSE: 
- pessoa
	- atributo nome
	- método comer
SUBCLASSES: 
- professor
	- atributo nome
	- atributo departamento
	- método comer, com especialização diferente
	- método ensinar
- Estudante
	- nome
	- comer, com especialização diferente
	- 
	- atributo curso
	- método estudar  

### Benefícios
- permite reutilizar o código 
	- compartilha similaridades
	- preserva diferenças
- facilita manutenção/extensão do sistema
	- maior legibilidade
	- menor quantidade de linhas
	- alteração em poucas partes do código

Os membros são herdados pelas classes dos níveis abaixo. Isso considera os **modificadores de acesso**: private são herdados, mas só são acessados pela própria classe

Subclasses podem herdar membros de:
- Herança simples: uma única superclasse (Java)
- Herança múltipla: várias superclasses (C++, Python)
	- Não confundir heraça múltipla (Classe A herda de Classe B e de Classe C), com herança multi-nível (Classe A herda de Classe B que herda de Classe C)


## Herança simples
```cpp
class Pessoa{
	public:
		string nome;
};

// estudante é sublcasse e Pessoa é superclasse
class Estudante : public Pessoa{
	public:
		int matricula;
}:

// só é preciso falar o nível mais baixo
class EstGrad: public Estudante{
	public:
		bool FUMP.
}
```

```cpp

int main(){
	EstGrad* aluno = new EstGrad();
	
	aluno->nome = "Ronaldo"; // atributo do avo
	aluno ->matricula = 321321412421;; // atributo do pai
	aluno->fump = true; // atributo dele mesmo
}
```

### Princípio da Substituição de Liskov (LSP)
> Se S é um subtipo de T, então S deve poder ser usado em qualquer situação em que T seria usado, sem que isso afete a execução correta do programa

Um objeto de uma subclasse pode ser usado quando um objeto da classe pai é esperado
- **mas:** os atributos da classe filha ficam "escondidos"

```cpp
int main(){
	EstGrad* aluno = new EstGrad();
	
	aluno->nome = "Ronaldo";
	aluno ->matricula = 321321412421;
	aluno->fump = true;
	
	Pessoa p* = aluno; // permitido!
	p->nome = "Maria"; // permitido
	p->matricula = 35542234323; // NÃO permitido! Erro de compilação
	p->FUMP = true; // NÃO permitido! Erro de compilação
}
```

### Sobrescrita de métodos
Métodos podem ser **sobrescritos** (override)
- diferente de sobrecarga (overload)
- mesma assinatura da classe base
- substituir o método da base por implementação própria
- tipo de polimorfismo

> Tomar cuidado com modificadores de acesso!
> - Não restringir o acesso (quebraria o LSP)
> - public -> public
> - protected -> protected, public

EX:
```cpp
class Pessoa{
	public:
		virtual void Imprime(){
			cout << "Sou uma PESSOA." << endl;
		}
};

class Estudante: public Pessoa{
	public:
		void Imprime() override{
			cout << "Sou um ESTUDANTE." << endl;
		}
}
```

Atenção ao virtual e ao override

```cpp
int main(){
	Pessoa p;
	p.Imprime(); // imprime sou uma PESSOA
	
	Estudante e;
	e.Imprime(); // imprime sou um ESTUDANTE
	
	Pessoa* p2 = new Estudante();
	p2->Imprime(); // imprime sou um ESTUDANTE
	
	delete p2;
	
	return 0;
}
```

`p2->Imprime()` retorna "sou um ESTUDANTE" por conta do "virtual e por ser um apontador. 
- Se não tivesse o virtual imprimiria "sou uma PESSOA"
- virutal basicamente é uma flag para o compilador de que o método pode ser sobrescrito
- botar override sem o virtual da erro de compilação
- Quando ce faz uma atribuição em vez de ponteiro (ligação **estática**), ou seja, por exemplo, `Pessoa p2 = e`, imprime pessoa! Pois só copia a parte Pessoa

**O que não pode ser sobrescrito:**
- atributos
- métodos private
- membros estáticos

**O que acontece se não redefinir e chamar o método de uma classe pai/avo**
- vai procurar o método na classe mais próxima na hierarquia

usa public/private/protectes na hora de chamar
- reduzir para o mais privativo entre os dois 


