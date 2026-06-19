#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

typedef struct lista {
    int valor;          // Valor armazenado pelo elemento
    struct lista* prox; // Ponteiro para o próximo elemento
};

void listaLibera(LISTA* lista) {  // Libera a memória utilizada para alocar a lista encadeada
    LISTA* aux = lista;     // inicia no ponteiro da lista
    while (aux != NULL) {   
        LISTA* temp = aux->prox;    // passagem de elemento
        free(aux);  
        aux = temp;   // esta ação faz com que a verificação de while seja feita no elemento atual                
    }
    // função chega ao fim quando chega ao último elemento (NULL)
}

void listaImprimeCiclo(LISTA* lista) {   // Imprime uma lista encadeada com ciclos
    LISTA* p = lista;
    printf("[");
    if (p) do { // do-while tsta APÓS O LOOP!! 
        printf("%d, ", p->valor);
        p = p->prox;
    } while (p != lista); // loop termina quando retornar ao elemento inicial
    printf("\b\b]\n");

}

int listaVerificaCiclo(LISTA* lista) {  // Verifica se a lista encadeada é um ciclo ou não 
    LISTA* ant = lista;             // variável com o elemento inicial
    LISTA* aux = lista->prox;       // variável com o elemento seguinte
    do {
        ant = ant->prox;            // avança um elemento 
        aux = aux->prox->prox;      // avança dois elementos
        
        if (aux == ant) return 1;   // verifica se eles são iguais
    } while(aux != NULL);           // se esta variável for nula, significa que o ciclo não existe
    
    return 0;                       // retorna 0 (falso)
}

LISTA* listaCriarCiclo(LISTA* lista) {     // Forma um ciclo na lista encadeada
    LISTA* p = lista; 
    // passa os elementos até que o próximo seja vazio
    while (p->prox != NULL) p = p->prox;
    p->prox = lista; // campo prox do ultimo elemento aponta para o início da lista
    return lista;
}

int listaPesquisa(LISTA* lista, int num) {   // Realiza uma busca linear na lista encadeada por um elemento n e retorna 1 caso o elemento seja encontrado
    for (LISTA* p = lista; p != NULL; p = p->prox)
        if (p->valor == num) return 1;
    return 0;
}

LISTA* listaRemove(LISTA* lista, int n) { // Remove um elemento de valor n da lista encadeada
    LISTA* anterior = NULL; // variável para o elemento anterior (inicia com NULL)
    LISTA* removido = lista; // variável para o elemento atual (inicia com o 1º da lista)

    while(removido != NULL && removido->valor != n) {
        ant = removido;
        removido = removido->prox;
    }

    // se o elemento não for encontrado, retorna a lista original
    if (removido == NULL) return lista;

    // se o elemento estiver no início da lista (anterior == NULL):
    if (anterior == NULL) lista = removido->prox;

    // se o elemento estiver no meio da lista:
    else anterior->prox = removido->prox;
    
    // remove o elemento e retorna a lista modificada
    free(removido);
    return lista;
} 

void listaImprime(LISTA* lista) { // Imprime a lista encadeada
    printf("[");
    for (LISTA* e = lista; e != NULL; e = e->prox)
        printf("%d, ", e->valor);
    printf("\b\b]\n");
}

LISTA* listaInsereOrdenado(LISTA* lista, int n) {     // Insere um elemento na lista encadeada, mas de forma ordenada
    LISTA* ant = NULL;
    LISTA* aux = lista;
    while (aux != NULL && aux->valor < n) {  // este loop encontra a posição do novo elemento, baseando-se na comparação dos valores
        ant = aux;
        aux = aux->prox;
    } 

    // cria novo elemento
    LISTA* novo = (LISTA*) malloc(sizeof(LISTA));
    novo->valor = n;
    
    if (ant == NULL) {
        novo->prox = lista;   // vetor no prox do elemento
        lista = novo;         // novo elemento se torna o início da lista
    }
    else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return lista;
}

LISTA* listaInsere(LISTA* lista, int n) {     // Insere um elemento na lista encadeada
    LISTA* novo_elemento = (LISTA*) malloc(sizeof(LISTA)); // aloca espaço para o novo elemento (struct)
    if (novo_elemento == NULL) { // fazer com todos!
        printf("Nao foi possivel alocar memoria para o elemento.\n");
        return lista;
    }

    novo_elemento->valor = n;
    novo_elemento->prox = lista; // endereço do vetor anterior para nova->prox
    
    return novo_elemento;  // retorna a lista com o novo elemento adicionado
}

LISTA* listaCria () {   // Cria uma lista encadeada vazia
    return NULL;
}