/*
    EXERCÍCIO 01:
    Crie um programa capaz de simular um Estacionamento. Inicialmente, deverá
    ser solicitado ao usuário o tipo de técnica a ser utilizada (Lista, Pilha ou
    Fila). Após a escolha da técnica, deverá ser solicitado opções do tipo:
        a. estacionar o carro
        b. retirar o carro
        c. olhar carro (verificar se o carro está no local)
    A estrutura a ser utilizada (Pilha, Fila ou Lista) representará o estacionamento.
    Sugestão: Crie um menu para apresentar as opções acima.

    OBS: No caso de se escolher:
        * a estrutura de pilha, deve-se supor que o estacionamento possui somente
        uma entrada e só cabe um carro de largura, não permitindo manobra dentro do
        estacionamento. Assim, deverá ser utilizado 2 pilhas: uma pilha para o
        estacionamento principal e outra para o estacionamento secundário, pois assim,
        para remover um carro deve-se retirar todos os carros que estão no topo do
        estacionamento principal, um a um, até encontrar o carro desejado. Os carros
        retirados devem ser colocados na pilha secundária, e depois devolvidos
        para a pilha primária. Se for estacionar um carro, deve-se colocá-lo no
        final do estacionamento primário.
        * a estrutura de fila, supor que o estacionamento possui duas entradas,
        uma em cada extremo, mas possui a largura de um único carro, não permitindo a
        manobra. Assim, para retirar um determinado carro, deve-se retirar da
        frente e colocar no final da fila até encontrar o carro desejado.
        Se for estacionar um novo carro, deve-se sempre colocar no final da fila.
        * a estrutura de Lista, o carro deverá ser colocado em uma posição
        qualquer de acordo com a ordem das placas. O carro pode ser retirado de
        qualquer posição.

        Autor: Danilo Domingues Quirino
        Versão: 202208-03
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCarros
{
    char placa[8];
    char proprietario[30];
} CAR;

typedef struct sNoh
{
    CAR veiculo;
    struct sNoh *next;
} NOH;

void init(NOH **init)
{
    *init = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void freeNode(NOH *no)
{
    free(no);
}

int empty(NOH *ponteiro)
{
    if (ponteiro == NULL)
        return 1;
    return 0;
}

/*
void debug(NOH *ponteiro)
{
    while (ponteiro != NULL)
    {
        printf("\n\n\t\t%s", ponteiro->veiculo.placa);
        ponteiro = ponteiro->next;
    }
}
*/

/*
    Optei por ser genérico na hora de verificar se tem algum veículo em particular na estrutura,
    respeitando apenas a estrutura em si durante as inclusões e remoções.
    Podemos imaginar que para verificar a existência ou não de um veículo em particular, temos a
    posibilidade de "andar" ao lados dos mesmo.
*/
int observar(NOH *ponteiro, char placa[])
{
    while (ponteiro != NULL)
    {
        if ((strcmp(ponteiro->veiculo.placa, placa)) != 0)
            ponteiro = ponteiro->next;
        else
            return 1;
    }
    return 0;
}

// Funções da Estrutura de __LISTA__
void inserirLista(NOH **lista, CAR cliente)
{
    NOH *inserir;
    NOH *aux;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->veiculo = cliente;
        inserir->next = NULL;

        if (empty(*lista))
        {
            // Caso a lista esteja vazia, inclusão do primeiro item
            *lista = inserir;
        }
        else
        {
            aux = *lista;
            // O item a ser inserido é menor que o primeiro da lista?
            if (strcmp(inserir->veiculo.placa, aux->veiculo.placa) < 0)
            {
                inserir->next = aux;
                *lista = inserir;
            }
            else
            {
                // O proximo do auxiliar é diferente de nulo E item a ser inserido é maior que a posição seguinte ao auxiliar?
                while ((aux->next != NULL) && (strcmp(inserir->veiculo.placa, aux->next->veiculo.placa) > 0))
                {
                    aux = aux->next;
                }
                inserir->next = aux->next;
                aux->next = inserir;
            }
        }
    }
    else
    {
        printf("\nErro na alocacao do no");
        exit(1);
    }
}

