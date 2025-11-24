#include <stdio.h>

// Remove duplicados de um vetor já ordenado
int removeDuplicados(int arr[], int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

int main() {
    int A, B;

    while (1) {
        scanf("%d %d", &A, &B);
        if (A == 0 && B == 0) break;

        int alice[A], beatriz[B];

        for (int i = 0; i < A; i++) scanf("%d", &alice[i]);
        for (int i = 0; i < B; i++) scanf("%d", &beatriz[i]);

        // Remover duplicados (já estão ordenados na entrada)
        A = removeDuplicados(alice, A);
        B = removeDuplicados(beatriz, B);

        int i = 0, j = 0;
        int unicosA = 0, unicosB = 0;

        while (i < A && j < B) {
            if (alice[i] < beatriz[j]) {
                unicosA++;
                i++;
            } else if (alice[i] > beatriz[j]) {
                unicosB++;
                j++;
            } else {
                // cartas iguais, não contam como únicas
                i++;
                j++;
            }
        }

        // Se ainda sobraram cartas em Alice ou Beatriz
        unicosA += (A - i);
        unicosB += (B - j);

        int resultado = (unicosA < unicosB) ? unicosA : unicosB;
        printf("%d\n", resultado);
    }

    return 0;
}
