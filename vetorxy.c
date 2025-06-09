#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 100

void preencherVetor(int *, int);
void imprimirVetor(int *, int);
void armazenarPares(int *, int, int **, int *);

int qtd;

int main() {
    int *v, *y; 
    int qtdPares = 0;

    puts("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &qtd);

    // Alocação Dinâmica para o vetor v (x) e y
    v = malloc(qtd * sizeof(int));
    y = malloc(qtd * sizeof(int)); // máximo de elementos pares é o tamanho do vetor v

    srand(time(NULL));
    preencherVetor(v, qtd);
    imprimirVetor(v, qtd);

    // Armazenar os pares em y
    armazenarPares(v, qtd, &y, &qtdPares);

    // Imprimir os números pares
    puts("\nVetor de números pares:");
    for (int i = 0; i < qtdPares; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    // Liberação de memória
    free(v);
    free(y);

    return 0;
}

void preencherVetor(int *pv, int t) {
    for (int k = 0; k < t; k++) {
        *(pv + k) = rand() % MX;  // Gera números aleatórios inteiros entre 0 e 99
    }
}

void imprimirVetor(int *pv, int t) {
    for (int k = 0; k < t; k++) {
        printf("[%p] %d\n", pv + k, *(pv + k));
    }
}

void armazenarPares(int *pv, int t, int **py, int *qtdPares) {
    for (int i = 0; i < t; i++) {
        if (*(pv + i) % 2 == 0) {  // Verifica se o número é par
            (*py)[*qtdPares] = *(pv + i);
            (*qtdPares)++;
        }
    }
}
