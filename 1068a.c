#include <stdio.h>
#include <string.h>

int main() {
    char expr[1001];
    
    while (scanf("%s", expr) != EOF) {
        int i, balance = 0, correto = 1;
        
        for (i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '(') {
                balance++;
            } else if (expr[i] == ')') {
                balance--;
                if (balance < 0) { // fechou mais do que abriu
                    correto = 0;
                    break;
                }
            }
        }
        
        if (balance != 0)
            correto = 0;
        
        if (correto)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}
