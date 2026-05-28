#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"

int main () {
    ARV* a = arvCriaVazia();
    a = arvCriaNo('a', arvCriaVazia(), arvCriaVazia());
    arvImprime(a);
    printf("\n");
    a->esq = arvCriaNo('b', arvCriaNo('d', arvCriaVazia(), arvCriaVazia()), arvCriaNo('e', arvCriaVazia(),arvCriaVazia()));
    a->dir = arvCriaNo('c', arvCriaVazia(), arvCriaVazia());
    arvImprime(a);
    printf("\n");
    a->dir->esq = arvCriaNo('f', arvCriaNo('g', arvCriaVazia(), arvCriaVazia()), arvCriaNo('h',arvCriaVazia(),arvCriaVazia())); 
    arvImprime(a);
    printf("\n");
    printf("Altura da arvore = %d\n", arvAltura(a));
    a = arvLibera(a);
    printf("Arvore liberada!\n");
    exit(EXIT_SUCCESS);
}