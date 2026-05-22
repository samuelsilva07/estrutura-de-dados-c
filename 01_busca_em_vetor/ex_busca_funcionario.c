#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct funcionario2 {
    char nome[81];
    float valor_hora;
    int horas_mes;
} FUNCIONARIO;

FUNCIONARIO* busca(int inicio, int fim, FUNCIONARIO* vetorFuncionarios, char* nome) { 
    /* 
        - busca o funcionario com base no seu nome
        - no arquivo de exemplo, os funcionarios estão ordenados por ordem alfabética 
        - por isso, utilizei a busca binária recursiva para realizar a busca de forma mais eficiente
    */
    int meio = ((int) (inicio + fim) / 2);
    int comparador = strcmp(nome, vetorFuncionarios[meio].nome);
    if (comparador == 0) return &vetorFuncionarios[meio];
    for (int i = 0; nome[i] != '\0'; i++) {
        if (comparador > 0) return busca(meio + 1, fim, vetorFuncionarios, nome);
        else if (comparador < 0) return busca(inicio, meio - 1, vetorFuncionarios, nome);
    }
    return NULL;
}

int main () {
    char* nome_arquivo = "arquivo_funcionarios.txt";
    FILE* arquivo_funcionarios = fopen(nome_arquivo, "rt");
    if (arquivo_funcionarios == NULL) return 0;

    int qtdFuncionarios = 10;
    FUNCIONARIO* funcionarios = (FUNCIONARIO*) malloc(qtdFuncionarios*sizeof(FUNCIONARIO));

    for(int i = 0; i < qtdFuncionarios; i++) {
        fscanf(arquivo_funcionarios, "%s,%f,%d", funcionarios[i].nome, &funcionarios[i].valor_hora, &funcionarios[i].horas_mes);
    }

    char nome[81];
    printf("Digite o nome do funcionario: ");
    scanf("%s", nome);
    FUNCIONARIO* funcionarioBusca = busca(0, qtdFuncionarios - 1, funcionarios, nome);

    if (funcionarioBusca != NULL) {
        printf("Funcionario encontrado!\n\n");
        printf("Nome: %s\n", funcionarioBusca->nome);
        printf("Valor-hora: %.2f\n", funcionarioBusca->valor_hora);
        printf("Horas-mes: %d\n", funcionarioBusca->horas_mes);
    } else {
        printf("Funcionario nao encontrado.");
    }

    free(funcionarios);
    fclose(arquivo_funcionarios);

    return 0;
}