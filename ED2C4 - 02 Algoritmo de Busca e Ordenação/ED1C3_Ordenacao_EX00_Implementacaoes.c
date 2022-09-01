#include <stdio.h>
#include <time.h>
#include "ED1C3_Ordenacao_BubbleSort.h"
#define TAM 50

void apresentarVetor(int *vetor)
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%04d ", vetor[i]);
    }
    printf("\n________________\n");
}

void inserirAleatorio(int *vetor)
{
    for (int i = 0; i < TAM; i++)
    {
        vetor[i] = rand() % 1000 + 1;
    }
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tESCOLHA O METODO DE ORDENACAO DESEJADO");
    printf("\n1 -\tBubble Sort");
    printf("\n2 -\tSelect Sort");
    printf("\n3 -\tInsert Sort");
    printf("\n4 -\tShell  Sort");
    printf("\n5 -\tHeap   Sort");
    printf("\n6 -\tQuick  Sort");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 6);
    return op;
}

int main()
{
    srand(time(NULL));
    int op;
    int vetor[TAM];
    long int permutacoes = 0;

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\n\tBubble Short\nO vetor atualmente tem essa forma:\n");
            inserirAleatorio(&vetor);
            apresentarVetor(&vetor);
            permutacoes = bubbleSort(&vetor, TAM);
            printf("Foram necessarias %ld operacoes para ordenar o vetor;\n\tO vetor ordenado: \n"), permutacoes;
            apresentarVetor(vetor);
            break;

        case 2:
            printf("\tBusca Exaustiva\n\tInforme o valor a procurar: ");

            break;

        case 3:
            printf("\tBusca Sequencial\n\tInforme o valor a procurar: ");

            break;

        case 4:
            printf("\tBusca Binaria\n\tInforme o valor a procurar: ");

            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);

    return 0;
}
