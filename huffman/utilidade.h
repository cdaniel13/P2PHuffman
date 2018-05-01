#ifndef UTILIDADE_H_
#define UTILIDADE_H_
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Byte;
#define tamMax 256

/*
 * Seta um bit no byte
 *
 * Recebe o byte a ser setado
 * Recebe a posicao a ser setada
 * Retorna o byte setado
 */
Byte setarBit(Byte byte, int posicao);


/*
 * Checa se o bit esta setado no byte
 *
 * Recebe o byte a ser checado
 * Recebe a posicao a ser checada
 * Retorna 1 caso esteja setado, 0 caso o contrario
 */
int checarSetado(Byte byte, int posicao);



#endif
