// Utilizando de uma HEAP, o elemento de maior valor sobe para a raiz e volta ao vetor ordenado
long int heapSort(int *vetor, int tamanho)
{
    int i = tamanho / 2;   // Percorrer as posições do vetor
    int pai, filho;        // Nós da arvore utilizada
    int auxiliar;          // Armazena o valor atual de comparação
    long int contador = 0; // Contar os comparações realizados (para efeitos de comparação)

    while (1)
    {
        // contador++;
        if (i > 0)
        {
            i--;
            auxiliar = vetor[i];
        }
        else
        {
            tamanho--;
            if (tamanho <= 0)
            {
                return;
            }
            auxiliar = vetor[tamanho];
            vetor[tamanho] = vetor[0];
        }

        pai = i;
        filho = (i * 2) + 1;

        while (filho < tamanho)
        {
            contador++;
            if ((filho + 1 < tamanho) && (vetor[filho + 1] > vetor[filho]))
                filho++;

            if (vetor[filho] > auxiliar)
            {
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = (pai * 2) + 1;
                contador++;
            }
            else
                break;
        }
        vetor[pai] = auxiliar;
    }
    return contador;
}