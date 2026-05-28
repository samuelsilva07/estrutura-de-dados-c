#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

LISTA* adiciona(LISTA* lista, int n) {
    LISTA* novo = (LISTA*) malloc(sizeof(LISTA));
    novo->valor = n;
    novo->prox = lista;
    return novo;
}

LISTA* listaCiclo(LISTA* lista) {
    LISTA* p = lista; 
    // passa os elementos até que o próximo seja vazio
    while (p->prox != NULL) p = p->prox;
    p->prox = lista; // campo prox do ultimo elemento aponta para o início da lista
    return lista;
}

void imprimeListaCircular(LISTA* lista) {
    LISTA* p = lista;
    if (p) do { // do-while tsta APÓS O LOOP!! 
        printf("%d ", p->valor);
        p = p->prox;
    } while (p != lista); // loop termina quando retornar ao elemento inicial
}

int main (void) {
    LISTA* vetor = criaLista();
    int num;
    for (int i = 0; i < 3; i++) {
        printf("Digite um numero para adicionar a lista: ");
        scanf("%d", &num);
        vetor = insercaoLista(vetor, num);
    }
    vetor = listaCiclo(vetor);
    imprimeListaCircular(vetor);
    exit(EXIT_SUCCESS);
}