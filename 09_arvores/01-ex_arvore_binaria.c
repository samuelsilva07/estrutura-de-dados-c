#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"

int main () {
    ARV* arvore = arvCriaVazia();
    printf("Uma nova arvore foi criada!\n");

    /* utilização das FUNÇÕES para criar os ramos (TIPO ARV!!!)*/
    arvore = arvCriaNo('a', arvCriaVazia(), arvCriaVazia());
    arvImprime(arvore);
    printf("\n");

    arvore->esq = arvCriaNo('b', arvCriaVazia(), arvCriaNo('d', arvCriaVazia(), arvCriaVazia()));
    arvore->dir = arvCriaNo('c', arvCriaNo('e', arvCriaVazia(), arvCriaVazia()), arvCriaNo('f', arvCriaVazia(), arvCriaVazia()));
    arvImprime(arvore);
    printf("\nAltura: %d\n", arvAltura(arvore));

    arvLibera(arvore);
    printf("\nArvore liberada!\n");
    return 0;
}