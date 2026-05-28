#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct array {
    int tamanho;    // tamanho total do array
    int qtd;        // quantidade de elementos armazenados no array
    int* vetor;     // vetor de elementos do array
};

void arrayLibera(ARRAY* lista) {
    free(lista->vetor);
    free(lista);
    printf("Memoria liberada!\n");
}

int arrayPesquisa(ARRAY* lista, int elemento) { // retorna o índice do elemento procurado
    for (int i = 0; i < lista->qtd; i++) 
        if (lista->vetor[i] == elemento) return i;
    return -1;
}

void arrayImprime(ARRAY* lista) {
    printf("[");
    for (int i = 0; i < lista->qtd; i++) {
        printf("%d, ", lista->vetor[i]);
    } 
    printf("\b\b]\n");  // remove a vírgula do último elemento e fecha os colchetes
}

int arrayRemove(ARRAY* lista, int posicao) { // remove o elemento do vetor e retorna o seu valor
    if (lista->tamanho < 1) {
        printf("O array já está vazio!");
        return (int) NULL;
    }
    int removido = lista->vetor[posicao]; // pega o elemento removido

    // reposiciona todos os elementos após o removido, para que a última posição esteja com valores duplicados
    for (int i = posicao; i < lista->qtd - 1; i++) {    
        lista->vetor[posicao] = lista->vetor[posicao + 1];
    }

    lista->vetor[-1] = (int) NULL;    // remove o elemento duplicado
    lista->qtd--;               // diminui a quantidade de elementos no vetor
    return removido;            // retorna o elemento removido
}

void arrayAdiciona(ARRAY* lista, int valor) {  // adiciona um elemento no final do vetor
    if (lista->qtd == lista->tamanho) {  // verifica se o array está cheio
        lista->tamanho *= 2;    // tamanho do vetor é dobrado
        lista->vetor = (int*) realloc(lista->vetor, lista->tamanho * sizeof(int));  // realloc para redimensionar o vetor
    }
    int posicao = lista->qtd;
    lista->vetor[posicao] = valor;  // elemento é adicionado na posição correta
    lista->qtd++;
}

ARRAY* arrayCria() {  // retorna um ponteiro para o array inicial
    ARRAY* lista = (ARRAY*) malloc(sizeof(ARRAY));
    if (lista == NULL) {
       printf("Nao foi possivel alocar memoria para o array.\n");
       return NULL; 
    }

    lista->tamanho = 1; // vetor inicia com tamanho 1 - já que é inicializado com o tamanho de int
    lista->qtd = 0;
    lista->vetor = (int*) malloc(sizeof(int));

    if (lista->vetor == NULL) {
        printf("Nao foi possivel alocar memoria para o vetor.\n");
        return NULL; 
    }

    printf("Memoria alocada com sucesso!\n");
    return lista;
}