#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.c"

int main () {
    LinkedList* lista_ciclo = newLinkedList();
    int num;
    for (int i = 0; i < 5; i++) {
        printf("Digite um numero para adicionar a lista: ");
        scanf("%d", &num);
        lista_ciclo = add(lista_ciclo, num);
    }

    // Lista sem ciclo

    if (checkCycle(lista_ciclo)) {
        printf("Lista ciclo: ");
        showCycleList(lista_ciclo); 
    } else {
        printf("Lista encadeada: ");
        showLinkedList(lista_ciclo);
    }

    // lista com ciclo
    
    lista_ciclo = addCycle(lista_ciclo);
    
    if (checkCycle(lista_ciclo)) {
        printf("Lista ciclo: ");
        showCycleList(lista_ciclo); 
    } else {
        printf("Lista encadeada: ");
        showLinkedList(lista_ciclo);
    }

    freeLinkedList(lista_ciclo);
    exit(EXIT_SUCCESS);
}