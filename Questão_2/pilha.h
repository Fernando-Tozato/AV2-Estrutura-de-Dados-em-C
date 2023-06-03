#ifndef PILHA_H
#define PILHA_H

#include "node.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>
#include "clear.h"

// variável global com o tamanho da pilha
int tam;

// função que verifica se a pilha é vazia
int PilhaVazia (node *PILHA) {
	if (PILHA->prox == NULL) {
		return 1;
	} else {
		return 0;
	}
}

// função para empilhar
void Push (node *PILHA) {
	node *novo=(node *) malloc(sizeof(node));
	novo->prox = NULL;
	
	printf("\n\nNovo item: ");
	scanf("%d", &novo->item);
	
	if (PilhaVazia(PILHA)) {
		PILHA->prox = novo;
	} else {
		node *tmp = PILHA->prox;
		while(tmp->prox != NULL) {
			tmp = tmp->prox;
		}
		tmp->prox = novo;
	}
	tam++;
}

// função para desempilhar
void Pop (node *PILHA) {
	if (PilhaVazia(PILHA)) {
		printf("\nA pilha está vazia.\n");
		return;
	} else {
		node *ultimo = PILHA->prox;
		node *penultimo = PILHA;	
	
		while (ultimo->prox != NULL) {
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		free(ultimo);
		penultimo->prox = NULL;
		tam--;
	}
}

// função para imprimir a pilha
void ImprimePilha (node *PILHA) {
	if (PilhaVazia(PILHA)) {
		printf("\nA pilha está vazia.\n");
		return;
	}
	node *tmp;
	tmp = PILHA->prox;
	printf("\nPilha:");
	while (tmp != NULL) {
		printf("%3d", tmp->item);
		tmp = tmp->prox;
	}
	printf("\nQuantidade de itens na pilha: %d\n", tam);
}

// função para limpar pilha
void LimpaPilha (node *PILHA) {
	if (PilhaVazia(PILHA)) {
		printf("\nA pilha já está vazia\n");
		return;
	} else {
		for (int i=0; i<tam+1; i++) {
			node *ultimo = PILHA->prox;
			node *penultimo = PILHA;	
		
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

// função para imprimir topo da pilha
void ImprimeTopo (node *PILHA) {
	if (PilhaVazia(PILHA)) {
		printf("\nA pilha está vazia.\n");
		return;
	} else {
		node *ultimo = PILHA->prox;
		node *penultimo = PILHA;	
	
		while (ultimo->prox != NULL) {
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		printf("\nTopo: %3d", ultimo->item);
		printf("\nQuantidade de itens na pilha: %d\n", tam);
	}
}

// função principal da pilha
void Pilha () {
	setlocale(LC_ALL, "Portuguese");
	
	node *PILHA = (node *) malloc(sizeof(node));
	PILHA->prox = NULL;
	tam = 0;
	
	int e;
	char espera[2];
	
	clear();
	while(1) {
		printf("O que você deseja fazer?");
		printf("\n    1 - Inserir.");
		printf("\n    2 - Remover.");
		printf("\n    3 - Imprimir pilha.");
		printf("\n    4 - Imprimir topo da pilha.");
		printf("\n    5 - Limpar pilha.");
		printf("\n    0 - Retornar.");
		printf("\nEscolha: ");
		scanf("%d",&e);
		
		switch (e) {
			case 1:
				Push(PILHA);
				clear();
				printf("Item inserido com sucesso!\n\n\n");
				break;
			case 2:
				Pop(PILHA);
				clear();
				printf("Item removido com sucesso!\n\n\n");
				break;
			case 3:
				ImprimePilha(PILHA);
				printf("\n\nDigite qualquer coisa para continuar.\n");
				scanf("%s", espera);
				clear();
				break;
			case 4:
				ImprimeTopo(PILHA);
				printf("\n\nDigite qualquer coisa para continuar.\n");
				scanf("%s", espera);
				clear();
				break;
			case 5:
				clear();
				LimpaPilha(PILHA);
				printf("Pilha limpa com sucesso!\n\n\n");
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
