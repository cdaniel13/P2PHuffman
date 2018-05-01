#ifndef FILAPRIORIDADE_H_
#define FILAPRIORIDADE_H_
#include <stdio.h>
#include <stdlib.h>
#include "HuffmanArvore.h"

typedef struct filaPrioridade{
	HuffmanArvore* cabeca;
}filaPrioridade;


/*
 * Cria um novo no da arvore de huffman
 *
 * Recebe um Byte
 * Recebe a frequencia do Byte
 *
 * Retorna o novo no
 */
HuffmanArvore* criarNo(void* byte, size_t tipoDado,int frequencia);


/*
 * Aloca espaco para uma nova fila de prioridade
 *
 * Recebe nada
 * Retorna a cabeca da fila
 */
filaPrioridade* criarFila();


/*
 * Constroi a fila de prioridade a partir da frequencia dos bytes
 *
 * Recebe a fila de prioridade
 * Recebe um ponteiro com a frequencia dos bytes
 * Retorna nada
 */
void construirFila(filaPrioridade* fila, int* frequencia);


/*
 * Verifica se a fila esta vazia
 *
 * Recebe a fila de prioridade
 * Retorna 1 caso a fila esteja vazia, 0 caso o contrario
 */
int filaVazia(filaPrioridade* fila);


/*
 * Coloca um no da arvore na fila de prioridade
 *
 * Recebe a fila de prioridade
 * Recebe um no da arvore
 * Retorna nada
 */
void enfileirar(filaPrioridade* fila, HuffmanArvore* novoNo);


/*
 * Retira um no da fila de prioridade
 *
 * Recebe a fila de prioridade
 * Retorna o no desenfileirado
 */
HuffmanArvore* desenfileirar(filaPrioridade* fila);


/*
 * Constroi a arvore de huffman a partir da fila de prioridade
 *
 * Recebe a fila de prioridade
 * Retorna o ponteiro para a raiz da arvore
 */
HuffmanArvore* construirArvore(filaPrioridade* fila);

#endif /* FILAPRIORIDADE_H_ */
