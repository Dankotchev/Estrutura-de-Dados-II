int buscaSequencial(int *vetor, int valor, int tamanho)
{
    int i = 0;
    int contador = 1;

    while ((valor != vetor[i]) && (i < tamanho))
    {
        i = i + 1;
        contador++;
    }
    printf("Foram realizados %d iteracoes", contador);

    if ((i < tamanho) && (valor == vetor[i]))
        return i;
    else
        return -1;
}

int buscaBinaria(int *vetor, int valor, int tamanho)
{
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    int contador = 1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (valor == vetor[meio])
        {
            printf("Foram realizados %d iteracoes", contador);
            return meio;
        }

        if (valor < vetor[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
        contador++;
    }
    printf("Foram realizados %d iteracoes", contador);
    return -1;
}