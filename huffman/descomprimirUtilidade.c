#include <stdio.h>
#include "HuffmanArvore.h"
#include "descomprimirUtilidade.h"
#include <string.h>

int validarArquivoHuffman(char *nomeArquivo){

    char comparador[] = ".huff";
    int i;
    int j = 0;

    for(i = strlen(nomeArquivo) - 5; i < strlen(nomeArquivo); i++){

        if(nomeArquivo[i] != comparador[j]){

            return 0;
        }
        j++;
    }

    return 1;
}


void descomprimirArquivo(FILE *arquivoComprimido, FILE *arquivoDescomprimido, HuffmanArvore* arvore, int tamanhoLixo){

   HuffmanArvore* arvoreAuxiliar;
   Byte byte, byteAuxiliar;
   short int i;

   arvoreAuxiliar = arvore;

   fscanf(arquivoComprimido, "%c", &byte);
   byteAuxiliar = byte;

   while((fscanf(arquivoComprimido, "%c", &byte)) != EOF){

       for(i = 7; i >= 0; i--){

           if(eFolha(arvoreAuxiliar)){


               fprintf(arquivoDescomprimido, "%c", *(Byte*)(arvoreAuxiliar->byteArvore));
               arvoreAuxiliar = arvore;
           }

           if(!checarSetado(byteAuxiliar, i)){

               arvoreAuxiliar = arvoreAuxiliar->esquerda;
           }
           else{

        	   arvoreAuxiliar = arvoreAuxiliar->direita;
           }
       }
       byteAuxiliar = byte;
   }

   for(i = 7; i >= tamanhoLixo - 1; i--){

       if(eFolha(arvoreAuxiliar)){

    	   fprintf(arquivoDescomprimido, "%c", *(Byte*)(arvoreAuxiliar->byteArvore));

           arvoreAuxiliar = arvore;
       }

       if(!checarSetado(byteAuxiliar, i)){

           arvoreAuxiliar = arvoreAuxiliar->esquerda;
       }
       else{

    	   arvoreAuxiliar = arvoreAuxiliar->direita;
       }
   }
}
