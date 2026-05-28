#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        free(aux);
        aux = p;
    }
}

void imprimeListaFiguras(LISTA* lista) {
    if (lista != NULL) {
        LISTA* figura;
        int i = 1;
            printf("----------------------------");
            for (figura = lista; figura != NULL; figura = figura->prox) {
                printf("\nFigura %d:\n - Tipo: %s\n", i, figura->tipo);
                if (strcmp(figura->tipo, "RET")) {
                    RETANGULO* medidas = (RETANGULO*) figura->info;
                    printf(" - Base = %.2fm\n - Altura = %.2fm\n", medidas->base, medidas->altura);
                }
                else if (strcmp(figura->tipo, "TRI")) {
                    TRIANGULO* medidas = (TRIANGULO*) figura->info;
                    printf(" - Base = %.2fm\n - Altura = %.2fm\n", medidas->base, medidas->altura);
                }
                else if(strcmp(figura->tipo, "CIR")) {
                    CIRCULO* medidas = (CIRCULO*) figura->info;
                    printf(" - Raio = %.2fm\n", medidas->raio);
                }
                i++;
            }
            printf("----------------------------");
    }
}

LISTA* alocaFigura(char figuraChar, LISTA* listaFiguras) {
    LISTA* figura = (LISTA*) malloc(sizeof(LISTA));
    if (figuraChar == 'T' || figuraChar == 't') {
        strcpy(figura->tipo, "TRI");
        TRIANGULO* medidas = alocaTriangulo();
        figura->info = (void*) medidas; 
    }
    else if (figuraChar == 'R' || figuraChar == 'r') {
        strcpy(figura->tipo, "RET");
        RETANGULO* medidas = alocaRetangulo();
        figura->info = (void*) medidas; 
    }
    else if (figuraChar == 'C' || figuraChar == 'c') {
        strcpy(figura->tipo, "CIR");
        CIRCULO* medidas = alocaCirculo();
        figura->info = (void*) medidas; 
    }
    figura->prox = listaFiguras;
    return figura;
}

LISTA* criaLista() {
    return NULL;
}

int main (void) {
    LISTA* listaFiguras = criaLista();
    int quantidade;
    printf("Digite a quantidade de figuras que serao inseridas na lista:\n");
    scanf("%d", &quantidade);
    char figura;
    for (int i = 0; i < quantidade; i++) {
        getchar();
        printf("\nT = Triangulo\nR = Retangulo\nC = Circulo\nN = nenhum\n\nDigite o caractere da figura que deseja alocar: ");
        scanf("%c", &figura);
        if (figura == 'N' && figura == 'n') break;
        else listaFiguras = alocaFigura(figura, listaFiguras);
    }
    printf("\nFim da manutencao da lista!\n");
    printf("Lista final:\n");
    imprimeListaFiguras(listaFiguras);
    liberaLista(listaFiguras);
    printf("\nFim do programa.\n");
    exit(EXIT_SUCCESS);
}