CAR removerLista(NOH **lista, char placa[])
{
    CAR veiculo;
    NOH *aux, *remover;

    if (!empty(*lista))
    {
        if (strcmp((*lista)->veiculo.placa, placa) == 0)
        {
            remover = *lista;
            *lista = (*lista)->next;
        }
        else
        {
            aux = *lista;
            while ((strcmp(aux->next->veiculo.placa, placa)) != 0)
            {
                aux = aux->next;
            }
            remover = aux->next;
            aux->next = aux->next->next;
        }

        veiculo = remover->veiculo;
        freeNode(remover);
    }
    else
    {
        strcpy(veiculo.placa, "null");
    }
    return veiculo;
}

// Funções da Estrutura de __PILHA__
void push(NOH **top, CAR cliente)
{
    NOH *inserir;
    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->veiculo = cliente;
        if (!empty(*top))
            inserir->next = *top;
        else
            inserir->next = NULL;
        *top = inserir;
    }
    else
    {
        printf("\nErro na alocacao do no.\n");
        return;
    }
}

CAR pop(NOH **top)
{
    NOH *remover;
    CAR veiculo;

    if (!empty(*top))
    {
        remover = *top;
        veiculo = remover->veiculo;

        *top = (*top)->next;
        freeNode(remover);
    }
    else
    {
        strcpy(veiculo.placa, "null");
    }
    return veiculo;
}

CAR removerPilha(NOH **original, char placa[])
{
    NOH *pilhaAux;
    CAR veiculo;
    int procurando = 1;

    init(&pilhaAux);

    if (!empty(*original))
    {
        while (procurando)
        {
            veiculo = pop(original);
            // Se não houver mais veiculos na pilha original ou se encontrar o veiculo correto
            if ((strcmp(veiculo.placa, "null") == 0) || (strcmp(veiculo.placa, placa) == 0))
                procurando = 0;
            else
                push(&pilhaAux, veiculo); // Guardar o veiculo incorreto na pilha auxiliar
        }

        // Retonar veiculos da pilha auxiliar para a original
        while (!empty(pilhaAux))
        {
            push(original, pop(&pilhaAux));
        }
    }
    else
    {
        strcpy(veiculo.placa, "null");
    }
    return veiculo;
}

// Funções da Estrutura de __FILA__
void enqueue(NOH **inicio, NOH **fim, CAR cliente)
{
    NOH *inserir;
    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->veiculo = cliente;
        inserir->next = NULL;

        if (empty(*inicio))
            *inicio = inserir;

        else
            (*fim)->next = inserir;
        *fim = inserir;
    }
    else
    {
        printf("Erro na alocacao do no.\n");
        return;
    }
}

CAR dequeue(NOH **inicio, NOH **fim)
{
    NOH *remover;
    CAR veiculo;

    if (!empty(*inicio))
    {
        remover = *inicio;
        *inicio = (*inicio)->next;
        if (*inicio == NULL)
            *fim = NULL;

        veiculo = remover->veiculo;
        freeNode(remover);
    }
    else
    {
        strcpy(veiculo.placa, "null");
    }
    return veiculo;
}

CAR removerFila(NOH **inicio, NOH **fim, char placa[])
{
    NOH *primeiroDaFila = *inicio; // O primeiro carro da fila antes de começar a rodar
    CAR veiculo;
    int procurando = 1;

    if (!empty(*inicio))
    {
        while (procurando)
        {
            veiculo = dequeue(inicio, fim);
            // Se voltar para o veiculo primeiro da fila original ou se encontrar o veiculo correto
            if ((strcmp(veiculo.placa, primeiroDaFila->veiculo.placa) == 0) || (strcmp(veiculo.placa, placa) == 0))
                procurando = 0;
            else
                enqueue(inicio, fim, veiculo); // Guardar o veiculo incorreto de volta na fila, agora no final
        }
    }
    else
    {
        strcpy(veiculo.placa, "null");
    }
    return veiculo;
}

// Funções GERAIS
int menuEstrutura()
{
    int op;
    printf("\n----------\n\tESCOLHA SUA ESTRUTURA DE DADOS FAVORITA");
    printf("\n1 -\tUtilizar uma Lista de Veiculos");
    printf("\n2 -\tUtilizar uma Pilha de Veiculos");
    printf("\n3 -\tUtilizar uma Fila de Veiculos");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 3);
    return op;
}

int menuEstacionamento()
{
    int op;
    printf("\n----------\n\tESCOLHA A OPERACAO DESEJADA");
    printf("\n1 -\tEstacionar Veiculo");
    printf("\n2 -\tRetirar um Veiculo");
    printf("\n3 -\tObservar um Veiculo");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 3);
    return op;
}

