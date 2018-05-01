#ifndef DESCOMPRIMIRUTILIDADE_H_
#define DESCOMPRIMIRUTILIDADE_H_
#include "HuffmanArvore.h"
#include "utilidade.h"

/*
 * Verifica se o arquivo passado tem a extensao correta(.huff)
 *
 * Recebe uma string com o nome do arquivo
 * Retorna um inteiro, 1 caso for validado, 0 caso contrario
 */
int validarArquivoHuffman(char *arquivo);

/*
 * Descompacta o arquivo .huff
 *
 * Recebe o arquivo de entrada
 * Recebe o arquivo de saida
 * Recebe a arvore reconstruida
 * Receve um inteiro com o tamanho do lixo
 * Retorna nada
 */
void descomprimirArquivo(FILE *arquivoComprimido, FILE *arquivoDescomprimido, HuffmanArvore* arvore, int tamanhoLixo);



#endif
