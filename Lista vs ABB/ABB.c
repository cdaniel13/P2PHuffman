#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

ABB* criarABB(){
	ABB* novaABB = (ABB*) malloc(sizeof(ABB));
	novaABB = NULL;

	return novaABB;
}

ABB* novoNoABB(int valor){
	ABB* novoNo = (ABB*) malloc(sizeof(ABB));
	novoNo->valor = valor;
	novoNo->esquerdo = novoNo->direito = NULL;

	return novoNo;
}

ABB* inserirABB(ABB* raiz, int valor, int *comparacoesABB){
	ABB* novoNo = novoNoABB(valor);

	if(raiz == NULL){
		//(*comparacoesABB)++;
		raiz = novoNo;
	}

	else{
		ABB* temp = raiz;
		ABB* ant = NULL;

		while(temp != NULL){
			ant = temp;
			(*comparacoesABB)++;
			if(temp->valor < valor){
				temp = temp->direito;
			}
			else{
				temp = temp->esquerdo;
			}
		}
		if(ant->valor < valor){
			ant->direito = novoNo;
		}
		else{
			ant->esquerdo = novoNo;
		}
/*
		(*comparacoesABB)++;
		if(raiz->valor < valor){
			inserirABB(raiz->esquerdo, valor, comparacoesABB);
		}
		else if(raiz->valor > valor){
			inserirABB(raiz->direito, valor, comparacoesABB);
		}
*/
	}

	return raiz;
}

int dfsABB(ABB* abb, int valor){

  int achou = 0;

  if(abb == NULL)return 0;

  if(abb->valor == valor) return 1;

  achou = dfsABB(abb->esquerdo, valor);
  if(achou) return 1;

  achou = dfsABB(abb->direito, valor);
  if(achou) return 1;

  return 0;

}

int buscaABB(ABB* abb, int valor){

	int comparacoes = 0;

	while(abb->valor != valor){

		if(abb->valor < valor){
			comparacoes++;
			abb = abb->direito;
		}

		else{
			comparacoes++;
			abb = abb->esquerdo;
		}
	}

	return comparacoes;
}

/*void print_pre_order(ABB* abb){
  printf(" (");
  if (abb != NULL){
    printf(" %d ", abb->valor);
     print_pre_order(abb->esquerdo);
     print_pre_order(abb->direito);
  }
  printf(") ");
}
*/
