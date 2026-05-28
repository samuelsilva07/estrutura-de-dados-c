#include <stdio.h>
#include <stdlib.h>

// biblioteca com as funções para a manutenção de listas encadeadas simples

typedef struct lista LISTA;

void listaLibera(LISTA* lista);
LISTA* listaPesquisa(LISTA* lista, int num);
LISTA* listaRemove(LISTA* lista, int num);
void listaImprime(LISTA* lista);
LISTA* listaInsereOrdenado(LISTA* lista, int num);
LISTA* listaInsere(LISTA* lista, int num);
LISTA* listaCria();