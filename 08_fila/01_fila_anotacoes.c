#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int info;
    struct elemento* prox;
} ELEMENTO;

typedef struct fila {
    ELEMENTO* inicio;
    ELEMENTO* fim;
} FILA;

void liberaFila(FILA* fila) {
    ELEMENTO* e = fila->inicio;
    while(e != NULL) {
        ELEMENTO* aux = e->prox;
        free(e);
        e = aux;
    }
    free(fila);
    printf("Fila liberada!\n");
}

void imprimeFila(FILA* fila) {
    ELEMENTO* e = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    for (e = fila->inicio; e != NULL; e = e->prox)
        printf("%d ", e->info);
    printf("\n");
}

int removeElementoFila(FILA* fila) {
    ELEMENTO* temp = fila->inicio;
    int valor = temp->info;
    fila->inicio = temp->prox;
    if (fila->inicio == NULL) fila->fim = NULL;  // caso da fila vazia
    free(temp);
    return valor;
}

void insereElementoFila(FILA* fila, int n) {
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

FILA* criaFila() {
    FILA* f = (FILA*) malloc(sizeof(FILA));
    f->inicio = f->fim = NULL;   
    // inicio e fim da fila inicializados com NULL
    return f;
}

/* Fila - FIFO (First In, First Out)!!! */

int main () {
    FILA* f = criaFila();
    insereElementoFila(f, 2);
    insereElementoFila(f, 3);
    insereElementoFila(f, 4);
    imprimeFila(f);
    int valor = removeElementoFila(f);
    imprimeFila(f);
    liberaFila(f);
    exit(EXIT_SUCCESS);
}