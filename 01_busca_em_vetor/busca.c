#include <stdio.h>
#include "busca.h"

int buscaLinear(int n, int* vet, int tam) { // percorre todo o vetor em busca do elemento desejado
    for (int i = 0; i < tam; i++) 
        if (vet[i] == n) return i;
    return NAOENCONTRADO;
}

int buscaBinaria(int n, int* vet, int tam) {
    /*
        - inicia a busca do meio do vetor
        - se o elemento for maior, procura na metade à direita 
        - caso contrário, procura na metade à esquerda

        obs: recomendado para listas ORDENADAS!
    */
    int meio, inicio = 0, fim = tam;
    while (inicio <= meio) {
        meio = (int) (inicio + fim) / 2;
        if (n > vet[meio]) inicio = meio;   // início do subvetor à direita é o elemento central
        else if (n < vet[meio]) fim = meio; // fim do subvetor à esquerda é o elemento central
        else return meio;
    }
    return NAOENCONTRADO;
}

int buscaBinariaRecursiva(int n, int* vet, int inicio, int fim) {  
    int meio = ((int) (inicio + fim) / 2);
    if (inicio > fim) return NAOENCONTRADO;
    else { 
        if (n == vet[meio]) return meio;
        if (n > vet[meio]) return buscaBinariaRecursiva(n, vet, meio + 1, fim);
        if (n < vet[meio]) return buscaBinariaRecursiva(n, vet, inicio, meio - 1);
        /* não há necessidade de elses (função é recursiva) - programa levemente mais rápido */
    }
}

void imprimirVetor(int* vetor, int tam) {
    printf("Vetor: [");
    for (int i = 0; i < tam; i++) {
        printf("%d", vetor[i]);
        if (i != tam - 1) printf(", ");
    }
    printf("]\n");
}