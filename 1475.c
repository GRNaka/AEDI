#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, C, T1, T2;

    while (scanf("%d %d %d %d", &N, &C, &T1, &T2) == 4) {

        int F[2005];
        int i, j;

        for (i = 0; i < N; i++) {
            scanf("%d", &F[i]);
        }

        // ordena os furos
        for (i = 0; i < N - 1; i++) {
            for (j = i + 1; j < N; j++) {
                if (F[i] > F[j]) {
                    int aux = F[i];
                    F[i] = F[j];
                    F[j] = aux;
                }
            }
        }

        // duplica os furos (pra simular o círculo aberto)
        for (i = 0; i < N; i++) {
            F[N + i] = F[i] + C;
        }

        int menor = 1000000000;

        // tenta abrir o círculo em cada furo
        for (int ini = 0; ini < N; ini++) {

            int dp[2005];
            dp[N + ini] = 0;

            for (i = N + ini - 1; i >= ini; i--) {

                int p1 = i + 1;
                while (p1 < N + ini && F[p1] - F[i] <= T1) {
                    p1++;
                }

                int p2 = i + 1;
                while (p2 < N + ini && F[p2] - F[i] <= T2) {
                    p2++;
                }

                int usaT1 = T1 + dp[p1];
                int usaT2 = T2 + dp[p2];

                if (usaT1 < usaT2)
                    dp[i] = usaT1;
                else
                    dp[i] = usaT2;
            }

            if (dp[ini] < menor)
                menor = dp[ini];
        }

        printf("%d\n", menor);
    }

    return 0;
}
