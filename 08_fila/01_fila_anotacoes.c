#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

int main () {
    system("cls");
    Queue* fila = newQueue();
    printf("Uma nova fila foi criada!\n");
    int valor_adicionado;
    while(1) {
        printf("Digite um numero para adicionar a fila: ");
        scanf("%d", &valor_adicionado);
        if (valor_adicionado == 0) break;
        enqueue(fila, valor_adicionado);
    }
    
    printf("\nFila atual: ");
    showQueue(fila);
    
    int valor_removido = dequeue(fila);
    printf("\nValor removido: %d\n\n", valor_removido);

    printf("Fila atual: ");
    showQueue(fila);
    printf("Inicio da fila: ");
    showFirst(fila);
    printf("Final da fila: ");
    showLast(fila);

    freeQueue(fila);
    printf("\nMemoria liberada!\n");
    exit(EXIT_SUCCESS);
}