#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* 
    Neste programa, é possível criar uma fila de retângulos, com suas medidas armazenadas em uma estrutura.
    Ao informar os dados necessários, o programa imprime a lista, apresentando (para cada retângulo):
     - Suas medidas (em metros)
     - Sua área (em metros quadrados)
*/

typedef struct retangulo {
    float base;
    float altura;
    struct retangulo* prox;
} RET;

typedef struct fila {
    RET* inicio;
    RET* fim;
} FILA;

void filaLibera(FILA* filaRet) {
    RET* aux = filaRet->inicio;
    while(aux != NULL) {
        RET* temp = aux->prox;
        free(aux);
        aux = temp;
    }
    printf("Fim do programa.\n");
    free(filaRet);
}

float areaRetangulo(float base, float altura) {
    return base * altura;
}

void filaImprime(FILA* filaRet) {
    RET* aux;
    int i = 1;
    for (aux = filaRet->inicio; aux != NULL; aux = aux->prox){
        printf("\nRetangulo %d:\n", i);
        printf(" -Base = %.2fm\n", aux->base);    
        printf(" -Altura = %.2fm\n", aux->altura);
        printf(" -Area = %.2fm2\n", areaRetangulo(aux->base, aux->altura)); 
        i++;  
    }
    printf("\n");
}

void alocaRetangulo(FILA* filaRet, float base, float altura) {
    RET* ret = (RET*) malloc(sizeof(RET));
    ret->base = base;
    ret->altura = altura;
    ret->prox = NULL;

    if (filaRet->inicio != NULL) filaRet->fim->prox = ret;
    else filaRet->inicio = ret;
    filaRet->fim = ret;
}

FILA* filaCria() {
    FILA* aux = (FILA*) malloc(sizeof(FILA));
    aux->inicio = aux->fim = NULL;
    return aux;
}

int main (void) {
    int quantidade;
    float base, altura;
    printf("Digite a quantidade de retangulos para adicionar a fila: ");
    scanf("%d", &quantidade);
    
    FILA* filaRet = filaCria();
    for (int i = 0; i < quantidade; i++) {
        printf("Digite a base e a altura do %do retangulo:\n", i+1);
        scanf("%f %f", &base, &altura);
        alocaRetangulo(filaRet, base, altura);
    }
    filaImprime(filaRet);
    filaLibera(filaRet);
    return 0;
}