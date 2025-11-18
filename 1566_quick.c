#include <stdio.h>
#include <stdlib.h>

int partition(int *v, int l, int r) {
    int pivot = v[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
        if (v[j] <= pivot) {
            i++;
            int t = v[i]; v[i] = v[j]; v[j] = t;
        }

    int t = v[i + 1]; v[i + 1] = v[r]; v[r] = t;
    return i + 1;
}

void quicksort(int *v, int l, int r) {
    while (l < r) {
        int p = partition(v, l, r);

        if (p - 1 - l < r - (p + 1)) {
            quicksort(v, l, p - 1);
            l = p + 1;
        } else {
            quicksort(v, p + 1, r);
            r = p - 1;
        }
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

        quicksort(v, 0, N - 1);

        for (int i = 0; i < N; i++)
            printf("%d%c", v[i], i == N-1 ? '\n' : ' ');

        free(v);
    }

    return 0;
}
