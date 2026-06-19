#ifndef PILHA_H
#define PILHA_H

typedef struct elemento ELEMENTO;
typedef struct pilha PILHA;

void pilhaLibera(PILHA* p);
int pilhaVazia(PILHA* p);
ELEMENTO* pilhaTopo(PILHA* p);
void pilhaImprime(PILHA* p);
int pilhaPop(PILHA* p);
void pilhaPush(PILHA* p, int n);
PILHA* pilhaCria();

#endif