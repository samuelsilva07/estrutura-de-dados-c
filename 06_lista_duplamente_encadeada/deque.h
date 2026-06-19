#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct deque DEQUE;

void dequeLibera(DEQUE* lista);
DEQUE* dequePesquisa(DEQUE* lista, int num);
DEQUE* dequeFinal(DEQUE* lista);
int dequeVazio(DEQUE* lista);
DEQUE* dequeRemove(DEQUE* lista, int num);
void dequeImprimirReverso(DEQUE* lista);
void dequeImprimir(DEQUE* lista);
DEQUE* dequeInsereOrdenado(DEQUE* lista, int num);
DEQUE* dequeInsere(DEQUE* lista, int num);
DEQUE* dequeCria();

#endif