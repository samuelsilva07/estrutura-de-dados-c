#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_busca.c"

int main () {
    ABB* arvore = abbCriaVazia();
    printf("Uma nova arvore foi criada!\n");
    
    int valor;
    while(1) { 
        printf("\nArvore atual: ");
        abbImprime(arvore);

        printf("\nDigite um numero para adicionar a arvore (ou 0 para sair): ");
        scanf("%d", &valor);
        
        if (valor == 0) break;
        arvore = abbInsere(valor, arvore);
    }
    printf("\nArvore: ");
    abbImprime(arvore);
    
    printf("\nDigite um valor para remover da arvore: ");
    scanf("%d", &valor);
    arvore = abbRemove(valor, arvore);

    printf("\nArvore final: ");
    abbImprime(arvore);
    printf("\nAltura: %d\n", abbAltura(arvore));
    
    arvore = abbLibera(arvore);
    printf("Arvore liberada!\n");
    return 0;
}