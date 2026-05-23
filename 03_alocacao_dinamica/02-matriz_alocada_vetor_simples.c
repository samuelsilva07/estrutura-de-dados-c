#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int tam, int *matriz) {
    for (int i = 0; i < tam; i++) printf("%d ", matriz[i]);
    printf("\n");
}

int* alocaMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    int* matrizAlocada = (int*) malloc(linhas*colunas*sizeof(int));
    // matrizAlocada = vetor unidimensional (tam = lin * col)
    if (matrizAlocada == NULL) {
        printf("\nNao foi possivel alocar memoria para a matriz\n");
        exit(EXIT_FAILURE);
    }
    int k = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            matrizAlocada[k++] = matriz[i][j];
    } 
    return matrizAlocada;
}

int main (void) {
    int M[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int* novaMatriz = alocaMatriz(4, 3, M);
    imprimeMatriz(4*3, novaMatriz);
    return 0;
}