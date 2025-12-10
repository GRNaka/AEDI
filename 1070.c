#include <stdio.h>

int main() {
    int x;
    
    // Lê o valor inteiro X
    scanf("%d", &x);
    
    // Se X for par, começa do próximo ímpar
    if (x % 2 == 0) {
        x = x + 1;
    }
    
    // Imprime 6 números ímpares consecutivos
    for (int i = 0; i < 6; i++) {
        printf("%d\n", x + 2 * i);
    }
    
    return 0;
}
