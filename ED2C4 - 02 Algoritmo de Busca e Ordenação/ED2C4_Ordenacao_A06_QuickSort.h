//
void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vet[], int inicio, int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vet[i] <= pivo)
		{
			// realiza a troca
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particionaMediana(int vet[], int inicio, int fim)
{
    int auxiliar;
    int media = (inicio + fim) / 2;

    if (vet[media] < vet[inicio])
        troca(vet, media, inicio);
    if (vet[fim] < vet[inicio])
        troca(vet, fim, inicio);
    if(vet[media] < vet[fim])
        troca(vet, media, fim);
    

	// chama a particiona
	return particiona(vet, inicio, fim);
}

// Escolha um pivo e coloca todos os valores maiores a sua direita, e menores a sua esquerda, finalizando o pivo em sua posição
void quickSort(int *vetor, int iniVetor, int fimVetor)
{
    int pivo;
	if(iniVetor < fimVetor)
	{
		// função particionar retorna o índice do pivô
		pivo = particionaMediana(vetor, iniVetor, fimVetor);
		
		// chamadas recursivas quick_sort
		quickSort(vetor, iniVetor, pivo - 1);
		quickSort(vetor, pivo + 1, fimVetor);
	}
}