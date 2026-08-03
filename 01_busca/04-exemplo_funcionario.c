#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    int horas_mes;
    float valor_hora;
    char nome[81];
} FUNCIONARIO;

void imprimirFuncionario(FUNCIONARIO* funcionario) {
    printf("\nNome: %s", funcionario->nome);
    printf("\nValor-hora: %.2f",funcionario->valor_hora);
    printf("\nHora-mes: %d",funcionario->horas_mes);
}

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
        } else if (comparador < 0) {
            fim = meio;
        } else {            
            return &vetor_funcionarios[meio];
        }
    } while (inicio <= meio);

    return NULL;
}

void buscarFuncionario(FUNCIONARIO* funcionarios, int qtd_funcionarios, char* nome) {
    FUNCIONARIO* funcionario_encontrado = busca(0, qtd_funcionarios, funcionarios, nome); 
    if (funcionario_encontrado == NULL) {
        printf("O funcionario nao esta no arquivo.\n");
        free(funcionarios);
        exit(EXIT_FAILURE);
    } 
    printf("Funcionario encontrado!\n");
    imprimirFuncionario(funcionario_encontrado);
}

char* informarNome() {
    static char nome[41];
    printf("Digite o nome do funcionario para a busca: "); // verifique o arquivo de funcionários para realizar os testes!
    if (scanf("%40s", nome) != 1) {
        printf("Entrada inválida.\n");
        exit(EXIT_FAILURE);
    }
    return nome;
}

void lerArquivo(FILE* arquivo, FUNCIONARIO* funcionarios, int qtd_funcionarios) {
    for (int i = 0; i < qtd_funcionarios; i++) {
        if (fscanf(arquivo, "%80s %f %d\n", funcionarios[i].nome, &funcionarios[i].valor_hora, &funcionarios[i].horas_mes) != 3) {
            printf("Erro ao ler os dados do arquivo.\n");
            free(funcionarios);
            fclose(arquivo);
            exit(EXIT_FAILURE);
        }
    }
}

FUNCIONARIO* gerarVetor(int qtd_funcionarios) {
    FUNCIONARIO* vetor = malloc(qtd_funcionarios * sizeof(FUNCIONARIO));
    if (vetor == NULL) {
        printf("Nao foi possivel alocar memoria para o vetor.\n");
        free(vetor);
        exit(EXIT_FAILURE);
    }
    return vetor;
}

FILE* abrirArquivo(char* nome_arquivo, char* modo) {
    FILE* arquivo = fopen(nome_arquivo, modo);
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    return arquivo;
}

int main() {    
    system("cls");
    FILE* arquivo = abrirArquivo("../arquivo_funcionarios.txt", "rt");
    printf("Leitura do arquivo concluida!\n");

    int qtd_funcionarios = 100;
    FUNCIONARIO* funcionarios = gerarVetor(qtd_funcionarios);

    lerArquivo(arquivo, funcionarios, qtd_funcionarios);

    char* nome = informarNome();
    buscarFuncionario(funcionarios, qtd_funcionarios, nome);    

    free(funcionarios);
    fclose(arquivo);

    exit(EXIT_SUCCESS);
}