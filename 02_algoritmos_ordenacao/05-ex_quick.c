#include <stdio.h> 
#include "ordenacao.c" 

void imprime(int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

int main (void) {
    int lista[10] = {2, 3, 1, 8, 7, 5, 6, 9, 0, 4};
    printf("Vetor nao ordenado:\n");
    imprime(10, lista);
    printf("\n");
    quick(10, lista);
    printf("Vetor ordenado:\n");
    imprime(10, lista);
    return 0;
}