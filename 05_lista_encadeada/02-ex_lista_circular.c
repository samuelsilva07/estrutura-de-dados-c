#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.c"

int main () {
    LISTA* lista_ciclo = listaCria();
    int num;
    for (int i = 0; i < 5; i++) {
        printf("Digite um numero para adicionar a lista: ");
        scanf("%d", &num);
        lista_ciclo = listaInsere(lista_ciclo, num);
    }
    lista_ciclo = listaCriarCiclo(lista_ciclo);
    if (listaVerificaCiclo(lista_ciclo)) {
        printf("Lista ciclo: ");
        listaImprimeCiclo(lista_ciclo); 
    } else {
        printf("Lista encadeada: ");
        listaImprime(lista_ciclo);
    }
    exit(EXIT_SUCCESS);
}