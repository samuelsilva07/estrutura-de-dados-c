#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente {
    char nome[50];
    char servico[50];
    struct cliente* proximo;
} Cliente;

typedef struct fila {
    Cliente* inicio;
    Cliente* fim;
} Fila;

void freeQueue(Fila* fila) {
    Cliente* atual = fila->inicio;
    Cliente* aux;
    while(atual != NULL) {
        aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    printf("\nMemoria liberada!");
}

int isEmpty(Fila* fila) {
    return fila->inicio == NULL;
}

void printCliente(Cliente* cliente) {
    printf("Nome: %s\nServico: %s\n", cliente->nome, cliente->servico);
}

void printQueue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("\nA fila esta vazia.\n");
        return;
    }
    int i = 1;
    printf("\n");
    for (Cliente* cliente = fila->inicio; cliente != NULL; cliente = cliente->proximo) {
        printf("Cliente %d\n---------------------------\n", i);
        printCliente(cliente);
        i++;
    }
}

void dequeue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("\nA fila esta vazia.\n");
        return;
    }

    Cliente* cliente_removido = fila->inicio;
    fila->inicio = cliente_removido->proximo;
    printf("Um cliente foi atendido!\n");
    printCliente(cliente_removido);

    if (fila->inicio == NULL) fila->fim = NULL;
    free(cliente_removido);
}

void enqueue(Fila* fila, char* nome, char* servico) {
    Cliente* novo_cliente = (Cliente*) malloc(sizeof(Cliente));
    strcpy(novo_cliente->nome, nome);
    strcpy(novo_cliente->servico, servico);
    novo_cliente->proximo = NULL;

    if (isEmpty(fila)) {
        fila->inicio = novo_cliente;
    } else {
        fila->fim->proximo = novo_cliente;
    }

    fila->fim = novo_cliente;
}

void addCliente(Fila* fila) {
    char nome[50], servico[50];
    printf("Digite o nome do cliente: ");
    getchar();
    // fgets(nome, 49, stdin);
    scanf("%s", nome);
    getchar();
    printf("Informe o servico solicitado (deposito, saque ou abrir conta): ");
    fgets(servico, 50, stdin);
    enqueue(fila, nome, servico);
    printf("Cliente adicionado com sucesso!\n");
}

Fila* criarFila() {
    Fila* nova_fila = (Fila*) malloc(sizeof(Fila));
    nova_fila->inicio = nova_fila->fim = NULL;
    return nova_fila;
}

int realizarOperacao(int operacao, Fila* fila) {
    switch(operacao) {
        case 0: 
            freeQueue(fila);
            return 0;
        case 1: 
            addCliente(fila);
            break;
        case 2: 
            dequeue(fila);
            break;
        case 3: 
            printQueue(fila);
            break;
        default: 
            printf("\nOperacao invalida, digite um numero entre 0 e 3.\n\n");
            break;
    }
    return 1;
}

void menu() {
    printf("\n      CENTRAL DE ATENDIMENTO      \n---------------------------------\n");
    printf("1 - Adicionar cliente\n2 - Atender cliente\n3 - Exibir clientes\n0 - Sair\n\n");
}

int main() {
    Fila* fila_clientes = criarFila();
    system("cls");
    int operacao;
    while (1) {
        menu();
        printf("Operacao: ");
        scanf("%d", &operacao);
        if (realizarOperacao(operacao, fila_clientes) == 0) {
            printf("\nFim do progama.\n");
            return 0;
        }
    }
}