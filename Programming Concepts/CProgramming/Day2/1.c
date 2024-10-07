#include <stdio.h>


int main() {
    int maths, phy, ele;
    printf("Enter the marks of maths, phy, and ele: ");
    scanf("%d, %d, %d", &maths, &phy, &ele);

    int total = maths + phy + ele;
    float average = (float)total / 3;
    printf("The average marks is = %.2f", average);
    
    if (average >= 50){
        printf("The student passed!");
    }else{
        printf("The student failed!");
    }
    return 0;
}