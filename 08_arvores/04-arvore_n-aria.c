#include <stdio.h>
#include <stdlib.h>

typedef struct arvvar {
    char info;
    struct arvvar* prim; // primeiro filho (sub-árvore "esquerda")
    struct arvvar* prox; // irmão (sub-árvore "direita")
} ARVVAR;

static int maiorSubArvore(int n1, int n2) {
    // função retorna o maior dos dois valores das sub-árvores em questão
    // auxilia no cálculo de altura da árvore
    if (n1 > n2) return n1;
    else return n2;
}

int arvvAltura(ARVVAR* arv) {
    if (arv == NULL) return -1; // árvore vazia = retorna -1

    /* se não, retorna o maior valor entre:
        -> 1 + altura da filha (prim)
        -> altura da irmâ (prox) */
    else {
        return maiorSubArvore(1 + arvvAltura(arv->prim), arvvAltura(arv->prox));
    }
}

void arvvLibera(ARVVAR* arv) {      
    // libera em PÓS-ORDEM! (esq -> dir -> raiz)
    ARVVAR* temp = arv->prim; // inicia com os filhos da árvore
    while(temp != NULL) {
        ARVVAR* aux = temp->prox; 
        free(temp);
        temp = aux; // passa para a próxima sub-árvore
    }
    printf("Memoria liberada!\n");
    free(arv); // libera a raiz
}

int arvvPertence(ARVVAR* arv, char valor) {
    if (arv == NULL) return -1; // se a árvore for vazia, função retorna -1
    else if (arv->info == valor) return 1;
    else {
        ARVVAR* aux;
        for (aux = arv->prim; aux != NULL; aux = aux->prox)
            return arvvPertence(aux, valor);
    } 
    return 0;
}

void arvvImprime(ARVVAR* arv) {
    // impressão em PRÉ-ORDEM (raiz -> filha -> irmã)
    ARVVAR* aux;
    printf("<%c ", arv->info);
    for (aux = arv->prim; aux != NULL; aux = aux->prox) {
        printf("\n");
        arvvImprime(aux);  // impressão das sub-árvores filhas
    }
    printf(">");

}

ARVVAR* arvvInsere(ARVVAR* arv, ARVVAR* sub) {
    // sub-árvore é inserida como FILHA da arvore
    // inserção ocorre sempre no INÍCIO da lista
    sub->prox = arv->prim;
    arv->prim = sub;
    return arv;
}

ARVVAR* arvvCria(char c) {
    ARVVAR* a = (ARVVAR*) malloc(sizeof(ARVVAR));
    a->info = c;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

int main () {
    ARVVAR* arvore = arvvCria('a');
    printf("Arvore 1:\n");
    arvvImprime(arvore);
    printf("\nAltura da arvore = %d", arvvAltura(arvore));
    printf("\n\n");
    ARVVAR* subArvore1 = arvvCria('b');
    arvore->prim = subArvore1;    // insere primeiro filho da árvore
    printf("Arvore 2:\n");
    arvvImprime(arvore);
    printf("\nAltura da arvore = %d", arvvAltura(arvore));
    printf("\n\n");
    ARVVAR* subArvore2 = arvvCria('c');
    arvore->prim = arvvInsere(arvore->prim, subArvore2);  // primeiro irmão
    ARVVAR* subArvore3 = arvvCria('d');
    arvore->prim = arvvInsere(arvore->prim, subArvore3); // segundo irmão
    printf("Arvore 3:\n");
    arvvImprime(arvore);
    printf("\nAltura da arvore = %d", arvvAltura(arvore));
    printf("\n\n");
    printf("%d\n", arvvPertence(arvore, 'b'));
    printf("%d\n", arvvPertence(arvore, 'f'));
    arvvLibera(arvore);
    exit(EXIT_SUCCESS);
}