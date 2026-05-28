#include <stdio.h>
#define TAM 10
#define NAOENCONTRADO -1

int buscaLinear(int n, int* vet, int tam);
int buscaBinaria (int n, int* vet, int tam);
int buscaBinariaRecursiva(int n, int* vet, int inicio, int fim);

void imprimirVetor(int* vetor, int tam);