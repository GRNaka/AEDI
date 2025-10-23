#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó da pilha
typedef struct No {
    char dado;
    struct No *prox;
} No;

// Função para empilhar (push)
void push(No **topo, char valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = *topo;
    *topo = novo;
}

// Função para desempilhar (pop)
void pop(No **topo) {
    if (*topo != NULL) {
        No *temp = *topo;
        *topo = temp->prox;
        free(temp);
    }
}

// Função para verificar se a pilha está vazia
int vazia(No *topo) {
    return topo == NULL;
}

// Função para liberar a pilha (caso ainda tenha nós)
void limpar(No **topo) {
    while (*topo != NULL) {
        pop(topo);
    }
}

int main() {
    char expr[1001];

    // Lê cada expressão até o fim do arquivo
    while (scanf("%s", expr) != EOF) {
        No *pilha = NULL;
        int i, correto = 1;

        for (i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '(') {
                push(&pilha, '(');
            } else if (expr[i] == ')') {
                if (vazia(pilha)) {
                    correto = 0;
                    break;
                } else {
                    pop(&pilha);
                }
            }
        }

        // Se a pilha não estiver vazia, ainda há '(' sem par
        if (!vazia(pilha))
            correto = 0;

        // Mostra o resultado
        if (correto)
            printf("correct\n");
        else
            printf("incorrect\n");

        limpar(&pilha); // libera a memória antes de processar a próxima linha
    }

    return 0;
}
