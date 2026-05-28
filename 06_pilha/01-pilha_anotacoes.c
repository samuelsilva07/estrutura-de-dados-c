#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int info;
    struct elemento* prox;
} ELEMENTO;

typedef struct pilha {
    ELEMENTO* topo;
} PILHA;

void liberaPilha(PILHA* pilha) {
    ELEMENTO* e = pilha->topo;
    while(e != NULL) {
        ELEMENTO* aux = e->prox;
        free(e);
        e = aux;
    }
    printf("Pilha liberada!\n");
}

void imprimePilha(PILHA* pilha) {
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    for (e = pilha->topo; e != NULL; e = e->prox)
        printf("%d ", e->info);
    printf("\n");
}

int pop(PILHA* pilha) {
    ELEMENTO* temp = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    int valor;
    temp = pilha->topo;         // variável temp recebe o elemento do topo
    valor = temp->info;         // valor recebe o dado de retorno

    pilha->topo = temp->prox;   // topo da pilha é reajustado 
    free(temp);
    return valor;
}

void push(PILHA* pilha, int n) {
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    e->info = n;
    e->prox = pilha->topo;  // adiciona o elemento antes do topo
    pilha->topo = e;        // novo elemento se torna o topo
}

PILHA* criaPilha() {
    PILHA* p = (PILHA*) malloc(sizeof(PILHA));
    p->topo = NULL; // topo da pilha inicia com NULL
    return p;
}

/* Pilha - LIFO (Last In, First Out)!!! */

int main () {
    PILHA* p = criaPilha();
    push(p, 2);
    push(p, 3);
    push(p, 4);
    imprimePilha(p);
    int valor;
    valor = pop(p);
    imprimePilha(p);
    liberaPilha(p);
    exit(EXIT_SUCCESS);
}