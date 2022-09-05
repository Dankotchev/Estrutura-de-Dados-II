#include <stdio.h>
#include <time.h>
#include "ED2C4_Ordenacao_A01_SelectSort.h"
#include "ED2C4_Ordenacao_A02_BubbleSort.h"
#include "ED2C4_Ordenacao_A03_InsertSort.h"
#include "ED2C4_Ordenacao_A04_ShellSort.h"
#include "ED2C4_Ordenacao_A05_HeapSort.h"
#include "ED2C4_Ordenacao_A06_QuickSort.h"
#include "ED2C4_BuscaPesquisa_EX01.h"
#define TAM 20

void apresentarVetor(int *vetor)
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%03d ", vetor[i]);
    }
    printf("\n________________\n");
}

void lerVetor(int *vetor)
{
    printf("Insira os 20 valores do vetor.\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("Informe o valor #%d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void duplicarVetor(int *vetorOriginal, int *vetorCopia)
{
    for (int i = 0; i < TAM; i++)
    {
        vetorCopia[i] = vetorOriginal[i];
    }
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tESCOLHA O METODO DE ORDENACAO DESEJADO");
    printf("\n1 -\tInserir um vetor");
    printf("\n2 -\tBubble Sort");
    printf("\n3 -\tSelect Sort");
    printf("\n4 -\tInsert Sort");
    printf("\n5 -\tHeap   Sort");
    printf("\n6 -\tShell  Sort");
    printf("\n7 -\tQuick  Sort");
    printf("\n8 -\tBusca  Sequencial");
    printf("\n9 -\tBusca  Binaria");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 9);
    return op;
}

int main()
{
    srand(time(NULL));
    int op;
    int vetorOriginal[TAM], vetorDuplicado[TAM];
    int procurar, posicao;
    long int permutacoes = 0;

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            lerVetor(vetorOriginal);
            apresentarVetor(vetorOriginal);
            break;

        case 2:
            printf("\n\tBubble Short\n");
            duplicarVetor(vetorOriginal, vetorDuplicado);
            permutacoes = bubbleSort(vetorDuplicado, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetorDuplicado);
            break;

        case 3:
            printf("\n\tSelect Short\n");
            duplicarVetor(vetorOriginal, vetorDuplicado);
            permutacoes = selectSort(vetorDuplicado, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetorDuplicado);
            break;

        case 4:
            printf("\n\tInsert Short\n");
            duplicarVetor(vetorOriginal, vetorDuplicado);
            permutacoes = insertSort(vetorDuplicado, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetorDuplicado);
            break;

        case 5:
            printf("\n\tHeap   Sort\n");
            duplicarVetor(vetorOriginal, vetorDuplicado);
            permutacoes = heapSort(vetorDuplicado, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetorDuplicado);
            break;

        case 6:
            printf("\n\tShell  Sort\n");
            duplicarVetor(vetorOriginal, vetorDuplicado);
            permutacoes = shellSort(vetorDuplicado, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetorDuplicado);
            break;

        case 7:
            printf("\n\tQuick  Sort\n");
            duplicarVetor(vetorOriginal, vetorDuplicado);
            //quickSort(vetorDuplicado, 0, TAM - 1);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetorDuplicado);
            break;

        case 8:
            duplicarVetor(vetorOriginal, vetorDuplicado);
            printf("\tBusca  Sequencial\n\tInforme o valor a procurar: ");
            scanf("%d", &procurar);
            posicao = buscaSequencial(vetorDuplicado, procurar, TAM);
            if (posicao >= 0)
                printf("\tValor Encontrado na posicao %d!", posicao);
            else
                printf("\tValor nao encontrado!");
            break;

        case 9:
            duplicarVetor(vetorOriginal, vetorDuplicado);
            printf("\tBusca  Binaria\n\tInforme o valor a procurar: ");
            scanf("%d", &procurar);
            posicao = buscaBinaria(vetorDuplicado, procurar, TAM);
            if (posicao >= 0)
                printf("\tValor Encontrado na posicao %d!", posicao);
            else
                printf("\tValor nao encontrado!");
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);

    return 0;
}
