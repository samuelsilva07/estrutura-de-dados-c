#include <stdio.h>
#include <stdlib.h>
#include "fila.c"

/* Fila  */

int main () {
    system("cls");
    FILA* fila = filaCria();
    printf("Uma nova fila foi criada!\n");
    int valor_adicionado;
    while(1) {
        printf("Digite um numero para adicionar a fila: ");
        scanf("%d", &valor_adicionado);
        if (valor_adicionado == 0) break;
        filaInsere(fila, valor_adicionado);
    }
    
    printf("\nFila atual: ");
    filaImprime(fila);
    
    int valor_removido = filaRemove(fila);
    printf("\nValor removido: %d\n", valor_removido);
    printf("Fila atual: ");
    filaImprime(fila);

    filaLibera(fila);
    printf("\nMemoria liberada!\n");
    exit(EXIT_SUCCESS);
}