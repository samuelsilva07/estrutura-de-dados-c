#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} ARV;

ARV* arvLibera(ARV* arvore) {
    if (arvore != NULL) {
        arvLibera(arvore->esq);
        arvLibera(arvore->esq);
        free(arvore);
    }
    return NULL;
}

ARV* abbPesquisa(int valor, ARV* arvore) {
    if (arvore != NULL) {
        if (valor < arvore->info) return abbPesquisa(valor, arvore->esq);
        else if (valor > arvore->info) return abbPesquisa(valor, arvore->dir);
        else return arvore;
    }
    return NULL;
}

void abbImprime(ARV* arvore) {
    // em uma ABB, a impressão é em ordem SIMÉTRICA (sae -> raiz -> sad)
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
        // árvore sem sub-árvores: libera o nó e substitui por NULL
        if (arvore->esq == NULL || arvore->dir == NULL) {
            free(arvore);
            arvore = NULL;
        }

        // sub-árvores com um filho: raiz dessa árvore se torna o filho único de sua raiz
        else if (arvore->esq == NULL) {
            ARV* aux = arvore;
            aux = aux->dir; // aux->dir se torna o filho único
            free(arvore);
        }
        else if (arvore->dir == NULL) {
            ARV* aux = arvore;
            aux = aux->esq; // aux->esq se torna o filho único
            free(arvore);
        }

        // sub-árvores com dois filhos: troca com o elemento ANTECEDENTE na ordenação (elemento mais à direita da sub-árvore à esquerda)
        else {
            ARV* aux = arvore->esq; // inicia na sub-árvore esquerda
            while (aux->dir != NULL) aux = aux-> dir; // percorre até o elemento mais à direita da sub-árvore
            arvore->info = aux->info; // troca as informações dos nós
            aux->info = valor; // adiciona o valor a ser removido no nó que será removido
            arvore->esq = abbRemove(valor, arvore->esq); // remove o nó recursivamente, partindo da sub-árvore da esquerda
        }
    }
    return arvore; // retorna a árvore após as alterações
}

ARV* abbInsere(int valor, ARV* arvore) {
    // busca nó vazio (na posição correta na árvore), depois o cria e insere na árvore (ou sub-árvore)
    if (arvore != NULL) {
        // se o valor for maior, insere na sub-árvore da direita
        if (arvore->info > valor) arvore->dir = abbInsere(valor, arvore->dir);
    
        // se for menor, insere na da esquerda
        else if (arvore->info < valor) arvore->esq = abbInsere(valor, arvore->esq);
    }
    ARV* aux = arvCria(valor, NULL, NULL); // cria nó
    return aux;
}

ARV* arvCria(int valor, ARV* arvEsq, ARV* arvDir) {
    ARV* p = (ARV*) malloc(sizeof(ARV));
    p->info = valor;
    p->esq = arvEsq;
    p->dir = arvDir;
    return p;
}

ARV* arvCriaVazia() {
    return NULL;
}

int main () {
    ARV* a = criaVazia();
    a = arvLibera(a);
    printf("Arvore liberada!\n");
    return 0;
}