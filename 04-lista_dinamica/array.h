#include <stdio.h>
#include <stdlib.h>

typedef struct _array Array;

void freeArray(Array* lista);
int get(Array* lista, int elemento);
void showArray(Array* lista);
int del(Array* lista, int posicao);
void append(Array* lista, int valor);
Array* newArray();