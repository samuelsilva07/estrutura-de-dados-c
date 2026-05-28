#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// biblioteca com as funções para a manutenção de filas

typedef struct Elemento {
    int info;
    struct elemento* prox;
} ELEMENTO;

typedef struct Fila {
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
    printf("Fila liberada!\n");
}

void filaImprime(FILA* fila) {
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    for (e = fila->inicio; e != NULL; e = e->prox)
        printf("%d ", e->info);
    printf("\n");
}

int filaRemove(FILA* fila) {
    ELEMENTO* temp = fila->inicio;
    int valor = temp->info;
    fila->inicio = temp->prox;
    if (fila->inicio == NULL) fila->fim = NULL;  
    free(temp);
    return valor;
}

void filaInsere(FILA* fila, int n) {
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    e->info = n;
    e->prox = NULL;  

    if (fila->inicio != NULL) {
        fila->fim->prox = e;
    }
    else fila->inicio = e;

    fila->fim = e;
}

FILA* filaCria() {
    FILA* f = (FILA*) malloc(sizeof(FILA));
    f->inicio = f->fim = NULL;   
    return f;
}