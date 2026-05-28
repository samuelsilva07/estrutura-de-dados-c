#include <stdio.h>
#include <stdlib.h>

typedef struct array ARRAY;

void arrayLibera(ARRAY* lista);
int arrayPesquisa(ARRAY* lista, int elemento);
void arrayImprime(ARRAY* lista);
int arrayRemove(ARRAY* lista, int posicao);
void arrayAdiciona(ARRAY* lista, int valor);
ARRAY* arrayCria();