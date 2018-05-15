#include <stdio.h>
#include "utilidade.h"
#include "HuffmanArvore.h"


void iniciarTabelaCaminhos(Byte tabelaCaminho[][tamMax]){
    int i;
    for(i = 0; i < 256; i++){
        tabelaCaminho[i][0] = '\0';
    }
}



void criarCabecalho(FILE* arquivoSaida, HuffmanArvore* arvore, int *tamanhoArvore){

    Byte byte = 0;


    fprintf(arquivoSaida, "%c%C", byte, byte);

    escreverArvore(arvore, tamanhoArvore, arquivoSaida);

}

void escreverArquivoCompactado(FILE* arquivoEntrada, FILE* arquivoSaida, Byte tabelaCaminhos[][256], int tamanhoArvore){

    Byte byte = 0, byteAuxiliar;

    short int bitIndex = 0;
    int stringIndex;

    fseek(arquivoEntrada, 0, SEEK_SET);
    while((fscanf(arquivoEntrada, "%c", &byteAuxiliar)) != EOF ){

        stringIndex = 0;
        while(tabelaCaminhos[byteAuxiliar][stringIndex] != '\0'){

            if (bitIndex == 8){

            	fprintf(arquivoSaida, "%c", byte);

                byte = 0;
                bitIndex = 0;
            }

            if(tabelaCaminhos[byteAuxiliar][stringIndex] == '1'){

                byte = setarBit(byte, bitIndex);
            }
            stringIndex++;
            bitIndex++;
        }
    }

    fprintf(arquivoSaida, "%c", byte);


    Byte tamanhoLixo = ((8 - bitIndex) << 5);
    Byte tamanhoStringArvore = tamanhoArvore;

    fseek(arquivoSaida, 0, SEEK_SET);

    fprintf(arquivoSaida, "%c%c", tamanhoLixo, tamanhoStringArvore);


}

int* pegarFrequenciaBytes(FILE* arquivoEntrada){
    int* frequencia = (int*) calloc(tamMax, sizeof(int));
    Byte ByteAtual;
    while((fscanf(arquivoEntrada, "%c", &ByteAtual)) != EOF)
        frequencia[ByteAtual]++;
    return frequencia;
}
