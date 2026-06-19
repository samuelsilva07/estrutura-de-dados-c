#include <stdio.h>
#include <stdlib.h>
#include "fila.c"
#define TRUE 1
#define MAX 40

int main () {
    FILA* fila = filaCria();
    int senha = 1, OK = 1;
    char operacao[MAX+1];
    do {
        int inseridos = 0, atendidos = 0;
        printf("\nFila atual: ");
        filaImprime(fila);
        printf("\nI - Inserir cliente na fila\nA - Atender cliente da fila\nS - Sair\n");
        printf("Digite as operacoes que serao realizadas (MAX = %d): ", MAX);
        fgets(operacao, 40, stdin);
        for (int i = 0; operacao[i] != '\0'; i++) {
            if (operacao[i] == 'S' || operacao[i] == 's') OK = 0;
            else if (operacao[i] == 'I' || operacao[i] == 'i') {
                filaInsere(fila, senha);
                inseridos++;
                senha++;
            }
            else if (operacao[i] == 'A' || operacao[i] == 'a') {
                if (fila == NULL) printf("A fila está vazia.\n");
                else {
                    filaRemove(fila);
                    atendidos++;
                }
            }
            else printf("Caractere invalido, tente novamente.\n");
        }
        printf("\n");
        if (inseridos) printf("Clientes inseridos = %d\n", inseridos);
        if (atendidos) printf("Clientes atendidos = %d\n", atendidos);
    } while (OK);
    filaLibera(fila);
    printf("Fim do programa.\n");
    exit(EXIT_FAILURE);
}