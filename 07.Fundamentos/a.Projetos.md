# Processo de desenvolvimento
## Requisitos
 Histórias de usuário (User Stories)
Objetivos/restrições estabelecidas por clientes e usuários
Definem as propriedades/características desejadas
Tipos
- Funcionais: funcionalidades que o software deve oferecer
- Não-funcionais: qualidades globais de um software 

EX:
> carro (Analogia):
> Funcional (O que ele faz):
> Acelerar
> Frear
> Virar as rodas
> Não-Funcional (Como ele é/qualidades):
> Velocidade máxima de 200km/h (Desempenho)
> Possui 6 airbags (Segurança)
> Faz 15km por litro de gasolina (Eficiência)

Envolve a identificação e “formalização” dos requisitos
- Identificar e formalizar as (reais) necessidades
- Falhas → Alto custo mais tarde para arrumar  
Área muito importante e desafiadora!


### Histórias de Usuários (User stories)
Descrição informal em linguagem natural de um ou mais recursos desejados/ necessários para um sistema de software.  
Contém as funcionalidades importantes para os usuários/clientes do sistema  
Conta uma *história* acerca de como *alguém* irá utilizar o produto (sistema) para alcançar um determinado *objetivo*

**Etapas:**
**1. Cartão:** descrição por escrito da história
- perguntas:
    - "Quem" 
    

**2. Conversação:** discução para explicar detalhes
- o que o cliente e a equipe entenderam
- traduzir 


**3. Confirmação:** critérios que confirmam a conclusão
- Critérios que precisam ser alcançados para que a User Story atenda os requisitos do usuário e seja aceita (concluída)
- aprensentar a intenção, não a solução
- mínimo necessário para ser útil ao usuário
- evitar a adição de características desnecessárias

- Deixar bem claro o que o time deve fazer antes de iniciar
- Permitir ao time saber exatamente quando ela está completa
- Auxiliar no desenvolvimento de testes automatizados



## Modelagem
Organização dos componentes do sistema

Níveis de modelagem:
1. Sistema de Software
2. Divisão em subsistemas/pacotes
3. Divisão em classes com pacotes
4. Divisão em dados e rotinas em classes
5. Rotina interna de design

Orientada a objetos:
Vantagens:
- baseada em dados
- modularidade
- extensibilidade

Desvantagens:
- funcionalidades nos objetos
- DIficil identificar objetos
- Dificil visualizar ligações

**Princípios do design:**
- KISS -> keep it simple, stupid
- DRY -> don´t repeat yourself
- YAGNI -> You aint gonna need it
- SOLID -> 

### Modelagem CRC
- Kent Beck e Ward Cunningham (1989)
    - Introdução à object-oriented thinking (design)
- Ferramenta/Metodologia/Processo
    - Análise, modelagem e projeto de sistemas OO
- Nenhum processo sozinho garante bons resultados
    - É possível torná-los mais prováveis
    - Utilizar POO não é garantia de qualidade!

A modelagem CRC utiliza cartões de papel para registrar as responsabilidades e colaborações das classes. 

É um precosso iterativo e interativo, relaciona usuários, analistas e designers. É independente de linguagem de programação e auxilia desenvolvedores com pouca experiência.

**Responsabilidade:**
Comportamento demandado de um objeto. É o contrato para o sistema.  
Tipos:
- Fonercer informações (conhecimento):
Objeto conhece e gerencias seus dados interntos.  
Objeto conhece outros objetos relacionados
- Fazer alguma coisa (realização):  
Objeto faz algo sobre ele próprio.  
Conhece e coordena ações em outros objetos.

**Colaboração:**
Processo através do qual vários objetos interagem para
fornecer um comportamento (alcançar um objetivo).  
Possui a responsabilidade, mas não a informação.  
Relação cliente/servidor (serviço).  

**Sessão:**
- Extração e modelagem dos requisitos:  
Simulação do sistema e execução de cenários
- Diversas pessoas:  
Especialistas, projetistas, analistas e moderador
- Princípios para uma sessão de sucesso:  
Todas as ideias são potencialmente boas ideias  
Flexibilidade (diferentes visões é algo bom!)

Como preencher os cartões?  

*Classes:*  
- Procurar pelos substantivos nas descrições
- Dado o contexto, decidir os mais importantes

*Responsabilidades:*  
- O que essa classe conhece e faz?
- Verbos → Comportamento  

*Colaboradores:*  
- A classe consegue realizar isso sozinha?
- Quais informações/serviços ela precisa?
## Implementação