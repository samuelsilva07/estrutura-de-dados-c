#include <stdio.h>
#include <stdlib.h>

typedef struct _array ARRAY;

void freeArray(ARRAY* lista);
int get(ARRAY* lista, int elemento);
void showArray(ARRAY* lista);
int del(ARRAY* lista, int posicao);
void append(ARRAY* lista, int valor);
ARRAY* newArray();