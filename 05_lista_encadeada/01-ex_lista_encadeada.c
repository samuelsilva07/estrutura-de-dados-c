#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"

int main () {
    LinkedList* lista_encadeada = newLinkedList();
    int num;
    for (int i = 0; i < 6; i++) {
        printf("Digite um numero para adicionar a lista: ");
        scanf("%d", &num);
        // lista_encadeada = add(lista_encadeada, num);
        lista_encadeada = addInOrder(lista_encadeada, num);
    }
    showLinkedList(lista_encadeada);
    lista_encadeada = delete(lista_encadeada, 5);
    showLinkedList(lista_encadeada);

    // BUSCA DE ELEMENTO
    printf("Valor: ");
    scanf("%d", &num);
    if (checkValue(lista_encadeada, num)) {
        printf("O valor esta na lista.\n");
    } else {
        printf("O valor nao esta na lista.\n");
    }
    
    freeLinkedList(lista_encadeada);    
    exit(EXIT_SUCCESS);
}