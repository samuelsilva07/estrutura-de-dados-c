#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    int horas_mes;
    float valor_hora;
    char nome[81];
} FUNCIONARIO;

FUNCIONARIO* busca(int inicio, int qtd_funcionarios, FUNCIONARIO* vetor_funcionarios, char* nome) {
    /* 
        - busca o funcionario com base no seu nome
        - no arquivo de exemplo, os funcionarios estão ordenados por ordem alfabética 
        - por isso, utilizei a busca binária para encontrar o funcionário de forma mais eficiente
    */
    int fim = qtd_funcionarios - 1;
    int meio = 0;
    do {
        meio = (inicio + fim) / 2;
        int comparador = strcmp(nome, vetor_funcionarios[meio].nome);
        if (comparador > 0) {
            inicio = meio;
        } if (comparador < 0) {
            fim = meio;
        } if (comparador == 0) {            
            return &vetor_funcionarios[meio];
        }
    } while(inicio <= meio);

    return NULL;
}

int main() {    
    system("cls");
    char* nome_arquivo = "../arquivo_funcionarios.txt";
    FILE* arquivo = fopen(nome_arquivo, "rt");

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    int qtd_funcionarios = 100;
    FUNCIONARIO* funcionarios = malloc(qtd_funcionarios * sizeof(FUNCIONARIO));
    if (funcionarios == NULL) {
        printf("Nao foi possivel alocar memoria para o vetor.\n");
        fclose(arquivo);
        return 1;
    }

    for (int i = 0; i < qtd_funcionarios; i++) {
        if (fscanf(arquivo, "%80s %f %d\n", funcionarios[i].nome, &funcionarios[i].valor_hora, &funcionarios[i].horas_mes) != 3) {
            printf("Erro ao ler os dados do arquivo.\n");
            free(funcionarios);
            fclose(arquivo);
            return 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("\n\nFuncionario %d", i);
        printf("\nNome: %s", funcionarios[i].nome);
        printf("\nValor-hora: %.2f",funcionarios[i].valor_hora);
        printf("\nHora-mes: %d",funcionarios[i].horas_mes);
    }

    char nome[81];
    printf("\nDigite o nome do funcionario para a busca: "); // verifique o arquivo de funcionários para realizar os testes!
    if (scanf("%80s", nome) != 1) {
        printf("Entrada inválida.\n");
        free(funcionarios);
        fclose(arquivo);
        return 1;
    }

    FUNCIONARIO* funcionario_encontrado = busca(0, qtd_funcionarios, funcionarios, nome);    

    if (funcionario_encontrado == NULL) {
        printf("O funcionario nao esta no arquivo.\n");
        free(funcionarios);
        fclose(arquivo);
        return 0;
    }

    printf("Funcionario encontrado!\n");
    printf("\nNome: %s", funcionario_encontrado->nome);
    printf("\nValor-hora: %.2f",funcionario_encontrado->valor_hora);
    printf("\nHora-mes: %d",funcionario_encontrado->horas_mes);

    free(funcionarios);
    fclose(arquivo);

    return 0;
}