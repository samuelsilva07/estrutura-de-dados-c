typedef struct arv ARV;

ARV* arvLibera(ARV* arvore);
int maiorSubArvore(int n1, int n2);
int arvAltura(ARV* arv);
int arvPertence(char valor, ARV* arvore);
void arvImprime(ARV* arvore);
ARV* arvCriaNo(char valor, ARV* arvEsq, ARV* arvDir);
ARV* arvCriaVazia();

ARV* abbPesquisa(int valor, ARV* arvore);
void abbImprime(ARV* arvore);
ARV* abbRemove(int valor, ARV* arvore);
ARV* abbInsere(int valor, ARV* arvore);