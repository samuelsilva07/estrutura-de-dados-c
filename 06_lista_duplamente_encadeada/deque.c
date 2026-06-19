#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

typedef struct deque {
    int valor;
    struct deque* ant;  // ponteiro para o elemento anterior
    struct deque* prox; // ponteiro para o próximo elemento
} DEQUE;

void dequeLibera(DEQUE* lista) {  // Libera a memória utilizada para alocar a lista duplamente encadeada
    DEQUE* atual = lista;
    DEQUE* proximo = NULL;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);          // libera a memória do elemento
        atual = proximo;      // atual recebe o próximo elemento a ser liberado
    }
}

DEQUE* dequePesquisa(DEQUE* lista, int num) {   // Realiza uma busca linear na lista duplamente encadeada por um elemento de valor n e o retorna caso seja encontrado
    for (DEQUE* elemento = lista; elemento != NULL; elemento = elemento->prox)
        if (elemento->valor == num) return elemento;
    return NULL;
    
}

DEQUE* dequeFinal(DEQUE* lista) {
    DEQUE* e = lista;
    while(e->prox != NULL) e = e->prox;
    return e;
}

int dequeVazio(DEQUE* lista) {
    return lista == NULL;
}

DEQUE* dequeRemove(DEQUE* lista, int num) {   // Remove um elemento de valor n da lista duplamente encadeada
    DEQUE* removido = dequePesquisa(lista, num);
    
    if (removido == NULL) return lista;

    // se removido é o primeiro elemento, lista aponta para o próximo
    if (removido == lista) lista = removido->prox;

    // se o elemento estiver no meio, o campo prox do elemento anterior aponta para removido->prox
    else removido->ant->prox = removido->prox;

    // se NÃO for o último elemento, o campo ant do próximo elemento aponta para removido->ant
    if (removido->prox != NULL) removido->prox->ant = removido->ant; 

    free(removido);
    return lista;
}

void dequeImprimirReverso(DEQUE* lista) { // Imprime a lista duplamente encadeada na ordem reversa
    printf("[");
    for (DEQUE* e = dequeFinal(lista); e != NULL; e = e->ant)
        printf("%d, ", e->valor);
    printf("\b\b]\n");
}

void dequeImprimir(DEQUE* lista) {   // Imprime a lista duplamente encadeada
    printf("[");
    for (DEQUE* e = lista; e != NULL; e = e->prox)
        printf("%d, ", e->valor);
    printf("\b\b]\n");
}

DEQUE* dequeInsereOrdenado(DEQUE* lista, int num) {     // Insere um elemento na lista encadeada, mas de forma ordenada
    DEQUE* atual = lista;
    DEQUE* anterior = NULL;

    while (atual != NULL && atual->valor < num) {
        anterior = atual;
        atual = atual->prox;
    }

    DEQUE* novo = (DEQUE*) malloc(sizeof(DEQUE));
    novo->valor = num;
    
    // se o novo elemento não está no final da lista, é preciso conectar apenas o elemento atual - pois ele não é NULL
    if (atual != NULL) atual->ant = novo;  // conecta apenas o elemento atual

    // caso o novo elemento não esteja no início da lista, então é preciso conectar apenas o elemento anterior - pela mesma razão
    if (anterior != NULL) anterior->prox = novo;
            
    novo->prox = atual;     // elemento ou NULL (se estiver no final da lista)
    novo->ant = anterior;   // elemento ou NULL (se estiver no começo da lista)

    // caso o novo elemento seja o início da lista, o ponteiro da lista vai para ele
    if (novo->ant == NULL) lista = novo;    

    return lista;   
}

DEQUE* dequeInsere(DEQUE* lista, int num) { // Insere um elemento na lista duplamente encadeada
    DEQUE* novo = (DEQUE*) malloc(sizeof(DEQUE));
    novo->valor = num;
    novo->prox = lista; // se a lista for vazia, aponta para NULL
    novo->ant = NULL;

    // criação do "caminho de volta" (se a lista não for vazia)
    if (lista != NULL) lista->ant = novo;
    return novo;
}

DEQUE* dequeCria () {   // Cria uma lista duplamente encadeada vazia
    return NULL;
}