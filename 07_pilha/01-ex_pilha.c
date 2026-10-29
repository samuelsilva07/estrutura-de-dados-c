#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main () {
    Stack* pilha = newStack();
    int valor;
    printf("Nova pilha criada!\n");
    while(1) {
        printf("\nPilha atual: ");
        showStack(pilha);

        printf("Insira um elemento na pilha: ");
        if (scanf("%d", &valor) != 1) {
            printf("ERRO: tipo de dado invalido.");
            return 0;
        } if (valor == 0) {
            break;
        }

        push(pilha, valor);
    };

    printf("--------------------------------------\nPilha atual: ");
    showStack(pilha);

    int valor_removido;
    valor_removido = pop(pilha);
    printf("\nValor removido = %d\n", valor_removido);
    
    printf("\nPilha final: ");
    showStack(pilha);
    printf("Topo da pilha: ");
    showFirst(pilha);
    
    freeStack(pilha);
    printf("Pilha liberada!\n");
    exit(EXIT_SUCCESS);
}