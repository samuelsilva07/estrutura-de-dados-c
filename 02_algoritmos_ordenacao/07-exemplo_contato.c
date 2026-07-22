#include <stdio.h>
#include <stdlib.h>
#define MAIS_VELHO 1
#define MESMO_DIA 0
#define MAIS_NOVO -1

typedef struct contato {
    int dia;
    int mes;
    int ano;
    char nome[81];
    char telefone[21];
} Contato;

void liberarVetor(int quantidade_contatos, Contato** vetor_contatos) {
    for (int i = 0; i < quantidade_contatos; i++) 
        free(vetor_contatos[i]);
    free(vetor_contatos);
}

int comparaDia(Contato* pessoa1, Contato* pessoa2) {
    if (pessoa1->dia > pessoa2->dia) return MAIS_VELHO;
    if (pessoa1->dia < pessoa2->dia) return MAIS_NOVO;
    return MESMO_DIA;
}

int comparaMes(Contato* pessoa1, Contato* pessoa2) {
    if (pessoa1->mes > pessoa2->mes) return MAIS_VELHO;
    if (pessoa1->mes < pessoa2->mes) return MAIS_NOVO;
    return comparaDia(pessoa1, pessoa2);
}

int comparaAno(Contato* pessoa1, Contato* pessoa2) {
    if (pessoa1->ano > pessoa2->ano) return MAIS_VELHO;
    if (pessoa1->ano < pessoa2->ano) return MAIS_NOVO;
    return comparaMes(pessoa1, pessoa2);
}

int comparaDataNascimento(Contato* pessoa1, Contato* pessoa2) {
    return comparaAno(pessoa1, pessoa2);
}

void bolha(Contato** vetor, int i) { 
    Contato* temp = vetor[i];
    vetor[i] = vetor[i + 1];
    vetor[i + 1] = temp;
}

void ordena(int quantidade_contatos, Contato** vetor_contatos) { 
    // neste exemplo, utilizei o algoritmo de Insertion Sort
    for (int i = 1; i < quantidade_contatos; i++) {
        int j = i; 
        while (j > 0 && comparaDataNascimento(vetor_contatos[j - 1], vetor_contatos[j]) == MAIS_VELHO) {
            bolha(vetor_contatos, j - 1);
            j--;  
        } 
    }
} 

void gerarArquivoOrdenado(int quantidade_contatos, Contato** vetor_contatos) {
    ordena(100, vetor_contatos);
    FILE* novo_arquivo = fopen("../contatos_ordenados.txt", "wt");
    if (!novo_arquivo) {
        printf("Erro na leitura do arquivo.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < quantidade_contatos; i++) 
        fprintf(novo_arquivo, "%s %s %d %d %d\n", 
            vetor_contatos[i]->nome, 
            vetor_contatos[i]->telefone, 
            vetor_contatos[i]->dia, 
            vetor_contatos[i]->mes, 
            vetor_contatos[i]->ano
        );
    fclose(novo_arquivo);
}

void imprimirContato(Contato* contato) {
    printf("%s %s %d %d %d\n", 
            contato->nome, 
            contato->telefone, 
            contato->dia, 
            contato->mes, 
            contato->ano
    );
}

void carregarContatos(char* nomeArquivo, Contato** vetor_contatos, int quantidade_contatos) {
    FILE* arquivo = fopen(nomeArquivo, "rt");
    if (!arquivo) {
        printf("Erro na leitura do arquivo.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < quantidade_contatos; i++) {
        if (fscanf(arquivo, "%80s %20s %d %d %d\n", 
            vetor_contatos[i]->nome, 
            vetor_contatos[i]->telefone, 
            &vetor_contatos[i]->dia, 
            &vetor_contatos[i]->mes, 
            &vetor_contatos[i]->ano) != 5
        ) {
            printf("Erro ao ler os dados do arquivo.\n");
            liberarVetor(i, vetor_contatos);
            fclose(arquivo);
            exit(EXIT_FAILURE);
        }
        // imprimirContato(vetor_contatos[i]);
    }
    
    fclose(arquivo);
}

void alocarContatos(int quantidade, Contato** vetor) {
    for (int i = 0; i < quantidade; i++) {
        vetor[i] = (Contato*) malloc(sizeof(Contato));
        if (!vetor[i]) {
            printf("Nao foi possivel alocar memoria para o contato.\n");
            liberarVetor(i, vetor);
            exit(EXIT_FAILURE);
        }
    }
} 

Contato** criarVetor(int quantidade) {
    Contato** vetor = (Contato**) malloc(quantidade * sizeof(Contato*));

    if (!vetor) {
        printf("Nao foi possivel alocar memoria para o vetor.\n");
        free(vetor);
        exit(EXIT_FAILURE);
    }
    
    alocarContatos(quantidade, vetor);
    return vetor;
}

int main() {
    Contato** vetor_contatos = criarVetor(100); 
    printf("Vetor inicializado.\n");

    carregarContatos("../contatos.txt", vetor_contatos, 100);
    printf("Leitura do arquivo concluida.\n");

    gerarArquivoOrdenado(100, vetor_contatos);
    printf("O novo arquivo foi gerado!\n");

    liberarVetor(100, vetor_contatos);
}