#include<stdio.h>

int main(){
    int num;
    printf("Enter the num: ");
    scanf("%d", &num);

    while(num > 0){
        int rem = num%10;
        int sum = sum + rem;
        num = num/10;
        printf("%d", sum);
    }
}