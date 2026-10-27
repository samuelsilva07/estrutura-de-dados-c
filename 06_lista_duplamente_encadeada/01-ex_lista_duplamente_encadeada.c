#include <stdio.h>
#include <stdlib.h>
#include "deque.c"

int main () {
    Deque* vetor = newDeque();
    int num;
    for (int i = 0; i < 5; i++) {
        printf("Digite um numero para inserir na lista: ");
        if (scanf("%d", &num) != 1) {
            printf("Entrada invalida.\n");
            freeDeque(vetor);
            return EXIT_FAILURE;
        }
        vetor = add(vetor, num);
    }
    printf("\nLista duplamente encadeada: ");
    showDeque(vetor);

    printf("\nDigite um valor para remover da lista: ");
    int valor_removido;
    if (scanf("%d", &valor_removido) != 1) {
        printf("Entrada invalida.\n");
        freeDeque(vetor);
        return EXIT_FAILURE;
    }
    vetor = delete(vetor, valor_removido);  
    
    printf("\nLista apos remocao: ");
    showDeque(vetor);
    
    freeDeque(vetor);
    printf("\nMemoria liberada!\n");
    exit(EXIT_SUCCESS);
}