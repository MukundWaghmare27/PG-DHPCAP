// PRN : 240840141026
// Name : Mukund PW

#include <stdio.h>
int read();
int power(int,int);
void print(int);

int main() {

    int base,exponent;

    base = read();
    exponent = read();

    int result = power(base,exponent);
    print(result);
    return 0;
}
int read() {
    int x;
    printf("Enter the value : ");
    scanf("%d", &x);
    return x;   
}

int power(int x, int y) {
    int result = 1;
    for (int i = 1; i <= y; i++) {
        result *= x;
    }
    return result;
}

void print(int result) {
    printf("Result: %d\n", result);
}
