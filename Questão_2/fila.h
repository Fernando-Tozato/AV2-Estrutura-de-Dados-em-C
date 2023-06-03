#ifndef FILA_H
#define FILA_H

#include "node.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>
#include <limits.h>
#include "clear.h"

int tam;

int FilaVazia (node*FILA) {
	if (FILA->prox == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void Enqueue (node*FILA) {
	node*novo = (node*) malloc(sizeof(node));
	novo->prox = NULL;
	
	printf("\n\nNovo item: ");
	scanf("%d", &novo->item);
	
	if (FilaVazia(FILA)) {
		FILA->prox=novo;
	} else {
		node*tmp = FILA->prox;
		while (tmp->prox != NULL) {
			tmp = tmp->prox;
		}
		tmp->prox = novo;
	}
	tam++;
}

void Dequeue (node*FILA) {
	if (FilaVazia(FILA)) {
		printf("\nA fila está vazia.\n");
		return;
	} else {
		node*tmp = FILA->prox;
		FILA->prox = tmp->prox;
		tam--;
		free(tmp);
	}
}

void ImprimeFila (node*FILA) {
	if (FilaVazia(FILA)) {
		printf("\nA fila está vazia.\n");
		return;
	}
	node*tmp;
	tmp = FILA->prox;
	printf("\nFila:");
	while (tmp != NULL) {
		printf("%3d", tmp->item);
		tmp = tmp->prox;
	}
	printf("\nQuantidade de itens na fila: %d\n", tam);
}

void LimpaFila (node*FILA) {
	if (FilaVazia(FILA)) {
		printf("\nA fila já está vazia\n");
		return;
	} else {
		for (int i=0; i<tam+1; i++) {
			node*ultimo = FILA->prox;
			node*penultimo = FILA;	
		
			while (ultimo->prox != NULL) {
				penultimo = ultimo;
				ultimo = ultimo->prox;
			}
			free(ultimo);
			penultimo->prox = NULL;
			tam--;
		}
	}
}

void Maior (node *FILA) {
	if (FilaVazia(FILA)) {
		printf("\nA fila está vazia.\n");
		return;
	}
	node *tmp;
	int maior = INT_MIN;
	tmp = FILA->prox;
	while (tmp != NULL) {
		if (tmp->item > maior) {
			maior = tmp->item;
		}
		tmp = tmp->prox;
	}
	printf("\nMaior: %d\n", maior);
	printf("\nQuantidade de itens na fila: %d\n", tam);
}

void Menor (node *FILA) {
	if (FilaVazia(FILA)) {
		printf("\nA fila está vazia.\n");
		return;
	}
	node*tmp;
	int menor = INT_MAX;
	tmp = FILA->prox;
	while (tmp != NULL) {
		if (tmp->item < menor) {
			menor = tmp->item;
		}
		tmp = tmp->prox;
	}
	printf("\nMenor: %d\n", menor);
	printf("\nQuantidade de itens na fila: %d\n", tam);
}

void Fila () {
	setlocale(LC_ALL, "Portuguese");
	
	node *FILA = (node *) malloc(sizeof(node));
	FILA->prox = NULL;
	tam = 0;
	
	int e;
	char espera[2];
	
	clear();
	while(1) {
		printf("O que você deseja fazer?");
		printf("\n    1 - Inserir.");
		printf("\n    2 - Remover.");
		printf("\n    3 - Imprimir fila.");
		printf("\n    4 - Imprimir maior elemento da fila.");
		printf("\n    5 - Imprimir menor elemento da fila.");
		printf("\n    6 - Limpar fila.");
		printf("\n    0 - Retornar.");
		printf("\nEscolha: ");
		scanf("%d",&e);
		
		switch (e) {
			case 1:
				Enqueue(FILA);
				clear();
				printf("Item inserido com sucesso!\n\n\n");
				break;
			case 2:
				Dequeue(FILA);
				clear();
				printf("Item removido com sucesso!\n\n\n");
				break;
			case 3:
				ImprimeFila(FILA);
				printf("\n\nDigite qualquer coisa para continuar.\n");
				scanf("%s", espera);
				clear();
				break;
			case 4:
				Maior(FILA);
				printf("\n\nDigite qualquer coisa para continuar.\n");
				scanf("%s", espera);
				clear();
				break;
			case 5:
				Menor(FILA);
				printf("\n\nDigite qualquer coisa para continuar.\n");
				scanf("%s", espera);
				clear();
				break;
			case 6:
				clear();
				LimpaFila(FILA);
				printf("Fila limpa com sucesso!\n\n\n");
				break;
			case 0:
				clear();
				return;
			default:
				clear();
				printf("Escolha inválida, tente novamente.\n\n\n");
				break;
		}
	}
}

#endif
