#include <stdio.h>
#include <locale.h>
#include "comprimir.h"
#include "descomprimir.h"

void menu(){
	setlocale(LC_ALL, "Portuguese");
	int escolha;
		system("cls");;
		puts("Digite:\n1 para comprimir\n2 para descomprimir\n0 para sair\n");
		scanf("%d", &escolha);

		switch(escolha){
			case 1:
				getchar();
				comprimir();
				menu();
				break;
			case 2:
				getchar();
				descomprimir();
				menu();
				break;
			case 0:
				break;
			default:
				system("cls");;
				puts("Opção invalida, por favor digite uma opção valida\n");
				menu();
		}

}
