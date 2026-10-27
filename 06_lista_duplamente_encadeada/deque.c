#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

typedef struct deque {
    int value;
    struct deque* previous;  // ponteiro para o elemento anterior
    struct deque* next; // ponteiro para o próximo elemento
} Deque;

void freeDeque(Deque* list) {  // Libera a memória utilizada para alocar a lista duplamente encadeada
    Deque* node = list;
    Deque* next_node = NULL;
    while (node != NULL) {
        next_node = node->next;
        free(node);          // libera a memória do elemento
        node = next_node;      // atual recebe o próximo elemento a ser liberado
    }
}

Deque* getLast(Deque* list) {
    if (list == NULL) return NULL;
    Deque* node = list;
    while(node->next != NULL) node = node->next;
    return node;
}

Deque* get(Deque* list, int value) {   // Realiza uma busca linear na lista duplamente encadeada por um elemento de valor n e o retorna caso seja encontrado
    for (Deque* node = list; node != NULL; node = node->next) {
        if (node->value == value) return node;
    }
    return NULL;
}

int isEmpty(Deque* list) {
    return list == NULL;
}

Deque* delete(Deque* list, int value) {   // Remove um elemento de valor n da lista duplamente encadeada
    Deque* deleted_node = get(list, value);
    
    if (deleted_node == NULL) return list;

    if (deleted_node->previous != NULL) deleted_node->previous->next = deleted_node->next;
    
    else list = deleted_node->next;

    if (deleted_node->next != NULL) deleted_node->next->previous = deleted_node->previous;

    free(deleted_node);
    return list;
}

void showReverseDeque(Deque* list) { // Imprime a lista duplamente encadeada na ordem reversa
    printf("[");
    for (Deque* node = getLast(list); node != NULL; node = node->previous)
        printf("%d, ", node->value);
    printf("\b\b]\n");
}

void showDeque(Deque* list) {   // Imprime a lista duplamente encadeada
    printf("[");
    for (Deque* node = list; node != NULL; node = node->next)
        printf("%d, ", node->value);
    printf("\b\b]\n");
}

Deque* addInOrder(Deque* list, int num) {     // Insere um elemento na lista encadeada, mas de forma ordenada
    Deque* node = list;
    Deque* previous_node = NULL;

    while (node != NULL && node->value < num) {
        previous_node = node;
        node = node->next;
    }

    Deque* new_node = (Deque*) malloc(sizeof(Deque));
    new_node->value = num;
    
    // se o novo elemento não está no final da lista, é preciso conectar apenas o elemento atual - pois ele não é NULL
    if (node != NULL) node->previous = new_node;  // conecta apenas o elemento atual

    // caso o novo elemento não esteja no início da lista, então é preciso conectar apenas o elemento anterior - pela mesma razão
    if (previous_node != NULL) previous_node->next = new_node;
            
    new_node->next = node;     // elemento ou NULL (se estiver no final da lista)
    new_node->previous = previous_node;   // elemento ou NULL (se estiver no começo da lista)

    // caso o novo elemento seja o início da lista, o ponteiro da lista vai para ele
    if (new_node->previous == NULL) list = new_node;    

    return list;   
}

Deque* add(Deque* list, int value) { // Insere um elemento na lista duplamente encadeada
    Deque* new_node = (Deque*) malloc(sizeof(Deque));
    new_node->value = value;
    new_node->next = list; // se a lista for vazia, aponta para NULL
    new_node->previous = NULL;

    // criação do "caminho de volta" (se a lista não for vazia)
    if (list != NULL) list->previous = new_node;
    return new_node;
}

Deque* newDeque () {   // Cria uma lista duplamente encadeada vazia
    return NULL;
}