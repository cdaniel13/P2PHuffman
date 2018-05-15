#ifndef HUFFMANARVORE_H_
#define HUFFMANARVORE_H_
#include "utilidade.h"


typedef struct HuffmanArvore {
	void* byteArvore;
	//size_t tipoDado;
	int frequencia;
	struct HuffmanArvore* esquerda;
	struct HuffmanArvore* direita;
	struct HuffmanArvore* proximo;
} HuffmanArvore;


/*
 * Cria um arvore vazia
 *
 * Recebe nada
 * Retorna um ponteiro para NULL
 */
HuffmanArvore* criarArvoreVazia();


/*
 * Atribui os novos bits que ira representar um determinado caractere
 *
 * Recebe a matriz dos caracteres
 * Recebe um ponteiro com os novos bits
 * Recebe o caractere que sera refomulado
 * Recebe a quantidade de bits
 * Retorna nada
 */
void PreencherMatriz(Byte matriz[][tamMax], Byte *vetorAux, Byte byte, int posicao);


/*
 * Constroi a tabela dos novos bit dos caracteres a partir da arvore huffman
 *
 * Recebe uma matriz
 * Recebe um ponteiro auxiliar
 * Recebe uma arvore de huffman
 * Recebe um controlador inteiro
 * Retorna nada
 */
void criarTabelaCaminhos(Byte matriz[][tamMax], Byte *vetorAux, HuffmanArvore* arvore, int posicao);


/*
 * Escreve a arvore de huffman no arquivo de saida
 *
 * Recebe uma arvore
 * Recebe um ponteiro que ira armazenar o tamanho da arvore
 * Recebe o arquivo de saida
 * Retorna nada
 */
void escreverArvore(HuffmanArvore* arvore, int *tamanhoArvore, FILE* arquivoSaida);


/*
 * Reconstroi a arvore de huffman do arquivo compactado
 *
 * Recebe o arquivo com a arvore
 * Recebe um poiteiro para a arvore
 * Retorna a raiz da arvore
 */
HuffmanArvore* reconstruirArvore(FILE* arquivo, HuffmanArvore* arvore);


/*
 * Verifica se a arvore ta vazia
 *
 * Recebe uma arvore
 * Retorna 1 caso a arvore esteja vazia, 0 caso o contrario
 */
int arvoreVazia(HuffmanArvore* arvore);


/*
 * Verifica se um determinado no da arvore e uma folha
 *
 * Recebe um no da arvore
 * Retorna 1 caso for uma folha, 0 caso o contrario
 */
int eFolha(HuffmanArvore* arvore);

#endif
