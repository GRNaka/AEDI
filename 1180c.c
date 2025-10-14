#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    if (!v) return 1;

    for (int i = 0; i < n; i++)
        scanf("%d", v + i);

    int menor = *v;
    int pos = 0;

    for (int i = 1; i < n; i++) {
        int atual = *(v + i);
        if (atual < menor) {
            menor = atual;
            pos = i;
        }
    }

    printf("Menor valor: %d\nPosicao: %d\n", menor, pos);

    free(v);
    return 0;
}
