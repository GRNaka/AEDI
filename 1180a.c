#include <stdio.h>
 
int main() {
 
    int N, cont=0, MenorValor=1000;
    scanf ("%d", &N);
    
    int vetX[N];
    
    for (int i = 0; i < N; i++){
        
        scanf("%d", &vetX[i]);
        if (MenorValor > vetX[i]){
            
            MenorValor = vetX[i];
            cont = i;
        }
        
    }
    printf ("Menor valor: %d\n", MenorValor);
    printf ("Posicao: %d\n", cont);
 
    return 0;
}
