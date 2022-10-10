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

void ShiftAnd(tipoTexto TEXTO, tipoPadrao PADRAO, long n, long m)
{
    long mascara[MAXCHAR], i, r = 0;
    for (i = 0; i < MAXCHAR; i++)
    {
        mascara[i] = 0;
    }

    for (i = 1; i <= m; i++)
    {
        mascara[PADRAO[i - 1] + 127] |= 1 << (m - 1);
    }

    for (i = 0; i < n; i++)
    {
        r = (((unsigned long)r >> 1) | (1 << (m - 1))) & mascara[TEXTO[i] + 127];
        if ((r & 1) != 0)
        {
            printf("Casamento na posicao %3ld", i - m + 2);
        }
    }
}

int main()
{
    tipoTexto textoT = "os testes fizeram os alunos tremerem";
    tipoPadrao padraoP = "testes";
    long n = MAXTAMANHOTEXTO;
    long m = strlen(padraoP) -1;

    ShiftAnd(textoT, padraoP, n, m);

    return 0;
}