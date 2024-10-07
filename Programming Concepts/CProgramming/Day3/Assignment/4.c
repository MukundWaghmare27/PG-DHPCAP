#include<stdio.h>

int main(){
    int num;
    printf("Enter the num: ");
    scanf("%d", &num);

    for (int i=0; i <= num; i++){
        if( i==0 && i==1){
            printf("%d\n", i);
        }else{
            int j=(i-1)+(i-2);
            printf("%d\n", j);
        }
        
        
    }
}