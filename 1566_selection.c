#include <stdio.h>
#include <stdlib.h>

void selection(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min]) min = j;

        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
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

        selection(v, N);

        for (int i = 0; i < N; i++)
            printf("%d%c", v[i], i == N-1 ? '\n' : ' ');

        free(v);
    }
    return 0;
}
