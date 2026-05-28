#define TAMANHO_MAX 127
typedef int Heap[TAMANHO_MAX];

int divInt(int num1, int num2);
int heapVazia(int quantidade);
int heapCheia(int quantidade);
void heapImprime(int* heap, int quantidade);
int heapRemove(int* heap, int* quantidade);
void heapInsere(int* heap, int* quantidade, int valor);