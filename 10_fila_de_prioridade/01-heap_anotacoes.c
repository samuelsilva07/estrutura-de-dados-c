#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_MAX 127
typedef int Heap[TAMANHO_MAX];

int divInt(int num1, int num2) {
    return (int) num1 / num2;
}

int heapVazia(int quantidade) {
    return quantidade == 0;
}

int heapCheia(int quantidade) {
    return quantidade >= TAMANHO_MAX;
}

void heapImprime(int* heap, int quantidade) {
    printf("\n[");
    for (int i = 0; i < quantidade; i++) {
        printf("%d, ", heap[i]);
    }
    printf("\b\b]\n");
}

void heapRemove(int* heap, int* quantidade) {
    // remoção do primeiro elemento (possui o maior índice)
    int ultimo = (*quantidade) - 1;
    int valor = heap[ultimo]; // valor do último elemento da heap
    int k = 0; // começa no topo da heap (elemento que será removido)
    // enquanto não chegar no final da heap e o último elemento for menor do que os comparados, ocorre a troca de valores
    while ((2*k < ultimo) && (valor < heap[2*k + 1] || valor < heap[2*k + 2])) {
        // inserção do lado esquerdo
        if (heap[2*k + 1] > heap[2*k + 2]) {
            heap[k] = heap[2*k + 1];
            k = 2*k + 1;
        }
        // inserção do lado direito
        else {
            heap[k] = heap[2*k + 2];
            k = 2*k + 2;
        }
    }
    heap[k] = valor; // elemento é realocado na posição correta
    --(*quantidade);  
}

void heapInsere(int* heap, int* quantidade, int valor) {
    if ((*quantidade) < TAMANHO_MAX) {
        (*quantidade)++; // tamanho da heap aumenta em uma unidade
        int k = (*quantidade) - 1; // k recebe o índice do último elemento 
        // se o elemento for maior do que seu pai (índice k/2), troca os elementos até encontrar a posição correta para o novo elemento
        while (k > 0 && (valor > heap[divInt(k, 2)])) {
            heap[k] = heap[divInt(k, 2)];
            k = divInt(k, 2);
        }
        heap[k] = valor; // elemento é inserido na posição correta
        return;
    }
    printf("A fila está cheia!\n");
}

int main () {
    Heap heap;
    int quantidade = 0;
    heapInsere(heap, &quantidade, 1);
    heapInsere(heap, &quantidade, 5);
    heapInsere(heap, &quantidade, 4);

    heapImprime(heap, quantidade);

    heapInsere(heap, &quantidade, 8);
    heapInsere(heap, &quantidade, 3);
    heapInsere(heap, &quantidade, 7);

    heapImprime(heap, quantidade);

    heapRemove(heap, &quantidade);
    heapImprime(heap, quantidade);

    heapRemove(heap, &quantidade);
    heapImprime(heap, quantidade);
    
    exit(EXIT_SUCCESS);
}