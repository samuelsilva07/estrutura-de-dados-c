#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct heap {
    int tamanho;                // Tamanho total do vetor da heap
    int quantidade;             // Quantidade de elementos na heap
    int vetor[TAMANHO_MAX];     // Vetor da heap
};

void heapLibera(HEAP* heap) {
    free(heap);
}

int divInt(int num1, int num2) {
    return (int) num1 / num2;
}

int heapVazia(HEAP* heap) {
    return heap->quantidade == 0;
}

int heapCheia(HEAP* heap) {
    return heap->quantidade >= TAMANHO_MAX;
}

void heapImprime(HEAP* heap) {  // Imprime os valores da heap
    printf("\n[");
    if (!heapVazia(heap)) {
        for (int i = 0; i < heap->quantidade; i++){
            printf("%d, ", heap->vetor[i]);
        }
        printf("\b\b");
    }
    printf("]\n");
}

int heapRemove(HEAP* heap) {    // Remove um elemento da heap
    if (heapVazia(heap)) {
        printf("A heap esta vazia!");
        return -1;
    }
    
    // remoção do primeiro elemento (possui o maior índice)
    int valor = heap->vetor[heap->quantidade - 1]; // valor do último elemento da heap
    int removido = heap->vetor[0];
    --heap->quantidade;

    int k = 0; // começa no topo da heap (elemento que será removido)

    if (heapVazia(heap)) {
        return removido;
    }

    // enquanto não chegar no final da heap e o último elemento for menor do que os comparados, ocorre a troca de valores
    while(2*k + 1 < heap->quantidade) {
        int indice_esq = 2*k + 1, indice_dir = 2*k + 2;
        int indice;

        // troca é direcionada para o lado esquerdo
        if (heap->vetor[indice_esq] > heap->vetor[indice_dir]) 
            indice = indice_esq;

        // troca é direcionada para o lado direito
        else indice = indice_dir;

        // se a posição correta for encontrada, o loop se encerra
        if (heap->vetor[indice] <= valor) break;

        // elemento "sobe" na heap
        heap->vetor[k] = heap->vetor[indice];    

        k = indice;
    }
    heap->vetor[k] = valor; // elemento é realocado na posição correta
    return removido;
}

void heapInsere(HEAP* heap, int valor) {  // Insere um elemento na heap
    if (heapCheia(heap)) {
        printf("A heap esta cheia!\n");
        return;
    }
    heap->quantidade++; // tamanho da heap aumenta em uma unidade
    int k = heap->quantidade - 1; // k recebe o índice do último elemento 
    // se o elemento for maior do que seu pai (índice k/2), troca os elementos até encontrar a posição correta para o novo elemento
    while (k > 0 && (valor > heap->vetor[divInt(k, 2)])) {
        heap->vetor[k] = heap->vetor[divInt(k, 2)];
        k = divInt(k, 2);
    }
    heap->vetor[k] = valor; // elemento é inserido na posição correta
}

HEAP* heapCria() {  // Cria uma heap vazia
    HEAP* nova_heap = (HEAP*) malloc(sizeof(HEAP));
    nova_heap->quantidade = 0;
    nova_heap->tamanho = TAMANHO_MAX;
    return nova_heap;
}
