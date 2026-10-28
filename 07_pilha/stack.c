#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// biblioteca com as funções para a manutenção de pilhas 
// LIFO (Last In, First Out)

typedef struct _element {
    int info;
    struct _element* next;
} Element;

typedef struct _stack {
    Element* top;
} Stack;

void freeStack(Stack* stack) {
    Element* element = stack->top;
    Element* next_element;
    while(element != NULL) {
        next_element = element->next;
        free(element);
        element = next_element;
    }
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void showFirst(Stack* stack) {     // Imprime o elemento que está no topo da pilha
    if (!isEmpty(stack)) printf("%d\n", stack->top->info);
}

void showStack(Stack* stack) {   // Imprime a pilha na sequência correta
    printf("[");
    if (isEmpty(stack)) {  // se a pilha estiver vazia, não imprime os elementos 
        printf("]\n");
        return;
    }

    Element* element = (Element*) malloc(sizeof(Element)); // criação de um elemento temporário para a impressão
    for (element = stack->top; element != NULL; element = element->next)
        printf("%d ", element->info);
        
    printf("\b]\n");
}

int pop(Stack* stack) {    // Retira o elemento do topo da pilha
    Element* deleted = (Element*) malloc(sizeof(Element));
    int value;
    deleted = stack->top;    // variável elemento_removido recebe o elemento do topo da pilha
    value = deleted->info;         // valor recebe o dado de retorno

    stack->top = deleted->next;   // topo da pilha é reajustado 
    free(deleted);
    return value;       // função retorna o valor do elemento removido
}

void push(Stack* stack, int value) {   // Adiciona um elemento ao topo da pilha
    Element* element = (Element*) malloc(sizeof(Element));
    element->info = value;
    element->next = stack->top;  // adiciona o elemento antes do topo
    stack->top = element;        // novo elemento se torna o topo
}

Stack* newStack() {    // Cria uma pilha vazia
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->top = NULL;     // topo da pilha inicia com NULL
    return new_stack;
}