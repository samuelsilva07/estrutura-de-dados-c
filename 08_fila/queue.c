#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// biblioteca com as funções para a manutenção de filas 
// FIFO (First In, First Out)

typedef struct _element {
    int info;
    struct _element* next;
} Element;

typedef struct _queue {
    Element* first;
    Element* last;
} Queue;

void freeQueue(Queue* queue) {
    Element* element = queue->first;
    Element* next_element;
    while(element != NULL) {
        next_element = element->next;
        free(element);
        element = next_element;
    }
}

int isEmpty(Queue* fila){
    return fila->first == NULL;
}

void showLast(Queue* queue) {
    if (!isEmpty(queue)) printf("%d\n", queue->last->info);
}

void showFirst(Queue* queue) {
    if (!isEmpty(queue)) printf("%d\n", queue->first->info);
}

void showQueue(Queue* queue) {
    Element* element = (Element*) malloc(sizeof(Element));
    printf("[");
    for (element = queue->first; element != NULL; element = element->next)
        printf("%d ", element->info);
    if (!isEmpty(queue)) printf("\b");
    printf("]\n");
}

int dequeue(Queue* queue) {
    Element* removed = queue->first;
    int value = removed->info;
    queue->first = removed->next;
    if (queue->first == NULL) queue->last = NULL;  // caso da fila vazia
    free(removed);
    return value;
}

void enqueue(Queue* queue, int value) {
    // fila = ORDEM INVERSA!!
    Element* element = (Element*) malloc(sizeof(Element));
    element->info = value;
    element->next = NULL;  // adiciona o elemento antes do inicio

    if (queue->first != NULL) {
        queue->last->next = element;
    }
    // se a fila estiver vazia, o elemento é o início e o last da fila
    else queue->first = element;

    queue->last = element;
}

Queue* newQueue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->first = new_queue->last = NULL;    // inicio e last da fila inicializados com NULL
    return new_queue;
}