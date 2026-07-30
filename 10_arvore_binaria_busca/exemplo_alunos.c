#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define ARVORE_VAZIA NULL

typedef struct arv {
    char mat[21];
    char nome[81];
    char email[41];
    struct arv* esq;
    struct arv* dir;
} Arv;

int arvVazia(Arv* arvore) {
    return arvore == NULL;
}

Arv* arvLibera(Arv* arvore) {
    if (!arvVazia(arvore)) {
        arvLibera(arvore->dir);
        arvLibera(arvore->esq);
        free(arvore);
    }
    return NULL;
}

void imprimirAluno(Arv* aluno) {
    printf("Nome: %s\nEmail: %s\nMatricula: %s\n-----------------------------\n", aluno->nome, aluno->email, aluno->mat);
}

void visualizarAlunos(Arv* arvore) {
    if(!arvVazia(arvore)) {
        visualizarAlunos(arvore->esq);
        imprimirAluno(arvore);
        visualizarAlunos(arvore->dir);
    }
}

Arv* criarAluno(char* nome, char* email, char* mat) {
    Arv* novo_aluno = (Arv*) malloc(sizeof(Arv));
    if (novo_aluno == NULL) {
        printf("Nao foi possivel alocar memoria.\n");
        return NULL;
    }

    strcpy(novo_aluno->nome, nome);
    strcpy(novo_aluno->email, email);
    strcpy(novo_aluno->mat, mat);
    novo_aluno->dir = novo_aluno->esq = NULL;
    return novo_aluno;
}

Arv* inserirAluno(Arv* arvore, char* nome, char* email, char* mat) {
    if (arvVazia(arvore)) return criarAluno(nome, email, mat);

    else if (strcmp(nome, arvore->nome) < 0) arvore->esq = inserirAluno(arvore->esq, nome, email, mat);    
    else if (strcmp(nome, arvore->nome) > 0) arvore->dir = inserirAluno(arvore->dir, nome, email, mat);    
    else printf("Este aluno ja foi adicionado.\n");
    
    return arvore;
}

Arv* addAluno(Arv* arvore) {
    char nome[81], email[41], matricula[21];
    printf("Nome do aluno(a): ");
    scanf("%80s", nome);
    printf("Email do aluno(a): ");
    scanf("%40s", email);
    printf("Matricula do aluno(a): ");
    scanf("%20s", matricula);
    return inserirAluno(arvore, nome, email, matricula);
}

Arv* arvCria() {
    return NULL;
}

Arv* realizarOperacao(int operacao, Arv* alunos) {
    system("cls");
    switch(operacao) {
        case 0:
            alunos = arvLibera(alunos);
            break;
        case 1:
            alunos = addAluno(alunos);
            printf("\nAluno adicionado com sucesso!");
            sleep(2);
            system("cls");
            break;
        case 2:
            if (arvVazia(alunos)) {
                printf("Nenhum aluno foi registrado.\n");
                sleep(2);
                system("cls");
            } else {
                printf("       ALUNOS DA TURMA       \n");
                printf("-----------------------------\n");
                visualizarAlunos(alunos);
                printf("Pressione [ENTER] para continuar");
                getchar();
            }
            break;
        default:
            printf("Valor invalido, digite um numero entre 0 e 2.\n");
            break;
    }
    return alunos;
}

void menu() {
    printf("   GERENCIAMENTO DE ALUNOS   \n");
    printf("-----------------------------\n");
    printf("1 - Inserir aluno(a)\n2 - Visualizar alunos\n0 - Sair\n");
    printf("\nOperacao: ");
}

int main() {
    Arv* alunos = arvCria();
    int operacao;
    system("cls");
    while(1) {
        menu();
        scanf("%d", &operacao);
        alunos = realizarOperacao(operacao, alunos);
        if (alunos == ARVORE_VAZIA) {
            printf("Fim do programa.\n");
            return 0;
        }
    }
}