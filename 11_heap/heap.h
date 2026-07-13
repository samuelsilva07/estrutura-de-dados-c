#ifndef HEAP_H 
#define HEAP_H 
#define TAMANHO_MAX 127

typedef struct heap HEAP;

void heapLibera(HEAP* heap);
int divInt(int num1, int num2);
int heapVazia(HEAP* heap);
int heapCheia(HEAP* heap);
void heapImprime(HEAP* heap);
int heapRemove(HEAP* heap);
void heapInsere(HEAP* heap, int valor);
HEAP* heapCria();

#endif