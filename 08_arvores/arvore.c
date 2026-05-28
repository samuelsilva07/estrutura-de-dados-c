#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/* Esta biblioteca contém as funções para a manipulação de:
    - Árvores binárias simples (arv) 
    - Arvores binarias de busca (abb)

   obs: todas as funções de árvores binarias simples podem ser utilizadas em arvores binárias de busca 
   (exceto arvImprime(), visto que a ordem de impressão dos dois tipos de árvore é distinta)
*/

typedef struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};

ARV* arvLibera(ARV* arvore) {
    if (arvore != NULL) {
        arvLibera(arvore->esq);
        arvLibera(arvore->esq);
        free(arvore);
    }
    return NULL;
}

int maiorSubArvore(int n1, int n2) {
    if (n1 > n2) return n1;
    else return n2;
}

int arvAltura(ARV* arv) {
    if (arv == NULL) return -1; // árvore vazia = retorna -1

    /* se não, retorna o maior valor entre:
        -> 1 + altura da filha (prim)
        -> altura da irmâ (prox) */
    else {
        return maiorSubArvore(1 + arvAltura(arv->esq), arvAltura(arv->dir));
    }
}

int arvPertence(char valor, ARV* arvore) {
    if (arvore == NULL) return 0;
    else return arvore->info == valor || arvPertence(valor, arvore->esq) || arvPertence(valor, arvore->esq);
}

void arvImprime(ARV* arvore) {
    // impressão em PRÉ-ORDEM (raiz -> sae -> sad)
    if(arvore != NULL) {
        printf("<");
        printf("%c ", arvore->info);
        arvImprime(arvore->esq);
        arvImprime(arvore->dir);
        printf(">");
    }
}

ARV* arvCriaNo(char valor, ARV* arvEsq, ARV* arvDir) {
    ARV* p = (ARV*) malloc(sizeof(ARV));
    p->info = valor;
    p->esq = arvEsq;
    p->dir = arvDir;
    return p;
}

ARV* arvCriaVazia() {
    return NULL;
}

// funções para ABB

ARV* abbPesquisa(int valor, ARV* arvore) {
    if (arvore != NULL) {
        if (valor < arvore->info) return abbPesquisa(valor, arvore->esq);
        else if (valor > arvore->info) return abbPesquisa(valor, arvore->dir);
        else return arvore;
    }
    return NULL;
}

void abbImprime(ARV* arvore) {
    // Impressão em ordem SIMÉTRICA (sae -> raiz -> sad)
    if(arvore != NULL) {
        abbImprime(arvore->esq);
        printf("<");
        printf("%c ", arvore->info);
        abbImprime(arvore->dir);
        printf(">");
    }
}

ARV* abbRemove(int valor, ARV* arvore) {
    if (arvore == NULL) return NULL;
    else if (valor > arvore->info) return abbRemove(valor, arvore->dir);
    else if (valor < arvore->info) return abbRemove(valor, arvore->esq);
    else {
        if (arvore->esq == NULL && arvore->dir == NULL) {
            free(arvore);
            arvore = NULL;
        }
        else if (arvore->esq == NULL) {
            ARV* aux = arvore;
            aux = aux->dir;             
            free(arvore);
        }
        else if (arvore->dir == NULL) {
            ARV* aux = arvore;
            aux = aux->esq;
            free(arvore);
        }
        else {
            ARV* aux = arvore->esq; 
            while (aux->dir != NULL) aux = aux-> dir; 
            arvore->info = aux->info; 
            aux->info = valor; 
            arvore->esq = abbRemove(valor, arvore->esq); 
        }
    }
    return arvore; 
}

ARV* abbInsere(int valor, ARV* arvore) {
    if (arvore != NULL) {
        if (arvore->info > valor) arvore->dir = abbInsere(valor, arvore->dir);
        else if (arvore->info < valor) arvore->esq = abbInsere(valor, arvore->esq);
    }
    ARV* aux = arvCriaNo(valor, NULL, NULL); 
    return aux;
}