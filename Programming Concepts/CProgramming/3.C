#include<stdio.h>

int main() {
    int L = 25, B = 30;
    int area, perimeter;

    area = L * B;
    perimeter = ((2*L) + (2*B));

    printf("area = %d, perimeter = %d", area,perimeter);

    return 0;
}