void lerTexto(char *texto, int tamanho)
{
    // fflush(stdin);
    __fpurge(stdin);
    fgets(texto, tamanho, stdin);
    if (texto[strlen(texto) - 1] == '\n')
    {
        texto[strlen(texto) - 1] = '\0';
    }
}

CAR lerInformacoes()
{
    CAR veiculo;

    printf("\nPlaca do Veiculo: ");
    lerTexto(veiculo.placa, 8);
    printf("Proprietario do Veiculo: ");
    lerTexto(veiculo.proprietario, 30);
    return veiculo;
}

void apresentarRemocao(CAR veiculo)
{
    if ((strcmp(veiculo.placa, "null") != 0))
    {
        printf("\nVeiculo removido:\n\tPlaca: %s\n\tProprietario:%s\n", veiculo.placa, veiculo.proprietario);
    }
    else
        printf("\nVeiculo nao encontrado.");
}

int main()
{
    int op, opp, presenteNoEstacionamento;
    NOH *inicio;
    NOH *fim;
    CAR veiculo;

    char placa[8];

    init(&inicio);

    do
    {
        op = menuEstrutura();
        switch (op)
        {
        case 1:
            printf("\tLista de Veiculos ");
            do
            {
                opp = menuEstacionamento();
                switch (opp)
                {
                case 1:
                    printf("\tEstacionar um Veiculo");
                    inserirLista(&inicio, lerInformacoes());
                    // debug(inicio);
                    break;

                case 2:
                    printf("\tRemover um veiculo");
                    printf("\nInforme a placa do veiculo a ser retirado: ");
                    lerTexto(placa, 8);
                    veiculo = removerLista(&inicio, placa);
                    apresentarRemocao(veiculo);
                    break;

                case 3:
                    printf("\tObservar Estacionamento");
                    printf("\nInforme a placa do veiculo a ser procurado: ");
                    lerTexto(placa, 8);
                    presenteNoEstacionamento = observar(inicio, placa);
                    if (presenteNoEstacionamento)
                        printf("Veiculo presente no Estacionamento");
                    else
                        printf("Veiculo nao esta no Estacionamento");
                    break;

                case 0:
                    printf("\tRetornando ao menu anterior...");
                    break;
                }
            } while (opp != 0);
            break;

        case 2:
            printf("\tPilha de Veiculos");
            do
            {
                opp = menuEstacionamento();
                switch (opp)
                {
                case 1:
                    printf("\tEstacionar um Veiculo");
                    push(&inicio, lerInformacoes());
                    // debug(inicio);
                    break;

                case 2:
                    printf("\tRemover um veiculo");
                    printf("\nInforme a placa do veiculo a ser retirado: ");
                    lerTexto(placa, 8);
                    veiculo = removerPilha(&inicio, placa);
                    apresentarRemocao(veiculo);
                    break;

                case 3:
                    printf("\tObservar Estacionamento");
                    printf("\nInforme a placa do veiculo a ser procurado: ");
                    lerTexto(placa, 8);
                    presenteNoEstacionamento = observar(inicio, placa);
                    if (presenteNoEstacionamento)
                        printf("Veiculo presente no Estacionamento");
                    else
                        printf("Veiculo nao esta no Estacionamento");
                    break;

                case 0:
                    printf("\tRetornando ao menu anterior...");
                    break;
                }
            } while (opp != 0);
            break;

        case 3:
            init(&fim);
            printf("\tFila de Veiculos");
            do
            {
                opp = menuEstacionamento();
                switch (opp)
                {
                case 1:
                    printf("\tEstacionar um Veiculo");
                    enqueue(&inicio, &fim, lerInformacoes());
                    // debug(inicio);
                    break;

                case 2:
                    printf("\tRemover um veiculo");
                    printf("\nInforme a placa do veiculo a ser retirado: ");
                    lerTexto(placa, 8);
                    veiculo = removerFila(&inicio, &fim, placa);
                    apresentarRemocao(veiculo);
                    break;

                case 3:
                    printf("\tObservar Estacionamento");
                    printf("\nInforme a placa do veiculo a ser procurado: ");
                    lerTexto(placa, 8);
                    presenteNoEstacionamento = observar(inicio, placa);
                    if (presenteNoEstacionamento)
                        printf("Veiculo presente no Estacionamento");
                    else
                        printf("Veiculo nao esta no Estacionamento");
                    break;

                case 0:
                    printf("\tRetornando ao menu anterior...");
                    break;
                }
            } while (opp != 0);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;

    return 0;
}
