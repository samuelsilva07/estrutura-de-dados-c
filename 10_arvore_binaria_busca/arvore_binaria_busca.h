#ifndef ARVORE_BINARIA_BUSCA_H 
#define ARVORE_BINARIA_BUSCA_H 

typedef struct abb ABB;

ABB* abbLibera(ABB* arvore);
int maiorSubArvore(int n1, int n2);
int abbAltura(ABB* arvore);
ABB* abbPesquisa(ABB* arvore, int valor);
int abbVazia(ABB* arvore);
void abbImprime(ABB* arvore);
ABB* abbRemove(ABB* arvore, int valor);
ABB* abbInsere(ABB* arvore, int valor);
ABB* abbCriaNo(int valor);
ABB* abbCriaVazia();

#endif
