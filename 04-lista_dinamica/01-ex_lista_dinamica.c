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
    int elemento = get(array, 0);
    printf("Valor de indice 0: %d\n", elemento);

    int elemento_removido = delete(array, 2);
    printf("\nO valor %d (indice 2) foi removido!\n", elemento_removido);
    showArray(array);

    freeArray(array);
    return 0;
}