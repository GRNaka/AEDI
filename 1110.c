#include <stdio.h>
 
int main() {
    
    int N;
    scanf ("%d", &N);
    
    while (N != 0){
        
        int vet [100];
        int aux = 1;
        
        for(int i = 0; i < N; i++){
            
            vet[i] = aux++;
            
        }
        
        printf("Discarded cards: ");
        int descarte = 0;
        int inicio = 0, fim = N;
        
        while (fim - inicio > 1){
            
            if (descarte == 0){
                printf ("%d", vet[inicio]);
            }
            else{
                printf(", %d", vet[inicio]);
            }
            descarte++;
            inicio++;
            
            vet[fim] = vet[inicio];
            fim++;
            inicio++;
        }
    
    printf("\nRemaining card: %d\n", vet[inicio]);
    scanf("%d", &N);
    }
 
    return 0;
}
