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

// Função que define e codifica simbolos
void defineAlfabeto(tipoAlfabeto alfabeto, FILE* arquivoAlfabeto)
{
    char simbolos[MAXALFABETO + 1];
    int i;
    char *temporario;

    for (i = 0; i <= MAXALFABETO; i++)
        alfabeto[i] = FALSE;
    
    fgets(simbolos, MAXALFABETO +1, arquivoAlfabeto);
    temporario = strchr(simbolos, '\n');
    if (temporario != NULL)
        *temporario = 0;
    for (i = 0; i <= strlen(simbolos); i++)
        alfabeto[simbolos[i] + 127] = TRUE;
    alfabeto[0] = FALSE;
    
}

// Primeira etapa da compressão

// Segunda etapa da compressão

// Terceira etapa da compressão

// Função responsável por comprimir um arquivo texto, utilizando as três etapas
void compressao(FILE *arquivoTexto, FILE *arquivoAlfabeto, FILE *arquivoComprimido)
{
    tipoAlfabeto alfabeto;
    tipoPalavra palavra, linha;
    int indice = 1, maxCompCod; //? entender esse maxCompCod
    tipoPesos p;
    tipoDicionario vocabulario = (tipoDicionario) calloc(M+1, sizeof(tipoItem));
    tipoVetoresBO vetoresBaseOffset = (tipoVetoresBO) calloc(MAXTAMVETORESDO + 1, sizeof(tipoBaseOffset));

    printf("Definindo alfabeto\n");
    defineAlfabeto(alfabeto, arquivoAlfabeto);
    *linha = '\0';
}





int main()
{
    FILE *arquivoTexto, *arquivoAlfabeto, *arquivoComprimido;
    compressao(arquivoTexto, arquivoAlfabeto, arquivoComprimido);
    return 0;
}
