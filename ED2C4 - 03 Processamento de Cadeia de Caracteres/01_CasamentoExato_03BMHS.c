#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAMANHOTEXTO 1000
#define MAXTAMANHOPADRAO 10
#define MAXCHAR 256
#define NUMMAXERROS 10

typedef char tipoTexto[MAXTAMANHOTEXTO];
typedef char tipoPadrao[MAXTAMANHOPADRAO];

#include "00_Auxiliares.h"

void BHMS(tipoTexto TEXTO, tipoPadrao PADRAO, long n, long m)
{
    long deslocamento[MAXCHAR + 1], i, j, k;
    
    for (j = 0; j <= MAXCHAR; j++)
    {
        deslocamento[j] = m + 1;
    }

    for (j = 1; j <= m; j++)
    {
        deslocamento[PADRAO[j - 1]] = m - j + 1;
    }

    i = m;

    while (i <= n)
    {
        k = i;
        j = m;
        while (TEXTO[k - 1] == PADRAO[j - 1] && j > 0)
        {
            k--;
            j--;
        }
        if (j == 0)
        {
            printf("Casamento na posicao %3ld", k + 1);
        }
        i += deslocamento[TEXTO[i]];
    }
}

int main()
{
    tipoTexto textoT =      "os testes fizeram os alunos tremerem";
    tipoPadrao padraoP =       "testes";
    long n = strlen(textoT) -1;
    long m = strlen(padraoP) -1;

    BHMS(textoT, padraoP, n, m);

    return 0;
}