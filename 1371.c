#include <stdio.h>
#include <math.h>

int main() {
    long long N;
    while (scanf("%lld", &N) && N != 0) {

        long long raiz = (long long)sqrt((long double)N);

        for (long long i = 1; i <= raiz; i++) {
            printf("%lld", i * i);
            if (i != raiz) printf(" ");
        }

        printf("\n");
    }

    return 0;
}
