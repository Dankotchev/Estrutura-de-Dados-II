# Lista de Exercícios

## Exercício 1

Crie um programa capaz de simular um Estacionamento. Inicialmente, deverá ser solicitado ao usuário o tipo de técnica a ser utilizada (Lista, Pilha ou Fila). Após a escolha da técnica, deverá ser solicitado opções do tipo:
a. estacionar o carro
b. retirar o carro
c. olhar carro (verificar se o carro está no local)
A estrutura a ser utilizada (Pilha, Fila ou Lista) representará o estacionamento.
Sugestão: Crie um menu para apresentar as opções acima.

OBS: No caso de se escolher:
- **A estrutura de Pilha**, deve-se supor que o estacionamento possui somente uma entrada e só cabe um carro de largura, não permitindo manobra dentro do estacionamento. Assim, deverá ser utilizado 2 pilhas: uma pilha para o estacionamento principal e outra para o estacionamento secundário, pois assim, para remover um carro deve-se retirar todos os carros que estão no topo do estacionamento principal, um a um, até encontrar o carro desejado. Os carros retirados devem ser colocados na pilha secundária, e depois devolvidos para a pilha primária. Se for estacionar um carro, deve-se colocá-lo no final do estacionamento primário.
- **A estrutura de Fila**, supor que o estacionamento possui duas entradas, uma em cada extremo, mas possui a largura de um único carro, não permitindo a manobra. Assim, para retirar um determinado carro, deve-se retirar da frente e colocar no final da fila até encontrar o carro desejado. Se for estacionar um novo carro, deve-se sempre colocar no final da fila.
- **A estrutura de Lista**, o carro deverá ser colocado em uma posição qualquer de acordo com a ordem das placas. O carro pode ser retirado de qualquer posição.
