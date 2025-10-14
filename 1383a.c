#include <stdio.h>

void LerSudoku(int mat[9][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int VerificaLinha(int mat[9][9]) {
    int i, j;

    for (i = 0; i < 9; i++) {
        int verificado[10] = {0};

        for (j = 0; j < 9; j++) {
            int num = mat[i][j];

            if (num < 1 || num > 9) {
                return 0;
            }

            if (verificado[num]) {
                return 0;
            }

            verificado[num] = 1;
        }
    }

    return 1;
}

int VerificaColuna(int mat[9][9]) {
    int i, j;

    for (j = 0; j < 9; j++) {
        int verificado[10] = {0};

        for (i = 0; i < 9; i++) {
            int num = mat[i][j];

            if (num < 1 || num > 9) {
                return 0;
            }

            if (verificado[num]) {
                return 0;
            }

            verificado[num] = 1;
        }
    }

    return 1;
}

int VerificaBlocos(int mat[9][9]) {
    int bi, bj, i, j;

    for (bi = 0; bi < 9; bi += 3) {        
        for (bj = 0; bj < 9; bj += 3) {    
            int verificado[10] = {0};

            for (i = 0; i < 3; i++) {      
                for (j = 0; j < 3; j++) {
                    int num = mat[bi+i][bj+j];

                    if (num < 1 || num > 9) {
                        return 0;
                    }

                    if (verificado[num]) {
                        return 0;
                    }

                    verificado[num] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int N;
    int mat[9][9];

    scanf("%d", &N);

    for (int aux = 0; aux < N; aux++) {
        LerSudoku(mat);

        if (VerificaLinha(mat) && VerificaColuna(mat) && VerificaBlocos(mat)) {
            printf("Instancia %d\nSIM\n\n", aux + 1);
        } else {
            printf("Instancia %d\nNAO\n\n", aux + 1);
        }
    }

    return 0;
}
