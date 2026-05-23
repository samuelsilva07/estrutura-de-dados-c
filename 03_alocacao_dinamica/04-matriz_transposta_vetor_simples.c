#include <stdio.h>
#include <stdlib.h>

void liberaMatriz(float* matriz) {
    free(matriz);
}

void imprimeMatrizTransposta(int linhas, int colunas, float* matriz) {
    printf("\nMatriz Transposta:\n\n");
    for (int i = 0; i < linhas*colunas; i++){
        printf("%.1f  ", matriz[i]);
        if ((i + 1) % colunas == 0) printf("\n");
    }
    printf("\n");
}

void imprimeMatriz(int linhas, int colunas, float matriz[][colunas]) {
    printf("\nMatriz Original:\n\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%.1f  ", matriz[i][j]);
        printf("\n");
    }
}

float* transposta(int linhas, int colunas, float* m1, float* m2) {
    if (m2 != NULL) {
        for (int i = 0; i < linhas; i++) 
            for (int j = 0; j < colunas; j++) 
                m2[i*linhas+j] = m1[j*colunas+i];
    }
    return m2;
}

float* alocaMatriz(int linhas, int colunas) {
    float* novaMatriz = (float*) malloc(linhas*colunas*sizeof(float));
    if (novaMatriz == NULL) {
        printf("\nNao foi possivel alocar memoria para a matriz\n");
        exit(EXIT_FAILURE);
    }
    return novaMatriz;
}

int main (void) {
    float M[3][3] = {{1, 4, 5}, {13, 3, 6}, {9, 15, 0}};
    imprimeMatriz(3, 3, M);
    float* matrizTransposta = alocaMatriz(3, 3);
    matrizTransposta = transposta(3, 3, M, matrizTransposta);
    imprimeMatrizTransposta(3,3, matrizTransposta);
    liberaMatriz(matrizTransposta);
    return 0;
}