// PRN : 240840141026
// Name : Mukund PW

#include <stdio.h>

int main() {
    int r1, c1,r2, c2;
    
    printf("Enter the row size and column size for matrix A : \n");
    scanf("%d %d", &r1, &c1);

    printf("Enter the row size and column size for matrix B : \n");
    scanf("%d %d", &r2,  &c2);

    int a[r1][c1], b[r2][c2], c[r1][c2];

    printf("Enter the elements of matrix A \n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B \n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0; 
        }
    }

    if(c1 == r2){

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }else{
        printf("Matrices cannot be multiplied. The no of columns in the 1st matrix must be equal to the no of rows in the 2nd matrix.\n");
    }

    printf(" matrix A \n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf(" matrix B \n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    printf("Resulting matrix C \n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
