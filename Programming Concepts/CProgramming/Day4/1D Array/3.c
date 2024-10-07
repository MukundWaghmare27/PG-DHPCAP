#include <stdio.h>

int main(){
    int sum = 0;
    int a[4] = {10, 2, 3, 4};

    printf("Elements of array are: ");
    for(int i=0; i<=3; i++){
        printf("%d\t", a[i]);
        sum += a[i];
    }
    printf("\nsum of array elements is = %d", sum);
    
}