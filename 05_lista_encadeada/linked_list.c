#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct _linked_list {
    int value;          // Valor armazenado pelo elemento
    struct _linked_list* next; // Ponteiro para o próximo elemento
};

LinkedList* breakCycle(LinkedList* list) {
    if (list == NULL) return NULL;

    LinkedList* node = list;
    do {
        node = node->next;
    } while (node->next != list);

    node->next = NULL;
    return list;
}

void showCycleList(LinkedList* list) {   // Imprime uma lista encadeada com ciclos
    LinkedList* node = list;
    printf("[");
    if (node != NULL) do { // do-while tsta APÓS O LOOP!! 
        printf("%d, ", node->value);
        node = node->next;
    } while (node != list); // loop termina quando retornar ao elemento inicial
    printf("\b\b]\n");
}

int checkCycle(LinkedList* list) {  // Verifica se a lista encadeada é um ciclo ou não 
    if (list == NULL) return 0;
    
    LinkedList* previous_node = list;       // variável com o elemento inicial
    LinkedList* node = list->next;          // variável com o elemento seguinte
    if (node == NULL) return 0;

    do {
        previous_node = previous_node->next;    // avança um elemento 
        node = node->next->next;                // avança dois elementos
        
        // se os ponteiros apontarem para o mesmo local, a lista possui um ciclo
        if (node == previous_node) return 1;   
        
        // se os próximos valores forem NULL, não há ciclo
        else if (node == NULL || node->next == NULL) return 0; 
    } while (node != NULL);           
    
    // se node for NULL, significa que o ciclo não existe e retorna 0    
    return 0;
}

LinkedList* addCycle(LinkedList* list) {     // Forma um ciclo na lista encadeada
    LinkedList* node = list; 
    // passa os elementos até que o próximo seja vazio
    while (node->next != NULL) node = node->next;
    node->next = list; // campo next do ultimo elemento aponta para o início da lista
    return list;
}

void freeLinkedList(LinkedList* list) {  // Libera a memória utilizada para alocar a lista encadeada
    if (list == NULL) return;

    if (checkCycle(list) == 1) list = breakCycle(list);  // verifica se a lista possui um ciclo e quebra-o

     LinkedList* node = list;        // inicia no ponteiro
    LinkedList* temp_node;
    
    while (node != NULL) {   
        temp_node = node->next;    // passagem de elemento
        free(node);  
        node = temp_node;   // esta ação faz com que a verificação de while seja feita no elemento atual                
    }
    // função chega ao fim quando chega ao último elemento (NULL)
}

int checkValue(LinkedList* lista, int value) {   // Realiza uma busca linear na lista encadeada por um elemento n e retorna 1 caso o elemento seja encontrado
    for (LinkedList* node = lista; node != NULL; node = node->next)
        if (node->value == value) return 1;
    return 0;
}

LinkedList* delete(LinkedList* list, int n) { // Remove um elemento de valor n da lista encadeada
    LinkedList* previous_node = NULL; // variável para o elemento previous_nodeerior (inicia com NULL)
    LinkedList* deleted_node = list; // variável para o elemento atual (inicia com o 1º da lista)

    while(deleted_node != NULL && deleted_node->value != n) {
        previous_node = deleted_node;
        deleted_node = deleted_node->next;
    }

    // se o elemento não for encontrado, retorna a lista original
    if (deleted_node == NULL) return list;

    // se o elemento estiver no início da lista (previous_nodeerior == NULL):
    if (previous_node == NULL) list = deleted_node->next;

    // se o elemento estiver no meio da lista:
    else previous_node->next = deleted_node->next;
    
    // remove o elemento e retorna a lista modificada
    free(deleted_node);
    return list;
} 

void showLinkedList(LinkedList* list) { // Imprime a lista encadeada
    printf("[");
    for (LinkedList* e = list; e != NULL; e = e->next)
        printf("%d, ", e->value);
    printf("\b\b]\n");
}

LinkedList* addInOrder(LinkedList* list, int value) {     // Insere um elemento na lista encadeada, mas de forma ordenada
    LinkedList* previous_node = NULL;
    LinkedList* node = list;
    while (node != NULL && node->value < value) {  // este loop encontra a posição do novo elemento, baseando-se na comparação dos valores
        previous_node = node;
        node = node->next;
    } 

    // cria novo elemento
    LinkedList* new_node = (LinkedList*) malloc(sizeof(LinkedList));
    new_node->value = value;
    
    if (previous_node == NULL) {
        new_node->next = list;   // vetor no next do elemento
        list = new_node;         // novo elemento se torna o início da lista
    }
    else {
        new_node->next = previous_node->next;
        previous_node->next = new_node;
    }
    return list;
}

LinkedList* add(LinkedList* list, int value) {     // Insere um elemento na lista encadeada
    LinkedList* new_node = (LinkedList*) malloc(sizeof(LinkedList)); // aloca espaço para o novo elemento (struct)
    if (new_node == NULL) { // fazer com todos!
        printf("Nao foi possivel alocar memoria para o elemento.\n");
        return list;
    }

    new_node->value = value;
    new_node->next = list; // endereço do vetor previous_nodeerior para nova->next
    
    return new_node;  // retorna a lista com o novo elemento adicionado
}

LinkedList* newLinkedList() {   // Cria uma lista encadeada vazia
    return NULL;
}