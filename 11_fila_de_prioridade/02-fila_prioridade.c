#include <stdio.h>
#include "heap.c"

int main() {
    Heap fila_prioridade;
    int operacao, senha = 0;
    int quantidade_clientes = 0;
    system("cls");
    while (1) {
        printf("\nFILA DE PRIORIDADE\n------------------------------------\n");
        printf("1 - adicionar cliente | 2 - atender cliente | 3 - visualizar fila | 0 - Sair\n");
        printf("\nOperacao: ");
        scanf("%d", &operacao);
        switch (operacao) {
            case 0:
                printf("Fim do programa.\n");
                exit(1);
            case 1:
                system("cls");
                if (heapCheia(quantidade_clientes)) {
                    printf("A fila esta cheia!\n");
                    break;
                }
                senha++;
                heapInsere(fila_prioridade, &quantidade_clientes, senha);
                printf("Cliente adicionado com sucesso!\n");
                break;
            case 2:
                system("cls");
                if (heapVazia(quantidade_clientes)) {
                    printf("A fila esta vazia!\n");
                    break;
                }
                int senha_removido = heapRemove(fila_prioridade, &quantidade_clientes);
                printf("Cliente %d atendido com sucesso!\n", senha_removido);
                break;
            case 3:
                system("cls");
                printf("Fila atual: ");
                heapImprime(fila_prioridade, quantidade_clientes);
                break;
            default:
                system("cls");
                printf("Entrada invalida, digite um numero entre 0 a 3.\n");
                break;
        }
    }
}
