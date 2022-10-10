#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define BASENUM 128
#define MAXALFABETO 255
#define MAXTAMVETORESDO
#define TRUE 1
#define FALSE 0

// tipos programa E.26
typedef char tipoChave[BASENUM];
typedef unsigned tipoPesos[BASENUM][MAXALFABETO];


#define MAXTAMANHOTEXTO 1000
#define MAXTAMANHOPADRAO 10
#define MAXCHAR 256
#define NUMMAXERROS 10

typedef char tipoTexto[MAXTAMANHOTEXTO];
typedef char tipoPadrao[MAXTAMANHOPADRAO];

typedef short tipoAlfabeto[MAXALFABETO + 1];
typedef struct tipoBaseOffset
{
    int base, offset;
}tipoBaseOffset;
typedef tipoBaseOffset *tipoVetoresBO;
typedef char tipoPalavra[MAXCHAR];
typedef tipoPalavra *tipoVetorPalavra;

// Inserir outras funções

// Primeira etapa da compressão

// Segunda etapa da compressão

// Terceira etapa da compressão

// Função responsável por comprimir um arquivo texto, utilizando as três etapas
void compressao(FILE *arquivoTexto, FILE *arquivoAlfabeto, FILE *arquivoComprimido)
{

}





int main()
{
    FILE *arquivoTexto, *arquivoAlfabeto, *arquivoComprimido;
    compressao(arquivoTexto, arquivoAlfabeto, arquivoComprimido);
    return 0;
}
