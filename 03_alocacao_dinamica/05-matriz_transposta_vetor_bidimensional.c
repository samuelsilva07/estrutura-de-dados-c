#include <stdio.h>
#include <stdlib.h>

float** liberaMatriz(int linhas, float** matriz) {
    for (int i = 0; i < linhas; i++) 
        if (matriz[i] != NULL) free(matriz[i]);
    free(matriz);
    return matriz;
} 

void imprimeMatrizTransposta(int linhas, int colunas, float** matriz) {
    printf("\nMatriz Transposta:\n\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%.1f  ", matriz[i][j]);
        printf("\n");
    }
}

void imprimeMatriz(int linhas, int colunas, float matriz[][colunas]) {
    printf("\nMatriz Original:\n\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%.1f  ", matriz[i][j]);
        printf("\n");
    }
}

float** transposta(int linhas, int colunas, float m1[][colunas], float** m2) {
    if (m2 != NULL) {
        for (int i = 0; i < linhas; i++) 
            for (int j = 0; j < colunas; j++)
                m2[j][i] = m1[i][j];
    }   
    return m2;
}

float** alocaMatriz(int linhas, int colunas) {
    float** matriz = (float**) malloc(linhas * sizeof(float*));
    if (matriz == NULL) {
        printf("\nNao foi possivel alocar memoria para a matriz\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < colunas; i++) 
        matriz[i] = (float*) malloc(colunas*sizeof(int));
    printf("\nMemoria alocada!\n");
    return matriz;
}

int main (void) {
    float M[3][3] = {{1, 4, 5}, {13, 3, 6}, {9, 15, 0}};
    imprimeMatriz(3, 3, M);
    float** matrizTransposta = alocaMatriz(4, 3);
    matrizTransposta = transposta(3, 3, M, matrizTransposta);
    imprimeMatrizTransposta(3,3, matrizTransposta);
    matrizTransposta = liberaMatriz(4, matrizTransposta);
    return 0;
}