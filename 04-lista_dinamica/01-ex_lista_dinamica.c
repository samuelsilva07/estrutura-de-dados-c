#include <stdio.h>
#include "array.c"

int main() {
    Array* array = newArray();
    
    append(array, 2);
    showArray(array);
    append(array, 5);
    showArray(array);
    append(array, 3);
    showArray(array);
    append(array, 9);
    showArray(array);
    append(array, 8);

    showArray(array);
    int indice_elemento = get(array, 9);
    printf("Indice do elemento 9: %d\n", indice_elemento);

    int elemento_removido = del(array, 2);
    printf("\nElemento %d removido!\n", elemento_removido);

    freeArray(array);
    return 0;
}