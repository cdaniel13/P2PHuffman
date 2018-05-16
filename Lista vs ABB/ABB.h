#ifndef ABB_H_
#define ABB_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct ABB{
	int valor;
	struct ABB *esquerdo;
	struct ABB *direito;
}ABB;


ABB* criarABB();

ABB* novoNoABB(int valor);

ABB* inserirABB(ABB* raiz, int valor, int *comparacoesABB);

int dfsABB(ABB* abb, int valor);

//void print_pre_order(ABB* bst);

int buscaABB(ABB* abb, int valor);


#endif /* ABB_H_ */
