#ifndef COMPRIMIRUTILIDADE_H_
#define COMPRIMIRUTILIDADE_H_
#include "utilidade.h"
#include "HuffmanArvore.h"

/*
 *Inicializa a tabela que guardara os novos bits que representarao cada caractere.
 *
 *Recebe uma matriz
 *Retorna nada
 */
void iniciarTabelaCaminhos(Byte tabelaCaminho[][tamMax]);

/*
 * Cria o cabecalho do arquivo compactado,
 * reseva os 2 primeiros bytes para o lixo e o tamanho da arvore.
 * Chama a funcao que ira escrever a arvore no arquivo compactado.
 *
 * Recebe o arquivo de saida
 * Recebe uma arvore
 * Recebe o tamanho da arvore
 * Retorna nada
 */
void criarCabecalho(FILE* arquivoSaida, HuffmanArvore* arvore, int *tamanhoArvore);

/*
 * Escreve os bits do lixo e do tamanho da arvore no arquivo
 * Escreve a tabela com os novos valores de cada caractere no arquivo
 *
 * Recebe o arquivo original
 * Recebe o arquivo final
 * Recebe uma matriz
 * Recebe um inteiro(tamanho da arvore)
 * Retorna nada
 */
void escreverArquivoCompactado(FILE* arquivoEntrada, FILE* arquivoSaida, Byte tabelaCaminhos[][256], int tamanhoArvore);

/*
 * Pega a frequencia de cada byte do arquivo de entrada
 *
 * Recebe um aquivo
 * Retorna um ponteiro inteiro com as frequencias dos bytes
 */

int* pegarFrequenciaBytes(FILE* arquivoEntrada);

#endif /* COMPRIMIRUTILIDADE_H_ */
