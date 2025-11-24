#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, Q, x, caso = 1;
    
    while (scanf("%d %d", &N, &Q) == 2 && N && Q) {
        int marmores[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &marmores[i]);
        }

        // Ordenar os mármores
        qsort(marmores, N, sizeof(int), cmp);

        printf("CASE# %d:\n", caso++);
        
        for (int i = 0; i < Q; i++) {
            scanf("%d", &x);
            // Busca binária
            int l = 0, r = N - 1, pos = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (marmores[m] == x) {
                    pos = m;
                    r = m - 1; // continua procurando à esquerda
                } else if (marmores[m] < x) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (pos == -1)
                printf("%d not found\n", x);
            else
                printf("%d found at %d\n", x, pos + 1);
        }
    }
    return 0;
}
