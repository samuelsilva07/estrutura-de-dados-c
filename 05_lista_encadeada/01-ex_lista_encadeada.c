#include <stdio.h>
#include "lista_encadeada.c"

int main () {
    LISTA* lista_encadeada = listaCria();
    int num;
    for (int i = 0; i < 5; i++) {
        printf("Digite um numero para adicionar a lista: ");
        scanf("%d", &num);
        // lista_encadeada = listaInsere(lista_encadeada, num);
        lista_encadeada = listaInsereOrdenado(lista_encadeada, num);
    }
    listaImprime(lista_encadeada);
    lista_encadeada = listaRemove(lista_encadeada, 5);
    listaImprime(lista_encadeada);

    // BUSCA DE ELEMENTO
    printf("Numero a ser procurado: ");
    scanf("%d", &num);
    if (listaPesquisa(lista_encadeada, num)) {
        printf("O elemento esta na lista.\n");
    } else {
        printf("O elemento nao esta na lista.\n");
    }
    
    listaLibera(lista_encadeada);    
    exit(EXIT_SUCCESS);
}