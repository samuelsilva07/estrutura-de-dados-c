#include <stdio.h>
#include <stdlib.h>

typedef struct _array Array;

void freeArray(Array* list);
int getIndex(Array* list, int value);
int get(Array* list, int index);
void showArray(Array* list);
int delete(Array* list, int index);
void append(Array* list, int value);
Array* newArray();