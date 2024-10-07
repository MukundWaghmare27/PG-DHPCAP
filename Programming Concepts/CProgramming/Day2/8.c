#include <stdio.h>

int main(){
    int maths, phy, ele;
    printf("Enter the marks of maths, phy, and ele: ");
    scanf("%d %d %d", &maths, &phy, &ele);
    
    int total = maths + phy + ele;
    float average = (float)total / 3;

    if (average < 50){
        printf("The student failed!");
    }else if(average >= 50 && average < 60) {
        printf("Grade C");
    }else if(average >= 60 && average < 70) {
        printf("Grade B");
    }else{
        printf("Grade A");
    }
}