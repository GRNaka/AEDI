#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n <= 0) scanf("%d", &n);

    for (int k = 1; k <= n; k++) {
        int **mat = malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++)
            mat[i] = malloc(9 * sizeof(int));

        int valido = 1;

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &mat[i][j]);

        for (int i = 0; i < 9 && valido; i++) {
            int *cont = calloc(10, sizeof(int));
            for (int j = 0; j < 9; j++) {
                int v = mat[i][j];
                if (v < 1 || v > 9 || cont[v]++) {
                    valido = 0;
                    break;
                }
            }
            free(cont);
        }

        for (int j = 0; j < 9 && valido; j++) {
            int *cont = calloc(10, sizeof(int));
            for (int i = 0; i < 9; i++) {
                int v = mat[i][j];
                if (v < 1 || v > 9 || cont[v]++) {
                    valido = 0;
                    break;
                }
            }
            free(cont);
        }

        for (int x = 0; x < 9 && valido; x += 3)
            for (int y = 0; y < 9 && valido; y += 3) {
                int *cont = calloc(10, sizeof(int));
                for (int i = x; i < x + 3; i++)
                    for (int j = y; j < y + 3; j++) {
                        int v = mat[i][j];
                        if (v < 1 || v > 9 || cont[v]++) {
                            valido = 0;
                            break;
                        }
                    }
                free(cont);
            }

        printf("Instancia %d\n%s\n\n", k, valido ? "SIM" : "NAO");

        for (int i = 0; i < 9; i++)
            free(mat[i]);
        free(mat);
    }

    return 0;
}
