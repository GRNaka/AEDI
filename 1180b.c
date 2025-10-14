#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int v[n];
    int *ptr = v;

    for (int i = 0; i < n; i++)
        scanf("%d", ptr + i);

    int menor = *ptr;
    int indice = 0;

    for (int i = 1; i < n; i++) {
        int atual = *(ptr + i);
        if (atual < menor) {
            menor = atual;
            indice = i;
        }
    }

    printf("Menor valor: %d\nPosicao: %d\n", menor, indice);

    return 0;
}
