#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.c"

void imprime (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

int main (void) {
    int lista[7] = {38, 27, 43, 3, 9, 82, 10};
    printf("Vetor nao ordenado:\n");
    imprime(7, lista);
    mergeSort(0, 7, lista);
    printf("Vetor ordenado:\n");
    imprime(7, lista);
    return 0;
}