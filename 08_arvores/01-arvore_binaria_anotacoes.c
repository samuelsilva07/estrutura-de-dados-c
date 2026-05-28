#include <stdio.h>
#include <stdlib.h>

/* árvores - funçôes baseadas em RECURSÃO! */

typedef struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
} ARV;

void arvImprime(ARV* arvore) {
    printf("<");
    if(arvore != NULL) {
        printf("%c ", arvore->info);
        arvImprime(arvore->esq);
        arvImprime(arvore->dir);
    }
    printf("> ");
}

int arvPertence(ARV* arvore, int valor) { 
    // retorna valores BOOLEANOS (pertence ou não pertence)
    if (arvore == NULL) return 0;
    else return arvore->info == valor || arvPertence(arvore->esq, valor) || arvPertence(arvore->dir, valor) == valor;
    // recursão para verificação nos ramos 
}

ARV* arvLibera(ARV* arvore) {
    if (arvore != NULL) {
        // recursão para liberar os ramos
        arvLibera(arvore->esq);
        arvLibera(arvore->dir);
        free(arvore);
    }
    return NULL;
}

ARV* arvCriaNo (char valor, ARV* esq, ARV* dir) {
    ARV* no = (ARV*) malloc(sizeof(ARV));
    no->info = valor;
    no->esq = esq;
    no->dir = dir;
    return no;
}

ARV* arvCriaVazia() {
    return NULL;
}

int main () {
    ARV* arvore = arvCriaVazia();
    /* utilização das FUNÇÕES para criar os ramos (TIPO ARV!!!)*/
    arvore = arvCriaNo('a', arvCriaVazia(), arvCriaVazia());
    arvImprime(arvore);
    printf("\n");
    arvore->esq = arvCriaNo('b', arvCriaVazia(), arvCriaNo('d', arvCriaVazia(), arvCriaVazia()));
    arvore->dir = arvCriaNo('c', arvCriaNo('e', arvCriaVazia(), arvCriaVazia()), arvCriaNo('f', arvCriaVazia(), arvCriaVazia()));
    arvImprime(arvore);
    arvLibera(arvore);
    printf("Arvore liberada!\n");
    return 0;
}