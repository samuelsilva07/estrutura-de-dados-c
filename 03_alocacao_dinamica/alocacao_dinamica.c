#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main (void) {
    int* vet = (int*) malloc(TAM * sizeof(int));
    printf("Digite os %d elementos do vetor:\n", TAM);
    for (int i = 0; i < TAM - 1; i++) scanf("%d ", &vet[i]);
    printf("Vetor alocado com sucesso!\n");
    free(vet);
    exit(EXIT_SUCCESS);
}