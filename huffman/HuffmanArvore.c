#include <stdio.h>
#include <stdlib.h>
#include "utilidade.h"
#include "HuffmanArvore.h"
#include "filaPrioridade.h"


int eFolha(HuffmanArvore* arvore){
	return ((arvore->esquerda == NULL) && (arvore->direita == NULL));
}

HuffmanArvore* criarArvoreVazia(){
	return NULL;
}


void PreencherMatriz(Byte matriz[][tamMax], Byte *vetorAux, Byte byte, int posicao){
    int i;
    for(i = 0; i < posicao; i++){
        matriz[byte][i] = vetorAux[i];
    }
    matriz[byte][i] = '\0';
}

void criarTabelaCaminhos(Byte matriz[][tamMax], Byte *vetorAux, HuffmanArvore* arvore, int posicao){

    if(arvore->esquerda == NULL && arvore->direita == NULL){

    	PreencherMatriz(matriz, vetorAux, *(Byte*)(arvore->byteArvore), posicao);
        return;
    }

    if(arvore->esquerda != NULL){
        vetorAux[posicao] = '0';
        criarTabelaCaminhos(matriz, vetorAux, arvore->esquerda,  posicao + 1);
    }

    if (arvore->direita != NULL){
        vetorAux[posicao] = '1';
        criarTabelaCaminhos(matriz, vetorAux, arvore->direita, posicao + 1);
    }
}

void escreverArvore(HuffmanArvore* arvore, int *tamanhoArvore, FILE* arquivoSaida){

    if (eFolha(arvore)) {

        if (*(Byte*)(arvore->byteArvore) == '\\' || *(Byte*)(arvore->byteArvore) == '*') {

            Byte byte = '\\';
            (*tamanhoArvore)++;
            fprintf(arquivoSaida, "%c", byte);

        }

        (*tamanhoArvore)++;
        fprintf(arquivoSaida, "%c", *(Byte*)(arvore->byteArvore));


        return;
    }

    (*tamanhoArvore)++;
    fprintf(arquivoSaida, "%c", *(Byte*)(arvore->byteArvore));


    if(arvore->esquerda != NULL){
    	escreverArvore(arvore->esquerda, tamanhoArvore, arquivoSaida);
    }

    if(arvore->direita != NULL){
    	escreverArvore(arvore->direita, tamanhoArvore, arquivoSaida);
    }
}


HuffmanArvore* reconstruirArvore(FILE* arquivo, HuffmanArvore* arvore){

    Byte byte;

    fscanf(arquivo, "%c", &byte);


    if(byte == '\*'){

        arvore = criarNo(&byte, sizeof(Byte),0);

        arvore->esquerda = reconstruirArvore(arquivo, arvore->esquerda);
        arvore->direita = reconstruirArvore(arquivo, arvore->direita);
    }
    else{

        if(byte == '\\'){

            fscanf(arquivo, "%c", &byte);

            arvore = criarNo(&byte, sizeof(Byte), 0);
        }
        else{

            arvore = criarNo(&byte, sizeof(Byte), 0);
        }
    }

    return arvore;
}

int arvoreVazia(HuffmanArvore* arvore){
    return (arvore == NULL);
}
