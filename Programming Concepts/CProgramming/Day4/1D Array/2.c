#include <stdio.h>

int main(){
    int a[4] = {1, 2, 3, 4, 5};

    printf("Elements of array are: ");
    for(int i=0; i<5; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("Array in reverse order: ");
    for(int j=4; j>=0; j--){
        printf("%d\t", a[j]);
    }
}