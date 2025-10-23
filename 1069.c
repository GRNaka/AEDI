#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char linha[1001];
    
    scanf("%d", &N);
    getchar(); // consome o \n após o número de casos
    
    for (int i = 0; i < N; i++) {
        fgets(linha, 1001, stdin);

        int topo = 0;     // topo da pilha
        int diamantes = 0;
        char pilha[1001]; // pilha para armazenar '<'

        for (int j = 0; linha[j] != '\0'; j++) {
            if (linha[j] == '<') {
                pilha[topo++] = '<'; // empilha
            } 
            else if (linha[j] == '>' && topo > 0) {
                topo--;       // desempilha um '<'
                diamantes++;  // formou um "<>"
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
