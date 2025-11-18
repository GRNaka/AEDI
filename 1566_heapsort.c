#include <stdio.h>
#include <stdlib.h>

void heapify(int *v, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    while (1) {
        if (l < n && v[l] > v[largest]) largest = l;
        if (r < n && v[r] > v[largest]) largest = r;

        if (largest != i) {
            int temp = v[i];
            v[i] = v[largest];
            v[largest] = temp;
            i = largest;
            l = 2*i + 1;
            r = 2*i + 2;
        } else break;
    }
}

void heapsort(int *v, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        heapify(v, i, 0);
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

        heapsort(v, N);

        for (int i = 0; i < N; i++)
            printf("%d%c", v[i], i == N-1 ? '\n' : ' ');

        free(v);
    }

    return 0;
}
