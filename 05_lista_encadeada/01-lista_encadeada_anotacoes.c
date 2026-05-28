#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista* prox; // ponteiro para o próximo elemento
} LISTA;

LISTA* criaLista (void) {
    return NULL;
}

void liberaLista(LISTA* vet) {
    LISTA* aux = vet;
    while (aux != NULL) {
        LISTA* temp = aux->prox;
        free(aux);
        aux = temp;
    }
    // função chega ao fim quando chega ao último elemento (NULL)
}

LISTA* insercaoOrdenadaLista(LISTA* vet, int n) {
    LISTA* ant = NULL;
    LISTA* aux = vet;
    while (aux != NULL && aux->valor < n) {
        ant = aux;
        aux = aux->prox;
    } 

    // cria novo elemento
    LISTA* novo = (LISTA*) malloc(sizeof(LISTA));
    novo->valor = n;

    if (ant == NULL) {
        novo->prox = vet;   // vetor no prox do elemento
        vet = novo;         // novo elemento se torna o início da lista
    }
    else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return vet;
}

LISTA* insercaoLista(LISTA* vet, int n) {
    LISTA* nova = (LISTA*) malloc(sizeof(LISTA)); // aloca espaço para o novo elemento (struct)
    nova->valor = n;
    nova->prox = vet; // endereço do vetor anterior para nova->prox
    return nova;
}

LISTA* removeElementoLista(LISTA* vet, int n) {
    LISTA* ant = NULL; // variável para o elemento anterior (inicia com NULL)
    LISTA* aux = vet; // variável para o elemento atual (inicia com o 1º da lista)

    while(aux != NULL && aux->valor != n) {
        ant = aux;
        aux = aux->prox;
    }

    // se o elemento não for encontrado, retorna a lista original
    if (aux == NULL) return vet;

    // se o elemento estiver no início da lista (anterior == NULL):
    if (ant == NULL) vet = aux->prox;

    // se o elemento estiver no meio da lista:
    else ant->prox = aux->prox;
    
    //remove o elemento e retorna a lista modificada
    free(aux);
    return vet;
}

void imprimeLista(LISTA* vet) {
    for (LISTA* e = vet; e != NULL; e = e->prox)
        printf("%d ", e->valor);
    printf("\n");
}

LISTA* pesquisaLista(LISTA* vet, int n) {
    LISTA* p;
    for (p = vet; p != NULL; p = p->prox) 
        if (p->valor == n) return p; 
    return NULL;
}

int main (void) {
    LISTA* vetor = criaLista();
    int num;
    for (int i = 0; i < 5; i++) {
        printf("Digite um numero para adicionar a lista: ");
        scanf("%d", &num);
        // vetor = insercaoLista(vetor, num);
        vetor = insercaoOrdenadaLista(vetor, num);
    }
    imprimeLista(vetor);
    // vetor = removeElementoLista(vetor, 5);
    // imprimeLista(vetor);

    // BUSCA DE ELEMENTO
    // printf("Numero a ser procurado: ");
    // scanf("%d", &num);
    // LISTA* achou = pesquisaLista(vetor, num);
    // printf("%d", achou->valor);

    liberaLista(vetor);    
    exit(EXIT_SUCCESS);
}