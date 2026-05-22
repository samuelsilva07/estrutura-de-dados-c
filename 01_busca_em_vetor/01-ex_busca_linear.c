#include <stdio.h>
#include "busca.c"

int main () {
    int vetor[TAM] = {1, 4, 3, 5, 7, 8, 5, 10, 9, 6}; // vetor de exemplo
    int n;
    imprimirVetor(vetor, TAM);
    printf("\nDigite um numero: ");
    scanf("%d", &n);
    int resultado = buscaLinear(n, vetor, TAM);
    if (resultado != NAOENCONTRADO)
        printf("Numero encontrado na posicao %d", resultado);
    else
        printf("Numero nao encontrado");
    return 0;
}