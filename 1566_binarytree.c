#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    int quantidade;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->quantidade = 1;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    } else {
        raiz->quantidade++;
    }
    
    return raiz;
}

void percorrerEmOrdem(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda, primeiro);
        
        for (int i = 0; i < raiz->quantidade; i++) {
            if (!(*primeiro)) {
                printf(" ");
            }
            printf("%d", raiz->valor);
            *primeiro = 0;
        }
        
        percorrerEmOrdem(raiz->direita, primeiro);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int lerNumero() {
    int numero = 0;
    char caractere;
    
    while ((caractere = getchar()) == ' ' || caractere == '\n' || caractere == '\t');
    
    do {
        numero = numero * 10 + (caractere - '0');
    } while ((caractere = getchar()) >= '0' && caractere <= '9');
    
    return numero;
}

int main() {
    int casosTeste = lerNumero();
    
    for (int caso = 0; caso < casosTeste; caso++) {
        int quantidadePessoas = lerNumero();
        
        No* raiz = NULL;
        
        for (int i = 0; i < quantidadePessoas; i++) {
            int altura = lerNumero();
            raiz = inserir(raiz, altura);
        }
        
        int primeiro = 1;
        percorrerEmOrdem(raiz, &primeiro);
        printf("\n");
        
        liberarArvore(raiz);
    }
    
    return 0;
}
