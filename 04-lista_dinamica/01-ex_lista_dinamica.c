#include <stdio.h>
#include "array.c"

int main() {
    ARRAY* lista_dinamica = arrayCria();
    
    arrayAdiciona(lista_dinamica, 2);
    arrayImprime(lista_dinamica);
    arrayAdiciona(lista_dinamica, 5);
    arrayImprime(lista_dinamica);
    arrayAdiciona(lista_dinamica, 3);
    arrayImprime(lista_dinamica);
    arrayAdiciona(lista_dinamica, 9);
    arrayImprime(lista_dinamica);
    arrayAdiciona(lista_dinamica, 8);

    arrayImprime(lista_dinamica);
    int indice_elemento = arrayPesquisa(lista_dinamica, 9);
    printf("Indice do elemento 9: %d\n", indice_elemento);

    int elemento_removido = arrayRemove(lista_dinamica, 2);
    printf("\nElemento %d removido!\n", elemento_removido);

    arrayLibera(lista_dinamica);
    return 0;
}