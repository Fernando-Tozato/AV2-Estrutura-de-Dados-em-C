// includes
#include <stdio.h>
#include <locale.h>

// função que ordena usando bubblesort
int* bubblesort (int *vet, int n) {
	int aux;
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<n-1;j++) {
			if (vet[j] > vet[j+1]) {
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
		}
	}
	return vet;
}

// função que ordena usando isertionsort
int* insertionsort (int *vet, int n) {
	for (int j=2; j<n; j++) {
		int chave = vet[j];
		int i = j-1;
		while (i > 0 && vet[i] > chave) {
			vet[i+1] = vet[i];
			i--;
		}
		vet[i+1] = chave;
	}
	return vet;
}

// função principal do programa
void main() {
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n\n--------------------- Seja bem-vinda à questão 2! ---------------------");
	while (1) {
		int n;
		printf("\nPrimeiro, escolha o tamanho do vetor (0 para sair): ");
		scanf("%d",&n);
		if (n > 0) {
			int vet[n], *vet2;
			printf("\n\nAgora, preencha o vetor:\n\n");
			for (int i=0; i<n; i++) {
				printf("Espaço %d: ",i+1);
				scanf("%d",&vet[i]);
			}
			while (1) {
				int e;
				printf("\n\nEscolha o tipo de ordenação:");
				printf("\n    1 - Bubble Sort.");
				printf("\n    2 - Insertion Sort.");
				printf("\n    0 - Sair.");
				printf("\nEscolha: ");
				scanf("%d",&e);
				
				switch (e) {
					case 1:
						printf("\n\nBubble Sort:\n");
						vet2 = bubblesort(vet,n);
						break;
					case 2:
						printf("\n\nInsertion Sort:\n");
						vet2 = insertionsort(vet,n);
						break;
					case 0:
						printf("------------------------------- Adeus!! -------------------------------\n\n\n");
						return;
					default: 
						printf("\n\n\n\nInsira um valor válido.");
						break;
				}
				
				for (int i=0; i<n; i++) {
					printf("%d - ",vet[i]);
				}	
			}
		} else if (n == 0) {
			printf("------------------------------- Adeus!! -------------------------------\n\n\n");
			return;
		} else {
			printf("\n\n\n\nInsira um valor válido.");
		}
	}
}
