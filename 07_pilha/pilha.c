#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// biblioteca com as funções para a manutenção de pilhas 
// LIFO (Last In, First Out)

typedef struct elemento {
    int info;
    struct elemento* prox;
} ELEMENTO;

typedef struct pilha {
    ELEMENTO* topo;
} PILHA;

void pilhaLibera(PILHA* pilha) {
    ELEMENTO* e = pilha->topo;
    while(e != NULL) {
        ELEMENTO* aux = e->prox;
        free(e);
        e = aux;
    }
}

int pilhaVazia(PILHA* p) {
    return p->topo == NULL;
}

ELEMENTO* pilhaTopo(PILHA* p) {     // Retorna o elemento que está no topo da pilha
    if (pilhaVazia(p)) return NULL;
    return p->topo;
}

void pilhaImprime(PILHA* pilha) {   // Imprime a pilha na sequência correta
    printf("[");
    if (pilhaVazia(pilha)) {  // se a pilha estiver vazia, não imprime os elementos 
        printf("]\n");
        return;
    }

    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO)); // criação de um elemento temporário para a impressão
    for (e = pilha->topo; e != NULL; e = e->prox)
        printf("%d ", e->info);
        
    printf("\b]\n");
    free(e);
}

int pilhaPop(PILHA* pilha) {    // Retira o elemento do topo da pilha
    ELEMENTO* elemento_removido = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    int valor;
    elemento_removido = pilhaTopo(pilha);    // variável elemento_removido recebe o elemento do topo da pilha
    valor = elemento_removido->info;         // valor recebe o dado de retorno

    pilha->topo = elemento_removido->prox;   // topo da pilha é reajustado 
    free(elemento_removido);
    return valor;       // função retorna o valor do elemento removido
}

void pilhaPush(PILHA* pilha, int n) {   // Adiciona um elemento ao topo da pilha
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    e->info = n;
    e->prox = pilha->topo;  // adiciona o elemento antes do topo
    pilha->topo = e;        // novo elemento se torna o topo
}

PILHA* pilhaCria() {    // Cria uma pilha vazia
    PILHA* p = (PILHA*) malloc(sizeof(PILHA));
    p->topo = NULL;     // topo da pilha inicia com NULL
    return p;
}