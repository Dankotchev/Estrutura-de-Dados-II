#include <stdio.h>
#include <time.h>
#include "ED1C3_Ordenacao_A01_SelectSort.h"
#include "ED1C3_Ordenacao_A02_BubbleSort.h"
#include "ED1C3_Ordenacao_A03_InsertSort.h"
#include "ED1C3_Ordenacao_A04_ShellSort.h"
#include "ED1C3_Ordenacao_A05_HeapSort.h"
#include "ED1C3_Ordenacao_A06_QuickSort.h"
#define TAM 500

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
            printf("\n\tBubble Short\nO vetor desordenado:\n");
            inserirAleatorio(vetor);
            apresentarVetor(vetor);
            permutacoes = bubbleSort(vetor, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetor);
            break;

        case 2:
            printf("\n\tSelect Short\nO vetor desordenado:\n");
            inserirAleatorio(vetor);
            apresentarVetor(vetor);
            permutacoes = selectSort(vetor, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetor);
            break;

        case 3:
            printf("\n\tInsert Short\nO vetor desordenado:\n");
            inserirAleatorio(vetor);
            apresentarVetor(vetor);
            permutacoes = insertSort(vetor, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetor);
            break;

        case 4:
            printf("\n\tShell  Sort\nO vetor desordenado:\n");
            inserirAleatorio(vetor);
            apresentarVetor(vetor);
            permutacoes = shellSort(vetor, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetor);
            break;

        case 5:
            printf("\n\tHeap   Sort\nO vetor desordenado:\n");
            inserirAleatorio(vetor);
            apresentarVetor(vetor);
            permutacoes = heapSort(vetor, TAM);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetor);
            break;

        case 6:
            printf("\n\tQuick  Sort\nO vetor desordenado:\n");
            inserirAleatorio(vetor);
            apresentarVetor(vetor);
            quickSort(vetor, 0, TAM-1);
            printf("Foram necessarias %ld operacoes;\n\tO vetor ordenado: \n", permutacoes);
            apresentarVetor(vetor);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);

    return 0;
}
