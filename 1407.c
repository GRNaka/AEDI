#include <stdio.h>
#include <string.h>

#define MAXN 110
#define MAXT 610

int main() {
    int n, t, caso = 1;

    while (1) {
        scanf("%d %d", &n, &t);
        if (n == 0) break;  // fim da entrada

        int duracao[MAXN], pontos[MAXN];
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &duracao[i], &pontos[i]);  // primeiro duração, depois pontos
        }

        // Programação dinâmica estilo "mochila ilimitada"
        int dp[MAXT];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = duracao[i]; j <= t; j++) {
                if (dp[j - duracao[i]] + pontos[i] > dp[j]) {
                    dp[j] = dp[j - duracao[i]] + pontos[i];
                }
            }
        }

        printf("Instancia %d\n", caso++);
        printf("%d\n\n", dp[t]);
    }

    return 0;
}
