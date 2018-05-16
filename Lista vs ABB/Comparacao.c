#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include <time.h>
#include "ABB.h"

//#define MaxNum 101


int main(void) {
	srand(time(NULL));

	FILE* arquivoLista;
	FILE* arquivoABB;
	int i, MaxNum;
	FILE* arquivo;
	arquivoLista = fopen("Lista.csv", "w");
	arquivoABB = fopen("ABB.csv", "w");
	arquivo = fopen("arquivo.csv", "w");

	printf("Informe quantos elementos deseja gerar: ");
	scanf("%d", &MaxNum);

	lista* lista = criarLista();
	ABB* abb = criarABB();
	//int *valoresLista = (int*) malloc(MaxNum * sizeof(int));
	//int *valoresABB = (int*) malloc(MaxNum * sizeof(int));

	//for(i = 0; i < MaxNum; i++) valoresLista[i] = valoresABB[i] = -1;

	puts("Gerando e armazenado os valores...");


	fprintf(arquivoLista, "valores,comparacoes\n");
	fprintf(arquivoABB, "valores,comparacoes\n");
	//fprintf(arquivo, "Valor Lista Arvore\n");

	for(i = 0; i < MaxNum; i++){
		int valorAleatorio = rand()%MaxNum, comparacoesLista = 0, comparacoesABB = 0;

		if(!dfsABB(abb, valorAleatorio)){
			lista = inserirListaCalda(lista, valorAleatorio, &comparacoesLista);
			abb = inserirABB(abb, valorAleatorio, &comparacoesABB);

			//valoresABB[valorAleatorio] = comparacoesABB;
			//valoresLista[valorAleatorio] = comparacoesLista;

			fprintf(arquivo, "%d %d %d\n", valorAleatorio, comparacoesLista, comparacoesABB);
			fprintf(arquivoLista, "%d,%d\n", valorAleatorio, comparacoesLista);
			fprintf(arquivoABB, "%d,%d\n", valorAleatorio, comparacoesABB);
		}
		else{
			i--;
		}
	}



	fclose(arquivoLista);
	fclose(arquivoABB);
	fclose(arquivo);
	puts("Valores gerado com sucesso!");

	system("pause");
	system("cls");
	int busca;
	while(1){
		puts("Deseja buscar qual numero?(Digite -1 para encerrar)");
		printf("Valores validos: [0, %d[\nSua escolha: ", MaxNum);
		scanf("%d", &busca);
		if(busca == -1) break;

		if(busca >= 0 && busca < MaxNum){

			printf("Comparacoes ate encontrar o numero %d:\n", busca);
			printf("Lista: %d\n", buscaLista(lista, busca));
			printf("ABB: %d\n", buscaABB(abb, busca));

		}
		else{
			printf("Voce digitou um numero fora do intervalor [0, %d[\n", MaxNum);
		}

		system("pause");
		system("cls");
	}





	getchar();
	return 0;
}
