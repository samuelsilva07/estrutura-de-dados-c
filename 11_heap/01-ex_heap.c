#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

int main () {
    HEAP* heap = heapCria();
    printf("Nova heap criada!\n");

    int valor;
    while(1) {
        printf("Heap atual: ");
        heapImprime(heap);

        printf("Digite um numero para adicionar a heap: ");
        scanf("%d", &valor);

        if (valor == 0) break;
        heapInsere(heap, valor);
    }

    printf("Heap: ");
    heapImprime(heap);

    int valor_removido = heapRemove(heap);
    printf("O valor %d foi removido!\n", valor_removido);


    printf("\nHeap final: ");
    heapImprime(heap);

    heapLibera(heap);
    printf("\nMemoria liberada!\n");
    
    return 0;
}