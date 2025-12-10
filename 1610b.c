#include <stdio.h>

#define MAXN 100005

int head[MAXN], to[300005], next[300005], edge_id;
int state[MAXN];  // 0 = unvisited, 1 = visiting, 2 = visited
int found_cycle;

void init_graph(int n) {
    for (int i = 1; i <= n; i++)
        head[i] = -1, state[i] = 0;
    edge_id = 0;
    found_cycle = 0;
}

void add_edge(int u, int v) {
    to[edge_id] = v;
    next[edge_id] = head[u];
    head[u] = edge_id++;
}

void dfs(int u) {
    if (found_cycle) return;

    state[u] = 1;

    for (int e = head[u]; e != -1; e = next[e]) {
        int v = to[e];

        if (state[v] == 1) {          // ciclo encontrado
            found_cycle = 1;
            return;
        }
        if (state[v] == 0)
            dfs(v);
        if (found_cycle) return;
    }

    state[u] = 2;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        init_graph(N);

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            add_edge(A, B);
        }

        for (int i = 1; i <= N && !found_cycle; i++)
            if (state[i] == 0)
                dfs(i);

        if (found_cycle) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}
