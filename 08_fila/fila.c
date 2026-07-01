#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// biblioteca com as funções para a manutenção de filas 
// FIFO (First In, First Out)

typedef struct elemento {
    int info;
    struct elemento* prox;
} ELEMENTO;

typedef struct fila {
    ELEMENTO* inicio;
    ELEMENTO* fim;
} FILA;

void filaLibera(FILA* fila) {
    ELEMENTO* e = fila->inicio;
    while(e != NULL) {
        ELEMENTO* aux = e->prox;
        free(e);
        e = aux;
    }
    free(fila);
}

int filaVazia(FILA* fila){
    return fila->inicio == NULL;
}

void filaImprime(FILA* fila) {
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    printf("[");
    for (e = fila->inicio; e != NULL; e = e->prox)
        printf("%d ", e->info);
    if (filaVazia(fila) != 1) printf("\b");
    printf("]\n");
}

int filaRemove(FILA* fila) {
    ELEMENTO* temp = fila->inicio;
    int valor = temp->info;
    fila->inicio = temp->prox;
    if (fila->inicio == NULL) fila->fim = NULL;  // caso da fila vazia
    free(temp);
    return valor;
}

void filaInsere(FILA* fila, int n) {
    // fila = ORDEM INVERSA!!
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    e->info = n;
    e->prox = NULL;  // adiciona o elemento antes do inicio

    if (fila->inicio != NULL) {
        fila->fim->prox = e;
    }
    // se a fila estiver vazia, o elemento é o início e o fim da fila
    else fila->inicio = e;

    fila->fim = e;
}

FILA* filaCria() {
    FILA* f = (FILA*) malloc(sizeof(FILA));
    f->inicio = f->fim = NULL;   
    // inicio e fim da fila inicializados com NULL
    return f;
}