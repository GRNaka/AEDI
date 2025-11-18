#include <stdio.h>

#define MAX 1024

char mapa[MAX][MAX];
int visitado[MAX][MAX];
int N, M;

// Movimentos: cima, baixo, esquerda, direita
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Estrutura simples de pilha (usando vetores)
typedef struct {
    int x, y;
} Ponto;

Ponto pilha[MAX * MAX];
int topo;

// Função DFS iterativa (sem recursão)
void dfs_iterativa(int startX, int startY) {
    topo = 0;
    pilha[topo].x = startX;
    pilha[topo].y = startY;
    topo++;

    visitado[startX][startY] = 1;

    while (topo > 0) {
        topo--;
        int x = pilha[topo].x;
        int y = pilha[topo].y;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visitado[nx][ny] && mapa[nx][ny] == '.') {
                    visitado[nx][ny] = 1;
                    pilha[topo].x = nx;
                    pilha[topo].y = ny;
                    topo++;
                }
            }
        }
    }
}

int main() {
    if (scanf("%d %d", &N, &M) != 2) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", mapa[i]);
    }

    int cliques = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mapa[i][j] == '.' && !visitado[i][j]) {
                dfs_iterativa(i, j);
                cliques++;
            }
        }
    }

    printf("%d\n", cliques);
    return 0;
}
