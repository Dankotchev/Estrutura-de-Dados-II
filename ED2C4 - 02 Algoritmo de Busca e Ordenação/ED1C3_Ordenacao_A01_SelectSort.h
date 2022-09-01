// Compara termo a termo, buscando o menor valor para inserir na menor posição a cada comparação
long int selectSort(int *vetor, int tamanho)
{
    int i, j;              // Percorrer os laços de repetição passando por todas posições
    int posValorMinimo;    // Posição onde encontra-se o menor valor
    int auxiliar;          // Auxiliar, para realizar a troca de valores
    long int contador = 0; // Contar os comparações realizados (para efeitos de comparação)

    for (i = 0; i < (tamanho - 1); i++)
    {
        posValorMinimo = i;
        for (j = (i + 1); j < tamanho; j++)
        {
            contador++;
            if (vetor[j] < vetor[posValorMinimo])
                posValorMinimo = j; // A menor posição passa a ser a de j
        }
    
        // Caso encontre um valor menor fora da posição i, realiza a troca
        if (i != posValorMinimo)
        {
            auxiliar = vetor[i];
            vetor[i] = vetor[posValorMinimo];
            vetor[posValorMinimo] = auxiliar;
        }
    }
    return contador;
}