#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// biblioteca com as funções para a manutenção de pilhas

typedef struct elemento {
    int info;
    struct elemento* prox;
};

typedef struct pilha {
    ELEMENTO* topo;
};

void pilhaLibera(PILHA* pilha) {
    ELEMENTO* e = pilha->topo;
    while(e != NULL) {
        ELEMENTO* aux = e->prox;
        free(e);
        e = aux;
    }
}

void pilhaImprime(PILHA* pilha) {
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    for (e = pilha->topo; e != NULL; e = e->prox)
        printf("%d ", e->info);
    printf("\n");
}

int pop(PILHA* pilha) {
    ELEMENTO* temp = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    int valor;
    temp = pilha->topo;         
    valor = temp->info;         

    pilha->topo = temp->prox;   
    free(temp);
    return valor;
}

void push(PILHA* pilha, int n) {
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    e->info = n;
    e->prox = pilha->topo;  
    pilha->topo = e;       
}

PILHA* pilhaCria() {
    PILHA* p = (PILHA*) malloc(sizeof(PILHA));
    p->topo = NULL; 
    return p;
}
