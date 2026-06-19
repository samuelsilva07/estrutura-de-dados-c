#include <stdio.h>
#include <stdlib.h>
#include "deque.c"

int main () {
    DEQUE* vetor = dequeCria();
    int num;
    for (int i = 0; i < 5; i++) {
        printf("Digite um numero para inserir na lista: ");
        scanf("%d", &num);
        vetor = dequeInsere(vetor, num);
    }
    printf("\nLista duplamente encadeada: ");
    dequeImprimir(vetor);

    printf("\nDigite um valor para remover da lista: ");
    int valor_removido = scanf("%d", &valor_removido);
    vetor = dequeRemove(vetor, valor_removido);  
    
    printf("\nLista apos remocao: ");
    dequeImprimir(vetor);
    
    dequeLibera(vetor);
    printf("\nMemoria liberada!\n");
    exit(EXIT_SUCCESS);
}