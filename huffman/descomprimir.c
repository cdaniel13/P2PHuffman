#include <stdio.h>
#include "descomprimir.h"
#include "utilidade.h"
#include "descomprimirUtilidade.h"
#include <string.h>
#include <locale.h>

void descomprimir(){
	setlocale(LC_ALL, "Portuguese");

    FILE *arquivoComprimido = NULL;
    FILE *arquivoDescomprimido = NULL;

    char nomeArquivoComprimido[tamMax];
    char nomeArquivoDescomprimido[tamMax];

    system("cls");
    puts("Digite o nome do arquivo compactado:");
    scanf("%[^\n]s", nomeArquivoComprimido);
    getchar();

    arquivoComprimido = fopen(nomeArquivoComprimido, "rb");


    while((!arquivoComprimido) || (!validarArquivoHuffman(nomeArquivoComprimido))){

    	system("cls");
        puts("Erro na abertura do arquivo!\n");

        if(!validarArquivoHuffman(nomeArquivoComprimido)){

            puts("O arquivo nao pussui a extensao correta (.huff)");
        }

        printf(" Digite o nome do arquivo compactado:\n\n Exemplo: arquivo.huff\n > ");
        scanf("%[^\n]s", nomeArquivoComprimido);
        getchar();

        arquivoComprimido = fopen(nomeArquivoComprimido, "rb");
    }

    puts("Digite o nome desejado para arquivo descomprimido:");
    scanf("%[^\n]s",  nomeArquivoDescomprimido);
    getchar();

    system("cls");
    puts("descompactando...");

    Byte tamanhoLixo, tamanhoArvore;

    int tamLixo, tamArvore;

    fscanf(arquivoComprimido, "%c", &tamanhoLixo);
    fscanf(arquivoComprimido, "%c", &tamanhoArvore);

    //pega os 3 bits do tamanho do lixo
    tamLixo = (tamanhoLixo >> 5);

    tamArvore = (tamanhoLixo & 0b00011111) << 8;
    tamArvore |= tamanhoArvore;


    HuffmanArvore* arvore = criarArvoreVazia();
    arvore = reconstruirArvore(arquivoComprimido, arvore);

    arquivoDescomprimido = fopen(nomeArquivoDescomprimido, "wb");
    descomprimirArquivo(arquivoComprimido, arquivoDescomprimido, arvore, tamLixo);


    fclose(arquivoComprimido);
    fclose(arquivoDescomprimido);

    printf("Arquivo descompactado!\nPressione enter para continuar:");
    getchar();
}

