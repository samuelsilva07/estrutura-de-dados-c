#include <stdio.h>
#include <string.h>
#include "heap.c"

void menu(){
    printf("\nFILA DE PRIORIDADE\n------------------------------------\n");
    printf("1 - adicionar cliente | 2 - atender cliente | 3 - visualizar fila | 0 - Sair\n");
    printf("\nOperacao: "); 
}

char* obterTipoAtendimento(int valor) {
    switch (valor) {
        case 1: return "urgencia baixa";
        case 2: return "urgencia media";
        case 3: return "urgencia alta";
        default: return "";
    }
}

int informarTipoAtendimento() {
    int valor;
    printf("1 - urgencia baixa\n2 - urgencia media\n3 - urgencia alta\n");
    printf("Selecione o seu nivel de urgencia: ");
    scanf("%d", &valor);
    return valor;
}

void realizarOperacao(HEAP* fila, int operacao) {
    switch (operacao) {
        case 1:
            if (heapCheia(fila)) {
                printf("A fila esta cheia!\n");
                break;
            }
            int prioridade = informarTipoAtendimento();
            heapInsere(fila, prioridade);
            printf("Cliente adicionado com sucesso!\n");
            break;
        case 2:
            if (heapVazia(fila)) {
                printf("A fila esta vazia!\n");
                break;
            }
            int valor_removido = heapRemove(fila);
            char* tipo_atendimento = obterTipoAtendimento(valor_removido);
            printf("Cliente de %s foi atendido!\n", tipo_atendimento);
            break;
        case 3:
            printf("Fila atual: ");
            heapImprime(fila);
            printf("Obs: 1 - urgencia baixa | 2 - urgencia media | 3 - urgencia alta\n");
            break;
        default:
            printf("Entrada invalida, digite um numero entre 0 a 3.\n");
            break;
    }
}

int main() {
    HEAP* fila_prioridade = heapCria();
    int operacao;
    system("cls");
    while (1) {
        menu();
        scanf("%d", &operacao);
        system("cls");
        if (operacao == 0) {
            printf("Fim do programa.\n");
            heapLibera(fila_prioridade);
            return 0;
        }

        realizarOperacao(fila_prioridade, operacao);
    }
}
