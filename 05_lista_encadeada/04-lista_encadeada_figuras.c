#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
    Este programa consiste em uma aplicação de lista encadeada, utilizando figuras geométricas.
     
     - Informe o número de figuras que sua lista deve conter
     - Escolha o tipo da figura que será adicionada
     - Informe as dimensões da figura

    Ao finalizar a coleta de informações, o programa imprime as figuras na tela (a partir da ultima figura informada até a primeira - a implementação foi realizada com uma lista encadeada!)

*/

typedef struct circulo {
    float raio;
} CIRCULO;

typedef struct retangulo {
    float base;
    float altura;
} RETANGULO;

typedef struct triangulo {
    float base;
    float altura;
} TRIANGULO;

typedef struct lista {
    void* info;     
    // a utilização do tipo void* no struct é fundamental nesse programa, pois assim a lista pode armazenar informações de qualquer figura - necesitando apenas de uma boa manipulação e conversão de tipos
    char tipo[4];
    struct lista* prox;
} LISTA;

CIRCULO* alocaCirculo() {
    CIRCULO* cir = (CIRCULO*) malloc(sizeof(CIRCULO));
    float raio;

    printf("Digite o raio do circulo:\n");
    scanf("%f", &raio);
    cir->raio = raio;
    return cir;
}

RETANGULO* alocaRetangulo() {
    RETANGULO* ret = (RETANGULO*) malloc(sizeof(RETANGULO));
    float base, altura;

    printf("Digite a base e a altura do retangulo:\n");
    scanf("%f %f", &base, &altura);
    ret->base = base;
    ret->altura = altura;
    return ret;
}

TRIANGULO* alocaTriangulo() {
    TRIANGULO* tri = (TRIANGULO*) malloc(sizeof(TRIANGULO));
    float base, altura;

    printf("Digite a base e a altura do triangulo:\n");
    scanf("%f %f", &base, &altura);
    tri->base = base;
    tri->altura = altura;
    return tri;
}

void liberaLista(LISTA* lista) {
    LISTA* aux = lista;
    while(aux != NULL) {
        LISTA* p = aux->prox;
        free(aux->info);
        free(aux);
        aux = p;
    }
}

void imprimeListaFiguras(LISTA* lista) {
    if (lista != NULL) {
        printf("Lista:\n");
        LISTA* figura;
        int i = 1;
            printf("----------------------------");
            for (figura = lista; figura != NULL; figura = figura->prox) {
                printf("\nFigura %d:\n - Tipo: %s\n", i, figura->tipo);
                if (strcmp(figura->tipo, "RET") == 0) {
                    RETANGULO* medidas = (RETANGULO*) figura->info;
                    printf(" - Base = %.2fm\n - Altura = %.2fm\n", medidas->base, medidas->altura);
                }
                else if (strcmp(figura->tipo, "TRI") == 0) {
                    TRIANGULO* medidas = (TRIANGULO*) figura->info;
                    printf(" - Base = %.2fm\n - Altura = %.2fm\n", medidas->base, medidas->altura);
                }
                else if(strcmp(figura->tipo, "CIR") == 0) {
                    CIRCULO* medidas = (CIRCULO*) figura->info;
                    printf(" - Raio = %.2fm\n", medidas->raio);
                }
                i++;
            }
            printf("----------------------------");
    }
}

LISTA* alocaFigura(char figura_char, LISTA* lista_figuras) {
    LISTA* figura = (LISTA*) malloc(sizeof(LISTA));
    if (figura_char == 'T' || figura_char == 't') {
        strcpy(figura->tipo, "TRI");
        TRIANGULO* medidas = alocaTriangulo();
        figura->info = (void*) medidas; 
    }
    else if (figura_char == 'R' || figura_char == 'r') {
        strcpy(figura->tipo, "RET");
        RETANGULO* medidas = alocaRetangulo();
        figura->info = (void*) medidas; 
    }
    else if (figura_char == 'C' || figura_char == 'c') {
        strcpy(figura->tipo, "CIR");
        CIRCULO* medidas = alocaCirculo();
        figura->info = (void*) medidas; 
    }
    figura->prox = lista_figuras;
    
    system("cls");
    printf("\nFigura alocada com sucesso!");
    sleep(2);
    return figura;
}

int verificaListaVazia(LISTA* lista) {
    return lista == NULL;
}

LISTA* criaLista() {
    return NULL;
}

int main (void) {
    system("cls");
    LISTA* lista_figuras = criaLista();
    int quantidade;
    printf("Digite a quantidade de figuras que serao inseridas na lista:\n");
    
    if(scanf("%d", &quantidade) != 1) {
        printf("Entrada inválida.\n");
        return 0;
    }
    
    if (quantidade > 0) {
        char figura;
        for (int i = 0; i < quantidade; i++) {
            getchar();
            system("cls");
            printf("T = Triangulo\nR = Retangulo\nC = Circulo\nN = nenhum\n\nDigite o caractere da figura que deseja alocar: ");
            
            if(scanf("%c", &figura) != 1) {
                printf("Entrada inválida.\n");
                return 0;
            }

            if (figura == 'N' || figura == 'n') break;
            else lista_figuras = alocaFigura(figura, lista_figuras);
        }
    }

    system("cls");
    printf("\nFim da manutencao da lista!\n");
    if (verificaListaVazia(lista_figuras)) {
        printf("A lista esta vazia.\n");
    } else {
        imprimeListaFiguras(lista_figuras);
    }
    sleep(3);

    liberaLista(lista_figuras);
    printf("\nFim do programa.\n");
    exit(EXIT_SUCCESS);
}