#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_busca.h"

struct abb {
    int valor;
    struct abb* esq;
    struct abb* dir;
};

ABB* abbLibera(ABB* arvore) {
    if (!abbVazia(arvore)) {
        // recursão para liberar os ramos
        abbLibera(arvore->esq);
        abbLibera(arvore->dir);
        free(arvore);
    }
    return NULL;
}

int maiorSubArvore(int n1, int n2) {
    return (n1 > n2) ? n1 : n2;
}

int abbAltura(ABB* arvore) {  // Retorna a altura da árvore
    if (abbVazia(arvore)) return 0; // árvore vazia = retorna 0
    return 1 + maiorSubArvore(abbAltura(arvore->esq), abbAltura(arvore->dir));
    
}

ABB* abbPesquisa(ABB* arvore, int valor) { // Verifica se um valor está na árvore binária de busca
    if (!abbVazia(arvore)) {
        if (valor < arvore->valor) return abbPesquisa(arvore->esq, valor);
        else if (valor > arvore->valor) return abbPesquisa(arvore->dir, valor);
        else return arvore;
    }
    return NULL;
}

int abbVazia(ABB* arvore) {  // Retorna 1 se a árvore está vazia e 0 caso contrário
    return arvore == NULL;
}

void abbImprime(ABB* arvore) { // Imprime os valores da árvore binária de busca em ordem simétrica (sae -> raiz -> sad)
    if(!abbVazia(arvore)) {
        printf("<");
        abbImprime(arvore->esq);
        printf("%d ", arvore->valor);
        abbImprime(arvore->dir);
        printf(">");
    }
}

ABB* abbRemove(ABB* arvore, int valor) {  // Remove um elemento da árvore binária de busca
    if (abbVazia(arvore)) return NULL;
    else if (valor > arvore->valor) arvore->dir = abbRemove(arvore->dir, valor);
    else if (valor < arvore->valor) arvore->esq = abbRemove(arvore->esq, valor);
    else if (valor == arvore->valor) {
        // árvore sem sub-árvores: libera o nó e substitui por NULL
        if (abbVazia(arvore->esq) && abbVazia(arvore->dir)) {
            free(arvore);
            arvore = NULL;
        }

        // sub-árvores com um filho: raiz dessa árvore se torna o filho único de sua raiz
        else if (abbVazia(arvore->esq)) {
            ABB* aux = arvore;
            arvore = arvore->dir; // arvore->dir se torna o filho único
            free(aux);
        }
        else if (abbVazia(arvore->dir)) {
            ABB* aux = arvore;
            arvore = arvore->esq; // arvore->esq se torna o filho único
            free(aux);
        }

        // sub-árvores com dois filhos: troca com o elemento ANTECEDENTE na ordenação (elemento mais à direita da sub-árvore à esquerda)
        else {
            ABB* aux = arvore->esq; // inicia na sub-árvore esquerda
            while (aux->dir != NULL) aux = aux-> dir; // percorre até o elemento mais à direita da sub-árvore
            arvore->valor = aux->valor; // troca as informações dos nós
            aux->valor = valor; // adiciona o valor a ser removido no nó que será removido
            arvore->esq = abbRemove(arvore->esq, valor); // remove o nó recursivamente, partindo da sub-árvore da esquerda
        }
    }

    return arvore; // retorna a árvore após as alterações
}

ABB* abbInsere(ABB* arvore, int valor) {    // Insere um elemento na árvore binária de busca, na posição correta.
    // busca nó vazio (na posição correta na árvore), depois o cria e insere na árvore (ou sub-árvore)
    if (abbVazia(arvore)) {
        return abbCriaNo(valor);
    }

    // se o valor for menor, insere na sub-árvore da esquerda
    else if (valor < arvore->valor)  arvore->esq = abbInsere(arvore->esq, valor);

    // se for maior, insere na sub-árvore da direita
    else if (valor > arvore->valor) arvore->dir = abbInsere(arvore->dir, valor);

    // caso ele seja igual, apresenta uma mensagem de erro - as ABBs não aceitam elementos duplicados
    else printf("Este valor ja esta na arvore.\n");

    return arvore;
}

ABB* abbCriaNo(int valor) {  // cria um nó da árvore com o seu respectivo valor
    ABB* no = (ABB*) malloc(sizeof(ABB));
    no->valor = valor;
    no->esq = no->dir = NULL;
    return no;
}

ABB* abbCriaVazia() {  // cria uma árvore vazia
    return NULL;
}