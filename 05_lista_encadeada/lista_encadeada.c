#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

// biblioteca com as funções para a manutenção de listas encadeadas simples

struct lista {
    int valor;
    struct lista* prox; 
};

void listaLibera(LISTA* lista) {
    LISTA* aux = lista;
    while(aux != NULL) {
        LISTA* p = aux->prox;
        free(aux);
        aux = p;
    }
}

LISTA* listaPesquisa(LISTA* lista, int num) {
    LISTA* p;
    for (p = lista; p != NULL; p = p->prox)
        if (p->valor == num) return p;
    return NULL;
}

LISTA* listaRemove(LISTA* lista, int num) {
    LISTA* ant = NULL;
    LISTA* p = lista;
    while(p != NULL && p->valor != num) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) return lista;

    if (ant == NULL) lista = p->prox;
    else ant->prox = p->prox;
    
    free(p);
    return lista;
}

void listaImprime(LISTA* lista) {
    LISTA* p;
    for (p = lista; p != NULL; p = p->prox)
        printf("%d ", p->valor);
    printf("\n");
}

LISTA* listaInsereOrdenado(LISTA* lista, int num) {
    LISTA* ant = NULL;
    LISTA* p = lista;
    while (p != NULL && p->valor < num) {
        ant = p;
        p = p->prox;
    }
    
    LISTA* novo = (LISTA*) malloc(sizeof(LISTA));
    novo->valor = num;

    if (ant == NULL) {
        novo->prox = lista;
        lista = novo;
    }
    else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return lista;
}

LISTA* listaInsere(LISTA* lista, int num) {
    LISTA* p = (LISTA*) malloc(sizeof(LISTA));
    p->valor = num;
    p->prox = lista;
    return p;
}

LISTA* listaCria() {
    return NULL;
}