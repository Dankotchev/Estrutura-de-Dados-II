#include <stdio.h>
#include <time.h>
#define TAM 10

// Função de ordenação para ordenar um dos vetores para a busca
// o entendimento ficará para as próximas aulas
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

    // Enquanto o valor da posição i do vetor for diferente do valor
    // E o índice i menor que o TAMANHO do vetor
    while ((vetor[i] != valor) && (i < TAM))
    {
        i = i + 1;
        contador++;
    }
    printf("Foram realizados %d passos", contador);

    // Se o índice for menor que o TAMANHO e o valor da posição i for o valor procurado
    if ((i < TAM) && (valor == vetor[i]))
        return i; // Encontrado na posição i
    else
        return -1; // Não encontrado
}

int buscaSequencial(int vetor[TAM], int valor)
{
    int i = 0;
    int contador = 1;

    // Enquanto o valor procurado for menor que o valor da posição i
    // E o índice for menor que o TAMANHO do vetor
    while ((valor > vetor[i]) && (i < TAM))
    {
        i = i + 1;
        contador++;
    }

    // Se o índice for menor que o TAMANHO e o valor da posição i for o valor procurado
    if ((i < TAM) && (valor == vetor[i]))
        return i; // Encontrado na posição i
    else
        return -1; // Não encontrado
}

int buscaBinaria(int vetor[TAM], int valor)
{
    int inicio = 0;    // Definindo o ínicio de um vetor
    int fim = TAM - 1; // Definindo o fim do vetor
    int meio;
    int contador = 1;

    // Enquanto a posição íncio for menor ou igual a posição fim
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (valor == vetor[meio])
        {
            printf("Foram realizados %d passos", contador);
            return meio; // Valor encontrado no meio do vetor definido, retorna a posição
        }

        // Se não encontrado na metade do vetor
        // verifica se o valor procurado é menor que o valor da posição do meio.
        if (valor < vetor[meio])
            fim = meio - 1; // Caso seja menor, o FIM passa ser a posição anterior a atual
        else
            inicio = meio + 1; // Caso seja maior, o ÍNICIO passa ser a posição seguinte a atual
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
    printf("\n3 -\tBusca Sequencial");
    printf("\n4 -\tBusca Binaria");
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
            if (posicao >= 0)
                printf("\tValor Encontrado na posicao %d!", posicao);
            else
                printf("\tValor nao encontrado!");
            break;

        case 3:
            printf("\tBusca Sequencial\n\tInforme o valor a procurar: ");
            scanf("%d", &procurar);
            posicao = buscaExaustiva(vetorOrdenado, procurar);
            if (posicao >= 0)
                printf("\tValor Encontrado na posicao %d!", posicao);
            else
                printf("\tValor nao encontrado!");
            break;

        case 4:
            printf("\tBusca Binaria\n\tInforme o valor a procurar: ");
            scanf("%d", &procurar);
            posicao = buscaBinaria(vetorOrdenado, procurar);
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
