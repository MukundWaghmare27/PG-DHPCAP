#include <stdio.h>

int main() {
    int i, a[6] = {10, 20, 3, 4, 3, 10}; 
    int search, count = 0;
    printf("Enter the num to search: ");
    scanf("%d", &search);
    for(i = 0; i < 6; i++) { 
        if(a[i] == search) { 
            count++;
        }
    }
    printf("The element occurred %d times\n", count);
    return 0;
}
