#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

// biblioteca com as funções para a manutenção de listas encadeadas simples

typedef struct _linked_list LinkedList;

void freeLinkedList(LinkedList* list);
void showCycleList(LinkedList* list);
int checkCycle(LinkedList* list);
LinkedList* addCycle(LinkedList* list);
int checkValue(LinkedList* list, int value);
LinkedList* delete(LinkedList* list, int value);
void showLinkedList(LinkedList* list);
LinkedList* addInOrder(LinkedList* list, int value);
LinkedList* add(LinkedList* list, int value);
LinkedList* newLinkedList();

#endif