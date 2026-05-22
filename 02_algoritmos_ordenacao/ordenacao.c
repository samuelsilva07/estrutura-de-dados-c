#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int checaVetor(int tam, int* vet) { // verifica se o vetor está ordenado
    for (int i = 0; i < tam; i++)
        if (vet[i] > vet[i + 1]) return 0;
    return 1;
}

void bolha(int* vet, int i) { // função que troca a posição de um elemento com seu sucessor 
    int temp = vet[i];
    vet[i] = vet[i + 1];
    vet[i + 1] = temp;
}

void bubbleSort(int tam, int* vet) {
    int fim = tam - 1, OK = 0;
    do {
        OK = 0; // indica se houve troca no vetor
        for (int i = 0; i < fim; i++) { 
            if (vet[i] > vet[i + 1]) {
                OK = 1;                 
                // Bolha - troca dos elementos:  
                bolha(vet, i);
            }
        }
        fim--;    // diminui o tamanho do vetor, pois o elemento na posição [fim] já está ordenado
    } while (OK); // loop se encerra quando nenhuma troca for realizada
}

void bubbleSortRecursivo(int tam, int* vet) {
    int fim = tam - 1, houve_troca = 0; 
    for (int i = 0; i < fim; i++) {
        if (vet[i] > vet[i + 1]) {
            houve_troca = 1;
            bolha(vet, i);
        }
    }
    // se uma troca foi realizada, a função é chamada novamente
    // tamanho do vetor REDUZIDO (sem os elementos ordenados)
    if (houve_troca) bubbleSortRecursivo(tam - 1, vet); 
}

void insertionSort(int tam, int* vet) {
    for (int i = 1; i < tam; i++) { // loop vai "aumentando" o tamanho do vetor a ser tratado
        int j = i;  // j recebe o valor do fim do "sub-vetor"
        while (j > 0 && vet[j - 1] > vet[j]) {
            bolha(vet, j - 1);
            j--;  // elementos são comparados na ordem INVERSA
        } 
    }
}

void selectionSort(int tam, int* vet) {
    int menor; 
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

void quick(int tam, int* vet) {
    if (tam > 1) { // verifica se o vetor tem tamanho 1 (não é necessário ordenar)
        int pivo = vet[0];
        int a = 1, b = tam - 1;
        do {
            while (a < tam && vet[a] <= pivo) a++;  // procura elemento maior que o pivô (início ao fim do vetor)
            while (vet[b] > pivo) b--;  // procura elemento menor que o pivô (fim ao início)
            if (a < b) { // troca dos elementos (bolha)
                int temp = vet[a];
                vet[a] = vet[b];
                vet[b] = temp;
                a++; b--;   // continua a percorrer o vetor
            }
        } while (a <= b); // enquanto o local de a seja menor ou igual ao de b (inversão)
        vet[0] = vet[b];
        vet[b] = pivo; // troca do elemento menor que o pivô com o pivô
        
        quick(b, vet); // ordena subvetor 1 (anterior ao pivô)
        quick(tam - a, &vet[a]); // ordena subvetor 2 (após o pivô)
    }
}

void intercala(int inicio, int meio, int fim, int *vet) {
    int i = inicio, j = meio, k = 0;
    int *vetTemp = malloc((fim - inicio) * sizeof(int)); // vetor com o tamanho da parte a ser ordenada 
    if (vetTemp == NULL) {
        printf("Memoria indisponivel para alocar o vetor!\n");
        exit(EXIT_FAILURE);
    }

    // adiciona os valores de forma ordenada no vetor (enquanto uma das condições não falhar)
    while (i < meio && j < fim) { 
        if (vet[i] <= vet[j]) vetTemp[k++] = vet[i++]; 
        else vetTemp[k++] = vet[j++];
    }

    // adiciona os valores que não foram ordenados em vetTemp 
    // obs: um desses loops NÂO VAI OCORRER, pois já foi realizado na etapa anterior
    while(i < meio) vetTemp[k++] = vet[i++];
    while(j < fim) vetTemp[k++] = vet[j++];

    // copia vetTemp para o vetor original (na metade correta - começando do local em inicio)
    for (i = inicio; i < fim; i++)
         vet[i] = vetTemp[i - inicio];
    // posição inicio de vet = posição 0 de vetTemp
    free(vetTemp); // libera a memória utilizada na alocação
}

void mergeSort(int inicio, int tam, int* vet) {
     if (inicio < tam - 1) {
        int meio = (int) (inicio + tam) / 2;
        mergeSort(inicio, meio, vet); // primeira metade
        mergeSort(meio, tam, vet);    // seguinda metade
        intercala(inicio, meio, tam, vet);  // "mescla" os vetores
     }
}