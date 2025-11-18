#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *temp, int left, int mid, int right) {
    int i = left, j = mid, k = left;

    while (i < mid && j < right)
        temp[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];

    while (i < mid) temp[k++] = v[i++];
    while (j < right) temp[k++] = v[j++];

    for (i = left; i < right; i++)
        v[i] = temp[i];
}

void mergesort(int *v, int n) {
    int *temp = malloc(n * sizeof(int));

    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size;
            int right = left + 2*size;

            if (mid > n) mid = n;
            if (right > n) right = n;

            merge(v, temp, left, mid, right);
        }
    }

    free(temp);
}

int main() {
    int NC, N;
    scanf("%d", &NC);

    while (NC--) {
        scanf("%d", &N);

        int *v = malloc(N * sizeof(int));

        for (int i = 0; i < N; i++)
            scanf("%d", &v[i]);

        mergesort(v, N);

        for (int i = 0; i < N; i++)
            printf("%d%c", v[i], i == N-1 ? '\n' : ' ');

        free(v);
    }
    return 0;
}
