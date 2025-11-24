#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    do {
        long long X;  
        scanf("%lld", &X);
        int aux = 0;  

        if (X < 2) {
            printf("Not Prime\n");
        } 
        else if (X == 2) {
            printf("Prime\n");
        } 
        else if (X % 2 == 0) {
            printf("Not Prime\n");
        } 
        else {
            // Testa apenas ímpares até a "raiz quadrada" de X
            for (long long i = 3; i * i <= X; i += 2) {
                if (X % i == 0) {
                    aux = 1; 
                    break;
                }
            }

            if (aux == 0)
                printf("Prime\n");
            else
                printf("Not Prime\n");
        }

        N--;   
    } while (N != 0);

    return 0;
}
