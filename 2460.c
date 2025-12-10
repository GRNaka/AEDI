#include <stdio.h>

#define MAXID 100001

int removed[MAXID];

int main() {
    int N, M;
    
    while (scanf("%d", &N) != EOF) {

        for (int i = 0; i < MAXID; i++)
            removed[i] = 0;

        int fila[50005];

        for (int i = 0; i < N; i++)
            scanf("%d", &fila[i]);

        scanf("%d", &M);

        for (int i = 0; i < M; i++) {
            int x;
            scanf("%d", &x);
            removed[x] = 1;
        }

        int first = 1;
        for (int i = 0; i < N; i++) {
            if (!removed[fila[i]]) {
                if (!first) printf(" ");
                printf("%d", fila[i]);
                first = 0;
            }
        }

        printf("\n");
    }

    return 0;
}
