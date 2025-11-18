#include <stdio.h>
#include <stdlib.h>

void insertion(int *v, int n) {
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main() {
    int NC, N;
    scanf("%d", &NC);

    while (NC--) {
        scanf("%d", &N);
        int *v = malloc(N * sizeof(int));

        for (int i = 0; i < N; i++)
            scanf("%d", &v[i]);

        insertion(v, N);

        for (int i = 0; i < N; i++)
            printf("%d%c", v[i], i == N-1 ? '\n' : ' ');

        free(v);
    }
    return 0;
}
