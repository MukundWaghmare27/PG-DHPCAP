// PRN : 240840141026
// Name : Mukund PW

#include <stdio.h>
#include <math.h>  

int main() {
    int n, i, j;
    
    printf("Enter the nth value: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            printf("%d ", (int)pow(2, j));
        }
        printf("\n");  
    }

    return 0;
}
