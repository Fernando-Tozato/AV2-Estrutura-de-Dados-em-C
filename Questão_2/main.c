#include <stdio.h>
#include <locale.h>
#include "pilha.h"
#include "fila.h"
#include "arvore.h"
#include "clear.h"

void main () {
	setlocale(LC_ALL, "Portuguese");
	int e;
	char espera[2];
	
	clear();
	printf("--------------------- Seja bem-vinda � quest�o 2! ---------------------");
	while(1) {
		printf("\nQual tipo de estrutura de dados voc� deseja usar?");
		printf("\n    1 - Pilha.");
		printf("\n    2 - Fila.");
		printf("\n    3 - �rvore.");
		printf("\n    0 - Sair.");
		printf("\nEscolha: ");
		scanf("%d",&e);
		
		switch (e) {
			case 1:
				Pilha();
				break;
			case 2:
				Fila();
				break;
			case 3:
				Arvore();
				break;
			case 0:
				printf("------------------------------- Adeus!! -------------------------------\n\n\n");
				return;
			default:
				clear();
				printf("\n\n\nEscolha inv�lida, tente novamente.");
				break;
		}
	}
}
