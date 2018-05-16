#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


lista* criarLista(){
	lista* novaLista = (lista*) malloc(sizeof(lista));
	novaLista = NULL;
	return novaLista;
}

lista* inserirListaCalda(lista* cabeca, int valor, int *comparacoes){
	lista* novoNo = (lista*) malloc(sizeof(lista));
	novoNo->valor = valor;
	novoNo->proximo = NULL;

	if(cabeca == NULL){
		//(*comparacoes)++;
		cabeca = novoNo;
	}

	else{
		lista* temp = cabeca;
		(*comparacoes)++;

		while(temp->proximo != NULL){
			temp = temp->proximo;
			(*comparacoes)++;
		}

		temp->proximo = novoNo;
	}

	return cabeca;
}


void imprimirLista(lista* head){

    if(head != NULL){
      printf("%d ", head->valor);
      imprimirLista(head->proximo);
    }

}

int buscaLista(lista* cabeca, int valor){
	int comparacoes = 0;
	while(cabeca->valor != valor){
		comparacoes++;
		cabeca = cabeca->proximo;
	}

	return comparacoes;
}
