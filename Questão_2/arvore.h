// includes
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include "clear.h"

// structs
typedef struct no {
	int chave;
	struct no *esquerda, *direita;
} No;

typedef struct {
	No *raiz;
	int tam;
} ArvB;

// função para inserir nós
No* Insere (No *raiz, int valor) {
	if (raiz == NULL) {
		No *novo = (No*)malloc(sizeof(No));
		novo->chave = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		return novo;
	} else {
		if (valor < raiz->chave) 
			raiz->esquerda = Insere(raiz->esquerda, valor);
			
		if (valor > raiz->chave) 
			raiz->direita = Insere(raiz->direita, valor);
		
		return raiz;
	}
}

// função para imprimir da esquerda para a direita
void Imprimir (No *raiz) {
	if (raiz != NULL) {
		Imprimir(raiz->esquerda);
		printf("%d ", raiz->chave);
		Imprimir(raiz->direita);
	}
}

// função para remover itens
No* Remove (No *raiz, int item) {
	if (raiz == NULL) {
		printf("\nValor não encontrado!\n");
		return NULL;
	} else {
		if (raiz->chave == item) {
			if (raiz->esquerda == NULL && raiz->direita == NULL) {
				free(raiz);
				return NULL;
			} else {
				if (raiz->esquerda == NULL || raiz->direita == NULL) {
					No *aux;
					if (raiz->esquerda != NULL) 
						aux = raiz->esquerda;
					else
						aux = raiz->direita;
					free(raiz);
					return aux;
				} else {
					No *aux = raiz->esquerda;
					while (aux->direita != NULL)
						aux = aux->direita;
					raiz->chave = aux->chave;
					aux->chave = item;
					raiz->esquerda = Remove(raiz->esquerda, item);
					return raiz;
				}
			}
		} else {
			if (item < raiz->chave)
				raiz->esquerda = Remove(raiz->esquerda, item);
			else
				raiz->direita = Remove(raiz->direita, item);
			return raiz;
		}
	}
}

// função para buscar itens
No* Busca (No *raiz, int item) {
	if (raiz == NULL) {
		printf("\nValor não encontrado!\n");
		return NULL;
	} else {
		if (raiz->chave == item) {
			printf("\n\nO item está na árvore.\n");
			return NULL;
		} else {
			if (item < raiz->chave)
				raiz->esquerda = Busca(raiz->esquerda, item);
			else
				raiz->direita = Busca(raiz->direita, item);
			return raiz;
		}
	}
}

// função para imprimir da direita para a esquerda
void ImprimirInverso (No *raiz) {
	if (raiz != NULL) {
		ImprimirInverso(raiz->direita);
		printf("%d ", raiz->chave);
		ImprimirInverso(raiz->esquerda);
	}
}

// função para buscar maior item
int MaiorChave (No *raiz) {
	if (raiz == NULL) {
		printf("\nA árvore está vazia!\n");
		return 0;
	} 
	No *tmp;
	int maior = INT_MIN;
	tmp = raiz->direita;
	while (tmp != NULL) {
		if (tmp->chave > maior) {
			maior = tmp->chave;
		}
		tmp = tmp->direita;
	}
	return maior;
}

// função principal da árvore
void Arvore () {
	setlocale(LC_ALL, "Portuguese");
	
	ArvB arv;
	arv.raiz = NULL;
	No *raiz = NULL;
	
	int e, item, maior;
	char espera[2];
	
	clear();
	while(1) {
		printf("O que você deseja fazer?");
		printf("\n    1 - Inserir item.");
		printf("\n    2 - Remover item.");
		printf("\n    3 - Imprimir (esquerda-direita).");
		printf("\n    4 - Imprimir (direita-esquerda).");
		printf("\n    5 - Buscar item.");
		printf("\n    6 - Imprimir maior item.");
		printf("\n    0 - Retornar.");
		printf("\nEscolha: ");
		scanf("%d",&e);
		
		switch (e) {
			case 1:
				printf("\n\nDigite o item que você deseja inserir: ");
				scanf("%d",&item);
				raiz = Insere(raiz, item);
				clear();
				printf("Item inserido com sucesso!\n\n\n");
				break;
			case 2:
				printf("\n\nDigite o item que você deseja remover: ");
				scanf("%d",&item);
				raiz = Remove(raiz, item);
				clear();
				printf("Item removido com sucesso!\n\n\n");
				break;
			case 3:
				Imprimir(raiz);
				printf("\n\nDigite qualquer coisa para continuar.\n");
				scanf("%s", espera);
				clear();
				break;
			case 4:
				ImprimirInverso(raiz);
				printf("\n\nDigite qualquer coisa para continuar.\n");
				scanf("%s", espera);
				clear();
				break;
			case 5:
				printf("\n\nDigite o item que você deseja buscar: ");
				scanf("%d",&item);
				raiz = Busca(raiz, item);
				raiz = Insere(raiz, item);
				printf("\n\nDigite qualquer coisa para continuar.\n");
				scanf("%s", espera);
				clear();
				break;
			case 6:
				maior = MaiorChave(raiz);
				if (maior)
					printf("Maior: %d", MaiorChave(raiz));
				printf("\n\nDigite qualquer coisa para continuar.\n");
				scanf("%s", espera);
				clear();
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
