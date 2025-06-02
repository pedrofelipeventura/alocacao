#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 5

void preencherVetor(float *, int);
void imprimirVetor(float *, int);
void calcularMedia(float *, int, float *);
float *getEndMenor(float *, int);
float *getEndMaior(float *, int);
void imprimirValores(float **);

int qtd;

int main(){

float *v;

puts("Digite a quantidade de elementos do vetor: ");
scanf("%d", &qtd);

//Alocação Dinâmica
v = malloc(qtd * sizeof(float));

    float *pMenorMaior[2]; // Assunto : Vetor de Ponteiros

    srand(time(NULL));
    preencherVetor(v, qtd);
    imprimirVetor(v, qtd);

    pMenorMaior[0] = getEndMenor(v, qtd);
    pMenorMaior[1] = getEndMaior(v, qtd);

    puts("====");
    // printf("End. Menor: %p\n",pMenorMaior[0]);
    // printf("End. Menor: %p\n",*pMenorMaior);
    // printf("End. Menor: %p\n",pMenorMaior[1]);
    // printf("End. Maior: %p\n",*(pMenorMaior+1));

    imprimirValores(pMenorMaior);

    return 0;
}

void preencherVetor(float *pv, int t){
    for (int k=0; k<t; k++){
        *(pv + k) = (((float) rand())/RAND_MAX) * MX;
    }
}

void imprimirVetor(float *pv, int t){
    for (int k=0; k<t; k++){
        printf("[%p] %.2f\n",pv+k, *(pv + k));
    }
}

float *getEndMenor(float *pv, int t){ // Assunto : Funções que devolvem ponteiros
    float *menor = pv;
    for (int k=0; k<t; k++){
        menor = (*(pv+k) < *menor)?pv+k:menor;
    }
    return menor;
}

float *getEndMaior(float *pv, int t){ // Assunto : Funções que devolvem ponteiros
    float *maior = pv;
    for (int k=0; k<t; k++){
        maior = (*(pv+k) > *maior)?pv+k:maior;
    }
    return maior;
}

void imprimirValores(float **pval){
    printf("End. Menor: %p com o valor: %.2f\n",*pval,**pval);
    printf("End. Maior: %p com o valor: %.2f\n",*(pval+1),**(pval+1));
}
