typedef struct elemento ELEMENTO;
typedef struct fila FILA;

void filaLibera(FILA* fila);
void filaImprime(FILA* fila);
int filaRemove(FILA* fila);
void filaInsere(FILA* fila, int n);
FILA* filaCria();