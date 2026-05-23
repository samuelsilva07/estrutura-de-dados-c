#include <stdio.h>
#include <stdlib.h>

int** liberaMatriz(int linhas, int** matriz) {
    if (matriz != NULL) {
        for (int i = 0; i < linhas; i++)
            if (matriz[i] != NULL) free(matriz[i]);
    }
    free(matriz);
    printf("Matriz liberada!\n");
    return NULL;
}

void imprimeMatrizAlocada(int linhas, int colunas, int** matriz) {
    for (int i = 0; i < linhas; i++) 
        for (int j = 0; j < colunas; j++)
            printf("%d ", matriz[i][j]);
    printf("\n");
}

int** copiaMatriz(int linhas, int colunas, int* m1[][colunas], int** m2) {
    for (int i = 0; i < linhas; i++) 
        for (int j = 0; j < colunas; j++) 
            m2[i][j] = m1[i][j];
        
    return m2;
}

int** alocaMatriz(int linhas, int colunas) {
    int** matrizAlocada = (int**) malloc(linhas*sizeof(int*));
    // matrizAlocada = ponteiro para vetor
    if (matrizAlocada == NULL) {
        printf("\nNao foi possivel alocar memoria para a matriz\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < linhas; i++) {
        matrizAlocada[i] = (int*) malloc(colunas*sizeof(int));
        // cada elemento também é um ponteiro para vetor
        if(matrizAlocada[i] == NULL) exit(1);
    }
    printf("Matriz alocada!\n");
    return matrizAlocada;
}

int main (void) {
    int M[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int** novaMatriz = alocaMatriz(4, 3);
    novaMatriz = copiaMatriz(4, 3, M, novaMatriz);
    imprimeMatrizAlocada(4,3, novaMatriz);
    novaMatriz = liberaMatriz(4, novaMatriz);
    return 0;
}