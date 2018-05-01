#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <locale.h>
#include "comprimir.h"
#include "comprimirUtilidade.h"
#include "utilidade.h"
#include "filaPrioridade.h"
#include "HuffmanArvore.h"
#include <string.h>



void comprimir(){

	setlocale(LC_ALL, "Portuguese");

	FILE* arquivoEntrada = NULL;
	FILE* arquivoSaida = NULL;

	char nomeArquivoEntrada[tamMax];
	char nomeArquivoSaida[tamMax];



	system("cls");
	printf("Digite o nome do arquivo que deseja comprimir:\n");
	scanf("%[^\n]s", nomeArquivoEntrada);
	getchar();
	arquivoEntrada = fopen(nomeArquivoEntrada, "rb");


	while(!arquivoEntrada){
		puts("Erro ao abrir o arquivo, tente novamente:");


			printf("Digite o nome do arquivo que deseja comprimir:\n");
			scanf("%[^\n]s", nomeArquivoEntrada);
			getchar();
			arquivoEntrada = fopen(nomeArquivoEntrada, "rb");

	}

	puts("Digite o nome desejado para o arquivo comprimido:");
	scanf("%[^\n]s", nomeArquivoSaida);
	getchar();
	strcat(nomeArquivoSaida, ".huff");

	system("cls");
	puts("Compactando, por favor aguarde...\n");

	int *frequencia = pegarFrequenciaBytes(arquivoEntrada);

	//volta para o começo do arquivo apos pegar as frequencias dos bytes
	fseek(arquivoEntrada, 0, SEEK_SET);

	filaPrioridade* fila = criarFila();

	construirFila(fila, frequencia);

	HuffmanArvore* arvore = construirArvore(fila);

	//matriz dos novos bits que irao representar os bytes
	Byte matriz[tamMax][tamMax], vetorTemp[tamMax];

	iniciarTabelaCaminhos(matriz);
	criarTabelaCaminhos(matriz, vetorTemp, arvore, 0);

	int *tamanhoArvore = (int*) malloc(sizeof(int));

	arquivoSaida = fopen(nomeArquivoSaida, "wb");

	//criando o cabecalho e resevando 2 bytes para o tamanho do lixo e da arvore...
	criarCabecalho(arquivoSaida, arvore, tamanhoArvore);
	escreverArquivoCompactado(arquivoEntrada, arquivoSaida, matriz, *tamanhoArvore);

	printf("Arquivo compactado!!\nPressione enter para continuar:");
	getchar();

	fclose(arquivoEntrada);
	fclose(arquivoSaida);



}


