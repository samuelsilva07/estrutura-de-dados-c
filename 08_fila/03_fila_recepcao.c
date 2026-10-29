#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.c"
#define TRUE 1
#define MAX 40

void menu(Queue* fila) {
    system("cls");
    printf("\nFila atual: ");
    showQueue(fila);
    printf("\nI - Inserir cliente na fila\nA - Atender cliente da fila\nS - Sair\n");
    printf("Digite as operacoes que serao realizadas (MAX = %d): ", MAX);
}

int main () {
    Queue* fila = newQueue();
    int senha = 1, OK = 1;
    char operacao[MAX + 1];
    do {
        int inseridos = 0, atendidos = 0;
        menu(fila);
        fgets(operacao, MAX, stdin);

        for (int i = 0; operacao[i] != '\n'; i++) {
            if (operacao[i] == 'S' || operacao[i] == 's') {
                OK = 0;
                break;
            } else if (operacao[i] == 'I' || operacao[i] == 'i') {
                enqueue(fila, senha);
                inseridos++;
                senha++;
            } else if (operacao[i] == 'A' || operacao[i] == 'a') {
                if (isEmpty(fila)){
                    printf("A fila esta vazia.\n");
                    sleep(2);
                }
                else {
                    dequeue(fila);
                    atendidos++;
                }
            } else {
                printf("Operacao invalida, tente novamente.\n");
            }
        }

        printf("\n");
        if (inseridos) {
            printf("Clientes inseridos = %d\n", inseridos);
            sleep(2);
        }
        if (atendidos) {
            printf("Clientes atendidos = %d\n", atendidos);
            sleep(2);
        }
    } while(OK);
    freeQueue(fila);
    printf("Fim do programa.\n");
    exit(EXIT_FAILURE);
}