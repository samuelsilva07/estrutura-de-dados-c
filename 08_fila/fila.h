#ifndef FILA_H
#define FILA_H

typedef struct elemento ELEMENTO;
typedef struct fila FILA;

void filaLibera(FILA* fila);
int filaVazia(FILA* fila);
void filaImprime(FILA* fila);
int filaRemove(FILA* fila);
void filaInsere(FILA* fila, int n);
FILA* filaCria();

#endif