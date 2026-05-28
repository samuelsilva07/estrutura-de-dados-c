#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

/* 
    Nesse programa, a pilha foi implementada para verificar se uma espressão numérica possui todos os símbolos utilizados corretamente.
    A pilha guarda os sinais que "abrem" e apenas os retira se seu fecho foi encontrado na posição correta.
     - Se a pilha estiver vazia no fim da verificação = a expressão está correta
     - Caso contrário = a expressão está incorreta 
 */

char fecho(char c) {
    if (c == '}') return '{';   
    else if (c == ']') return '[';
    else if (c == ')') return '(';
}

int verificaSinal(char c) {
    if (c == '(' || c == '[' || c == '{') return 1;
    if (c == ')' || c == ']' || c == '}') return -1;
    else return 0;
}

int verificaExpressao(char* exp) {
    PILHA* pilha = pilhaCria();
    for (int i = 0; exp[i] != '\0'; i++) {
        if (verificaSinal(exp[i]) == 1) push(pilha, exp[i]);
        if (verificaSinal(exp[i]) == -1) {
            if (pilha->topo == NULL || pop(pilha) != fecho(exp[i])){
                pilhaLibera(pilha);
                return 0;
            }
        }
    }
    if (pilha->topo != NULL) return 0;
    pilhaLibera(pilha);
    return 1;
}

int main () {
    char expressao[101];
    printf("Digite uma expressao matematica: ");
    fgets(expressao, 100, stdin);
    if (verificaExpressao(expressao)) printf("A expressao esta correta");
    else printf("A expressao esta incorreta");
    exit(EXIT_SUCCESS);
}