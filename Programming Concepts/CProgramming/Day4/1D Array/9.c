
#include <stdio.h>

int main() {
    char a[10] = {'a', 'b', 'c', 'd', 'e'};  
    char b[10] = {'f', 'g', 'h', 'i', 'j'};  
    char merged[20]; 
    int i, j;

    for(i = 0; i < 5; i++) {
        merged[i] = a[i];
    }

    for(j = 0; j < 5; j++) {
        merged[i + j] = b[j];  
    }

    printf("Merged array: ");
    for(i = 0; i < 10; i++) {
        printf("%c ", merged[i]);
    }
    printf("\n");

    return 0;
}

