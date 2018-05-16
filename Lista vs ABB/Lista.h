#ifndef LISTA_H_
#define LISTA_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int valor;
	struct lista* proximo;
}lista;

lista* criarLista();

lista* inserirListaCalda(lista* cabeca, int valor, int *comparacoes);

void imprimirLista(lista* head);

int buscaLista(lista* cabeca, int valor);


#endif /* LISTA_H_ */
