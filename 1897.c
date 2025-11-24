#include <stdio.h>
#include <string.h>

#define MAX_PLUS 100000
#define MIN_MINUS 10000
#define OFFSET MIN_MINUS

typedef struct {
    int val;
    int passos;
} Estado;

#define TOTAL_STATES (MAX_PLUS + MIN_MINUS + 1)

int visitado[TOTAL_STATES];
Estado fila[300000];
int ini, fim;

int bfs(int n, int m) {
    ini = fim = 0;
    memset(visitado, 0, sizeof(visitado));

    fila[fim++] = (Estado){n, 0};
    visitado[n + OFFSET] = 1;

    while (ini < fim) {
        Estado cur = fila[ini++];

        if (cur.val == m)
            return cur.passos;

        int candidatos[6];
        candidatos[0] = cur.val * 2;
        candidatos[1] = cur.val * 3;
        candidatos[2] = cur.val / 2;
        candidatos[3] = cur.val / 3;
        candidatos[4] = cur.val + 7;
        candidatos[5] = cur.val - 7;

        for (int i = 0; i < 6; i++) {
            int v = candidatos[i];
            if (v < -MIN_MINUS || v > MAX_PLUS)
                continue;
            if (!visitado[v + OFFSET]) {
                visitado[v + OFFSET] = 1;
                fila[fim++] = (Estado){v, cur.passos + 1};
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        printf("%d\n", bfs(n, m));
    }
    return 0;
}
