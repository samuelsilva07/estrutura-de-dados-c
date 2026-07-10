#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Esta biblioteca contém as funções para a manipulação de árvores binárias simples 

struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};

ARV* arvLibera(ARV* arvore) {   // Libera a memória alocada para a árvore 
    if (!arvVazia(arvore)) {
        // recursão para liberar os ramos
        arvLibera(arvore->esq);
        arvLibera(arvore->dir);
        free(arvore);
    }
    return NULL;
}

int maiorSubArvore(int n1, int n2) {  // retorna o maior valor entre as alturas das subárvores
    return (n1 > n2) ? n1 : n2;
}

int arvAltura(ARV* arvore) {    // Retorna a altura da árvore
    if (arvVazia(arvore)) return 0; // árvore vazia = retorna 0
    return 1 + maiorSubArvore(arvAltura(arvore->esq), arvAltura(arvore->dir));
    
}

int arvPertence(char valor, ARV* arvore) {  // Verifica se um valor está na árvore  
    // retorna valores BOOLEANOS (pertence ou não pertence)
    if (arvVazia(arvore)) return 0;
    else return arvore->info == valor || arvPertence(valor, arvore->esq) || arvPertence(valor, arvore->dir);
    // recursão para verificação nos ramos 
}

int arvVazia(ARV* arvore) {  // Retorna 1 se a árvore está vazia e 0 caso contrário  
    return arvore == NULL;
}

void arvImprime(ARV* arvore) { // Imprime os valores da árvore em pré-ordem (raiz -> sae -> sad)
    if(!arvVazia(arvore)) {
        printf("<");
        printf("%c ", arvore->info);
        arvImprime(arvore->esq);
        arvImprime(arvore->dir);
        printf(">");
    }
}

ARV* arvCriaNo(char valor, ARV* arv_esq, ARV* arv_dir) {   // cria um nó da árvore com o seu respectivo valor
    ARV* p = (ARV*) malloc(sizeof(ARV));
    p->info = valor;
    p->esq = arv_esq;
    p->dir = arv_dir;
    return p;
}

ARV* arvCriaVazia() {   // cria uma árvore vazia
    return NULL;
}
