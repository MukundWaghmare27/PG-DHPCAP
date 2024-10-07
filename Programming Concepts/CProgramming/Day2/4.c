#include <stdio.h>

int main(){
    int A, B, C;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &A, &B, &C);
    printf("A= %d B= %d C= %d\n", A, B, C);

    if (A > B && A > C && A != B && A != C){
        printf("A is the largest number.\n");
    }else if(B > A && B > C){
        printf("B is the largest number.\n");
    }else{
        printf("C is the largest number.\n");
    }
}