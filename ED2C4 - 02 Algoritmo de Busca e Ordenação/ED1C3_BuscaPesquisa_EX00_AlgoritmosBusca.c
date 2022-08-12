#include <stdio.h>
#include <time.h>
#define TAM 10

void bubble_sort(int vetor[TAM], int n)
{
    int k, j, aux;
    for (k = n - 1; k > 0; k--)
    {
        for (j = 0; j < k; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void inserirAleatorio(int vetorD[TAM], int vetorO[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        vetorO[i] = vetorD[i] = rand() % 100 + 1;
    }
    printf("\nVetor preenchido\n");
    for (int j = 0; j < TAM; j++)
    {
        printf("%02d ", vetorD[j]);
    }
    bubble_sort(vetorO, TAM);
}

int buscaExaustiva(int vetor[TAM], int valor)
{
    int i = 0;
    int contador = 1;
    printf("\t\t\tAntes do while... contador = %d\n", contador);

    // Enquanto o valor da posição i do vetor for diferente do valor
    // E o índice i menor que o TAMANHO do vetor
    while ((vetor[i] != valor ) && (i < TAM))
    {
        i = i + 1;
        contador++;
        printf("\t\t\tDentro do while, nao encontrado, mais um passo... contador = %d\n", contador);
    }
    printf("Foram realizados %d passos", contador);

    // Se o índice for menor que o TAMANHO e o valor da posição i for o valor procurado
    if ((i < TAM) && (vetor[i] == valor))
        return i; // achou na posição i
    else
        return -1; // não achou
}

int buscaSequencial(int vetor[TAM], int valor)
{
    int i = 0;
    int contador = 1;
    while (valor > (vetor[i] && i < TAM))
    {
        i = i + 1;
        contador++;
    }
    printf("Foram realizados %d passos", contador);
    if (i < TAM && (valor == vetor[i]))
        return i; // achou na posição i
    else
        return -1; // não achou
}

int buscaBinaria(int vetor[TAM], int valor)
{
    int inicio = 0;
    int fim = TAM - 1;
    int meio;
    int contador = 1;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (valor == vetor[meio])
            return meio;
        if (valor < vetor[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
        contador++;
    }
    printf("Foram realizados %d passos", contador);
    return -1; // não encontrado
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tESCOLHA A OPERACAO DESEJADA");
    printf("\n1 -\tInserir valores no vetor");
    printf("\n2 -\tBusca Exaustiva");
    printf("\n3 -\tBusca _____");
    printf("\n4 -\tBusca _____");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 4);
    return op;
}

int main()
{
    srand(time(NULL));
    int op;
    int vetorOrdenado[TAM], vetorDesordenado[TAM];
    int procurar, posicao;

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\tInserção de Valores no vetor");
            inserirAleatorio(vetorDesordenado, vetorOrdenado);
            break;

        case 2:
            printf("\tBusca Exaustiva\n\tInforme o valor a procurar: ");
            scanf("%d", &procurar);
            posicao = buscaExaustiva(vetorDesordenado, procurar);
            if (posicao >=0)
                printf("\tValor Encontrado na posicao %d!", posicao);
            else
                printf("\tValor nao encontrado!");
            break;

        case 3:
            printf("\tBusca Exaustiva\n\tInforme o valor a procurar: ");
            scanf("%d", &procurar);
            posicao = buscaExaustiva(vetorDesordenado, procurar);
            if (posicao >=0)
                printf("\tValor Encontrado na posicao %d!", posicao);
            else
                printf("\tValor nao encontrado!");
            break;

        case 4:
            printf("\tBusca Binaria\n\tInforme o valor a procurar: ");
            scanf("%d", &procurar);
            posicao = buscaBinaria(vetorOrdenado, procurar);
            if (posicao >=0)
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
