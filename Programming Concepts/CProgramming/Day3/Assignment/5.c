#include<stdio.h>

int main(){
    int num;
    printf("Enter the num: ");
    scanf("%d", &num);

    for(int i=2; i<=num; i++){
        if(num%i==0){
            printf("%d is not prime", num); 
            return 0;       
        }
    }
    printf("%d is prime", num);
}
   