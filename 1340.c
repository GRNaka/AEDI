#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

typedef struct {
    int dados[MAX];
    int ini, fim;
} Fila;

typedef struct {
    int dados[MAX];
    int tam;
} FilaPrioridade;

void push(Pilha *p, int x) {
    p->dados[++p->topo] = x;
}

int pop_pilha(Pilha *p) {
    if (p->topo < 0) return -1;
    return p->dados[p->topo--];
}

void push_fila(Fila *f, int x) {
    f->dados[f->fim++] = x;
}

int pop_fila(Fila *f) {
    if (f->ini == f->fim) return -1;
    return f->dados[f->ini++];
}

void push_fp(FilaPrioridade *fp, int x) {
    fp->dados[fp->tam++] = x;
}

int pop_fp(FilaPrioridade *fp) {
    if (fp->tam == 0) return -1;

    int maior = 0;
    for (int i = 1; i < fp->tam; i++) {
        if (fp->dados[i] > fp->dados[maior])
            maior = i;
    }

    int valor = fp->dados[maior];
    fp->tam--;
    fp->dados[maior] = fp->dados[fp->tam];
    return valor;
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {

        Pilha p; Fila f; FilaPrioridade fp;
        p.topo = -1;
        f.ini = f.fim = 0;
        fp.tam = 0;

        int podePilha = 1, podeFila = 1, podeFP = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                // Inserir
                push(&p, x);
                push_fila(&f, x);
                push_fp(&fp, x);
            } else {
                // Remover
                int v1 = pop_pilha(&p);
                int v2 = pop_fila(&f);
                int v3 = pop_fp(&fp);

                if (v1 != x) podePilha = 0;
                if (v2 != x) podeFila = 0;
                if (v3 != x) podeFP = 0;
            }
        }

        if (!podePilha && !podeFila && !podeFP)
            printf("impossible\n");
        else if ((podePilha + podeFila + podeFP) > 1)
            printf("not sure\n");
        else if (podePilha)
            printf("stack\n");
        else if (podeFila)
            printf("queue\n");
        else
            printf("priority queue\n");
    }

    return 0;
}
