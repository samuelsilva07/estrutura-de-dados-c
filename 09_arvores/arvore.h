#ifndef ARVORE_H
#define ARVORE_H

typedef struct arv ARV;

ARV* arvLibera(ARV* arvore);
int maiorSubArvore(int n1, int n2);
int arvAltura(ARV* arv);
int arvPertence(char valor, ARV* arvore);
int arvVazia(ARV* arvore);
void arvImprime(ARV* arvore);
ARV* arvCriaNo(char valor, ARV* arv_esq, ARV* arv_dir);
ARV* arvCriaVazia();

#endif