#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main () {
    PILHA* p = pilhaCria();
    int valor_adicionado;
    printf("Nova pilha criada!\n");
    while(1) {
        printf("\nPilha atual: ");
        pilhaImprime(p);

        printf("Insira um elemento na pilha: ");
        if (scanf("%d", &valor_adicionado) != 1) {
            printf("ERRO: tipo de dado invalido.");
            return 0;
        } if (valor_adicionado == 0) {
            break;
        }

        pilhaPush(p, valor_adicionado);
    };

    printf("--------------------------------------\nPilha atual: ");
    pilhaImprime(p);

    int valor_removido;
    valor_removido = pilhaPop(p);
    printf("\nValor removido = %d\n", valor_removido);
    
    printf("\nPilha final: ");
    pilhaImprime(p);
    
    pilhaLibera(p);
    printf("Pilha liberada!\n");
    exit(EXIT_SUCCESS);
}