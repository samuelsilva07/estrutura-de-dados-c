#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

typedef struct lista {
    int valor;
    struct lista* ant;  // ponteiro para o elemento anterior
    struct lista* prox; // ponteiro para o próximo elemento
} LISTA;

void liberaLista2(LISTA* vet) {
    LISTA* aux = vet;
    while (aux != NULL) {
        LISTA* temp = aux->prox;
        aux->prox = NULL;
        free(aux);
        aux = temp;
        aux->ant = NULL;
    }
}

LISTA* removeLista2(LISTA* vet, int n) {
    LISTA* p = busca(vet, n);

    if (p = NULL) return vet;

    // se p é o primeiro elemento, vet aponta para o próximo
    if (vet = p) vet = p->prox;

    // se o elemento estiver no meio, o campo prox do elemento anterior aponta para p->prox
    else p->ant->prox = p->prox;

    // se NÃO for o último elemento, o campo ant do próximo elemento aponta para p->ant
    if (p->prox != NULL) p->prox->ant = p->ant; 

    free(p);
    return vet;
}

LISTA* insereLista2(LISTA* lista, int n) {
    LISTA* novo = (LISTA*) malloc(sizeof(LISTA));
    novo->valor = n;
    novo->prox = lista; // se a lista for vazia, aponta para NULL
    novo->ant = NULL;

    // criação do "caminho de volta" (se a lista não for vazia)
    if (lista != NULL) lista->ant = novo;
    return novo;
}

int main (void) {
    LISTA* vetor = criaLista();
    int num;
    for (int i = 0; i < 5; i++) {
        printf("Digite um numero para insereLista2r a lista: ");
        scanf("%d", &num);
        vetor = insereLista2(vetor, num);
    }
    imprimeLista(vetor);
    removeLista2(vetor, 2);
    liberaLista2(vetor);
    exit(EXIT_SUCCESS);
}