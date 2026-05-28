#include <stdio.h>
#include "busca.c"

int main () {
    int vetor[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;
    imprimirVetor(vetor, TAM);
    printf("\nDigite um numero: ");
    scanf("%d", &n);
    int resultado = buscaBinariaRecursiva(n, vetor, 0, TAM - 1);
    if (resultado != NAOENCONTRADO)
        printf("Numero encontrado na posicao %d", resultado);
    else
        printf("Numero nao encontrado");
    return 0;
}