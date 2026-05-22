#include <stdio.h>

void imprime (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

void selectionSort(int tam, int* vet) {
    int menor; // índice do menor elemento
    for (int i = 0; i < tam; i++) {
        menor = i; 
        for (int j = i + 1; j < tam; j++)
            if (vet[j] < vet[menor]) menor = j;
        if (menor != i){
            int temp = vet[i];
            vet[i] = vet[menor];
            vet[menor] = temp;
        }
    }
}

int main (void) {
    int lista[10] = {2, 3, 1, 4, 7, 5, 6, 9, 0, 8};
    printf("Vetor nao ordenado:\n");
    imprime(10, lista);
    selectionSort(10, lista);
    printf("Vetor ordenado:\n");
    imprime(10, lista);
    return 0;
}