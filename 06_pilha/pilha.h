typedef struct elemento ELEMENTO;
typedef struct pilha PILHA;

void pilhaLibera(PILHA* p);
void pilhaImprime(PILHA* p);
int pop(PILHA* p);
void push(PILHA* p, int n);
PILHA* pilhaCria();
