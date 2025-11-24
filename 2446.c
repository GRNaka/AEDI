#include <stdio.h>

#define MAXV 100010

int main() {
    int V, M;
    scanf("%d %d", &V, &M);
    
    int moedas[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &moedas[i]);
    }
    
    // Caso especial: se o valor é 0, sempre é possível (não usar nenhuma moeda)
    if (V == 0) {
        printf("S\n");
        return 0;
    }
    
    // Programação dinâmica - subset sum
    int dp[MAXV] = {0};
    dp[0] = 1;  // Sempre possível formar soma 0 (1 = true)
    
    for (int i = 0; i < M; i++) {
        // Percorre de trás para frente para evitar usar a mesma moeda mais de uma vez
        for (int j = V; j >= moedas[i]; j--) {
            if (dp[j - moedas[i]]) {
                dp[j] = 1;
            }
        }
        
        // Se já encontramos a soma V, podemos parar
        if (dp[V]) break;
    }
    
    printf("%c\n", dp[V] ? 'S' : 'N');
    
    return 0;
}
