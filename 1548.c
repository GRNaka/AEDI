#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return y - x; // ordem decrescente
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M;
        scanf("%d", &M);

        int original[1001], sorted[1001];

        for (int i = 0; i < M; i++) {
            scanf("%d", &original[i]);
            sorted[i] = original[i];
        }

        qsort(sorted, M, sizeof(int), cmp_desc);

        int count = 0;
        for (int i = 0; i < M; i++)
            if (original[i] == sorted[i])
                count++;

        printf("%d\n", count);
    }

    return 0;
}
