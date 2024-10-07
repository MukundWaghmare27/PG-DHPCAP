#include <stdio.h>

int main(){
    int i, j;
    int a[4], b[4], c[4];

    printf("Enter the elements of first array: ");
    for(i=0; i<5; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter the elements of second array: ");
    for(j=0; j<5; j++){
        scanf("%d", &b[j]);
    }
    
    printf("sum of arrays: ");
    for (i=0; i<5; i++){
        c[i] = a[i]+b[i] ;
        printf("%d ", c[i]);
    }
    return 0;
}

