#ifndef ARVORE_BINARIA_BUSCA_H 
#define ARVORE_BINARIA_BUSCA_H 

typedef struct abb ABB;

ABB* abbLibera(ABB* arvore);
int maiorSubArvore(int n1, int n2);
int abbAltura(ABB* arv);
ABB* abbPesquisa(int valor, ABB* arvore);
int abbVazia(ABB* arvore);
void abbImprime(ABB* arvore);
ABB* abbRemove(int valor, ABB* arvore);
ABB* abbInsere(int valor, ABB* arvore);
ABB* abbCriaNo(int valor);
ABB* abbCriaVazia();

#endif
