#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEDIA_TURMA 5

typedef struct lista {
    char nome[81];
    float media;
    struct lista* prox;
} Lista;

void liberarLista(Lista* lista) {
    Lista* atual = lista;
    Lista* aux;
    while(atual != NULL) {
        aux = atual->prox;
        free(atual);
        atual = aux;
    }
    printf("\nMemoria liberada!\n");
}

int aprovados(Lista* lista) {
    int qtd_aprovados = 0;
    for (Lista* aluno = lista; aluno != NULL; aluno = aluno->prox)
        if (aluno->media >= MEDIA_TURMA)
            qtd_aprovados++;
    return qtd_aprovados;
}

Lista* addAluno(Lista* lista, char* nome, float media) {
    Lista* aluno = (Lista*) malloc (sizeof(Lista));
    if (aluno == NULL) { 
        printf("Nao foi possivel alocar memoria para o aluno.\n");
        return lista;
    }
    strcpy(aluno->nome, nome);
    aluno->media = media;
    aluno->prox = lista;
    return aluno;
}

float obterMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2;
}

Lista* lerAlunos(FILE* arquivo) {
    Lista* lista_alunos = NULL;
    char nome_aluno[81];
    float nota1, nota2;
    printf("Leitura iniciada\n");
    while(!feof(arquivo)) {
        fscanf(arquivo, "%s %f %f\n", nome_aluno, &nota1, &nota2);
        lista_alunos = addAluno(lista_alunos, nome_aluno, obterMedia(nota1, nota2));
    }
    printf("Leitura finalizada\n");
    return lista_alunos;
}

FILE* abrirArquivo(char* nome_arquivo, char* modo) {
    FILE* arquivo = fopen(nome_arquivo, modo);
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }
    return arquivo;
}

int main() {
    FILE* arquivo_alunos = abrirArquivo("../alunos_turma.txt", "rt");
    Lista* lista_alunos = lerAlunos(arquivo_alunos);
    printf("A turma possui %d alunos aprovados.\n", aprovados(lista_alunos));
    liberarLista(lista_alunos);
    return 0;
}