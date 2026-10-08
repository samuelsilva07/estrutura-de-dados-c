#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct _array {
    int total_size;    // tamanho total do array
    int size;        // quantidade de elementos armazenados no array
    int* vector;     // vetor de elementos do array
};

void freeArray(Array* array) {
    free(array->vector);
    free(array);
}

int get(Array* array, int value) { // retorna o índice do elemento procurado
    for (int i = 0; i < array->size; i++) 
        if (array->vector[i] == value) return i;
    return -1;
}

void showArray(Array* array) {
    printf("[");
    for (int i = 0; i < array->size; i++) {
        printf("%d, ", array->vector[i]);
    } 
    printf("\b\b]\n");  // remove a vírgula do último elemento e fecha os colchetes
}

int del(Array* array, int index) { // remove o elemento do vetor e retorna o seu valor
    if (array->total_size < 1) {
        printf("O array já está vazio!");
        return -1;
    }
    int deleted = array->vector[index]; // pega o elemento removido

    // reposiciona todos os elementos após o removido, para que a última posição esteja com valores duplicados
    for (int i = index; i < array->size - 1; i++) {    
        array->vector[index] = array->vector[index + 1];
    }

    array->vector[-1] = (int) NULL;    // remove o elemento duplicado
    array->size--;               // diminui a quantidade de elementos no vetor
    return deleted;            // retorna o elemento removido
}

void append(Array* array, int value) {  // adiciona um elemento no final do vetor
    if (array->size == array->total_size) {  // verifica se o array está cheio
        array->total_size *= 2;    // tamanho do vetor é dobrado
        array->vector = (int*) realloc(array->vector, array->total_size * sizeof(int));  // realloc para redimensionar o vetor
    }
    int index = array->size;
    array->vector[index] = value;  // elemento é adicionado na posição correta
    array->size++;
}

Array* newArray() {  // retorna um ponteiro para o array inicial
    Array* array = (Array*) malloc(sizeof(Array));
    if (array == NULL) {
       printf("Nao foi possivel alocar memoria para o array.\n");
       return NULL; 
    }

    array->total_size = 1; // vetor inicia com tamanho 1 - já que é inicializado com o tamanho de int
    array->size = 0;
    array->vector = (int*) malloc(sizeof(int));

    if (array->vector == NULL) {
        printf("Nao foi possivel alocar memoria para o vetor.\n");
        return NULL; 
    }

    return array;
}