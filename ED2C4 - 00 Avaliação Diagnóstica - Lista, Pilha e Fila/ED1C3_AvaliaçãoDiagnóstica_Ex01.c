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
        Versão: 202207-28
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

void initPilha(NOH **inicio, NOH **fim)
{
    *inicio = NULL;
    *fim = NULL;
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

int observarLista(NOH *lista, char placa[])
{
    while (lista != NULL)
    {
        if ((strcmp(lista->veiculo.placa, placa)) != 0)
            return 1;
        lista = lista->next;
    }
    return 0;
}

void inserirLista(NOH **lista, CAR cliente)
{
    NOH *inserir;
    NOH *aux = *lista;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->veiculo = cliente;

        if (strcmp(inserir->veiculo.placa, aux->veiculo.placa) < 0)
        {
            (*lista)->next = inserir;
            inserir->next = aux;
        }
        else
        {
            while (strcmp(aux->next->veiculo.placa, inserir->veiculo.placa) <= 0)
            {
                aux = aux->next;
            }

            inserir->next = aux->next;
            aux->next = inserir;
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
        return NULL;
    }
    return veiculo;
}

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
    CAR cliente;

    if (!empty(*inicio))
    {
        remover = *inicio;
        *inicio = (*inicio)->next;
        if (*inicio == NULL)
            *fim = NULL;

        cliente = remover->veiculo;
        freeNode(remover);
    }
    else
    {
        printf("Erro, fila vazia.\n");
        //        return NULL;
    }
    return cliente;
}

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
    CAR cliente;

    if (!empty(*top))
    {
        remover = *top;
        cliente = remover->veiculo;

        *top = (*top)->next;
        freeNode(remover);
    }
    else
    {
        printf("\nErro, pilha vazia.\n");
    }
    return cliente;
}

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

    printf("Placa do Veiculo: ");
    lerTexto(veiculo.placa, 8);
    printf("Proprietario do Veiculo: ");
    lerTexto(veiculo.proprietario, 30);
    return veiculo;
}

void apresentarRemocao(CAR veiculo)
{
    printf("\nVeiculo removido:\n\tPlaca: %s\n\tProprietario:%s\n",
           veiculo.placa, veiculo.proprietario);
}

int main()
{
    int op, opp, presenteNoEstacionamento;
    NOH *inicio;
    NOH *fim;
    CAR veiculo;

    char placa[8];

    do
    {
        op = menuEstrutura();
        switch (op)
        {
        case 1:
            init(&inicio);
            printf("\tLista de Veiculos ");
            do
            {
                opp = menuEstacionamento();
                switch (opp)
                {
                case 1:
                    printf("\tEstacionar um Veiculo");
                    inserirLista(&inicio, lerInformacoes());
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
                    presenteNoEstacionamento = observarLista(inicio, placa);
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
            init(&inicio);
            printf("\tPilha de Veiculos");
            do
            {
                opp = menuEstacionamento();
                switch (opp)
                {
                case 1:
                    printf("\tEstacionar um Veiculo");
                    push(&inicio, lerInformacoes());
                    break;

                case 2:
                    printf("\tRemover um veiculo");
                    printf("Informe a placa do veiculo a ser retirado: ");
                    lerTexto(placa, 8);
                    // v = removerLista(&inicio, placa);
                    break;

                case 3:
                    printf("\tEstado do estacionamento");
                    exibir(&inicio);
                    break;

                case 0:
                    printf("\tRetornando ao menu anterior...");
                    break;
                }
            } while (opp != 0);
            break;

        case 3:
            initPilha(&inicio, &fim);
            printf("\tFila de Veiculos");
            do
            {
                opp = menuEstacionamento();
                switch (opp)
                {
                case 1:
                    printf("\tEstacionar um Veiculo");
                    enqueue(&inicio, &fim, lerInformacoes());
                    break;

                case 2:
                    printf("\tRemover um veiculo");
                    printf("Informe a placa do veiculo a ser retirado: ");
                    lerTexto(placa, 8);
                    // v = removerLista(&inicio, placa);
                    break;

                case 3:
                    printf("\tEstado do estacionamento");
                    exibir(&inicio);
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
