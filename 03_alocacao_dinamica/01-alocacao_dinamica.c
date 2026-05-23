#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void imprimeVetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) printf("%d ", vetor[i]);
} 

int main (void) {
    //  ALOCAÇÃO DINÂMICA: processo de reservar um certo espaço na memória para armazenar dados

    /*  malloc: função que realiza esse processo
            -> sizeof(): determina o tipo de dado que iremos utilizar (int, char, structs, etc)
            -> TAM: quantidade de itens do tipo de dado desejado 
            -> produto de ambos: espaço total que será alocado
    */

    int* vet1 = (int*) malloc(TAM * sizeof(int));  // casting (int*) para definir o tipo de dados que estamos armazenando
    if (vet1 == NULL) { // este bloco verifica se a alocação foi realizada corretamente
        printf("\nNao foi possivel alocar memoria para o vetor\n");
        exit(EXIT_FAILURE);
    }
    printf("\nVetor alocado com sucesso!\n");
    printf("Digite os %d elementos do vetor:\n", TAM);
    for (int i = 0; i < TAM; i++) scanf("%d", &vet1[i]);
    printf("\nElementos do vetor: ");
    imprimeVetor(vet1, TAM);
    free(vet1);  // libera a memória alocada
    printf("\n------------------------------------------\n");  
    
    /*  calloc: aloca espaços na memória, porém inicializados com 0 
        *obs: quantidade de elementos e tipo de dado são PARÂMETROS SEPARADOS
    */

    int* vet2 = (int*) calloc(TAM, sizeof(int));
    if (vet2 == NULL) {
        printf("\nNao foi possivel alocar memoria para o vetor\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Vetor nulo: ");
    imprimeVetor(vet2, TAM);
    free(vet2);
    printf("\n------------------------------------------\n");

    /*  realloc: redefine a memória utilizada por um vetor, mas ainda preservando seus elementos
            -> vet: vetor a ser realocado
            -> TAM * sizeof(): nova dimensão do vetor
            *obs: só funciona com vetores alocados!
    */

    int novo_tamanho = 10;
    int* vet3 = (int*) malloc(TAM * sizeof(int));
    if (vet3 == NULL) {
        printf("\nNao foi possivel alocar memoria para o vetor\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Digite os %d elementos do vetor:\n", TAM);
    for (int i = 0; i < TAM; i++) scanf("%d", &vet3[i]);
    
    printf("Vetor inicial: ");
    imprimeVetor(vet3, TAM);

    int* vet4 = (int*) realloc(vet3, novo_tamanho * sizeof(int));
    if (vet4 == NULL) {
        printf("\nNao foi possivel alocar memoria para o vetor\n");
        exit(EXIT_FAILURE);
    }

    printf("\n\nVetor realocado com sucesso!");
    printf("\nDigite os elementos adicionais do vetor: ");
    for (int i = TAM; i < novo_tamanho; i++) scanf("%d", &vet4[i]);

    printf("\nVetor realocado: ");
    imprimeVetor(vet4, novo_tamanho);
    free(vet4);
    exit(EXIT_SUCCESS);
}