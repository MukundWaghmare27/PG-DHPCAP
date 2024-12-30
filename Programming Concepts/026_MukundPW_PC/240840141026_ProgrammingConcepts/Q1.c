
#include <stdio.h>

//Calculating Factorial of number
long long int factorial(int n) {
    long long int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int numbers[10];
    
    //Entering 10 numbers
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    //printing number with factorial
    printf("\nFactorials of the entered numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Factorial of %d is: %lld\n", numbers[i], factorial(numbers[i]));
    }

    return 0;
}

