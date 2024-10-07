#include <stdio.h>

int main() {
    char a[10];
    int i;

    printf("Enter a char in lowercase: ");
    scanf("%c", a);
  
    for(i = 0; a[i] != '\0'; i++) {
 
        if(a[i] >= 'a' && a[i] <= 'z') {
            a[i] = a[i] - 32; 
        }
    }
    printf("String in uppercase: %c\n", a);
}
