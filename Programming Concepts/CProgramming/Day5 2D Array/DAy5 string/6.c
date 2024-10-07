#include <stdio.h>
int main(){

    char a[20];
    printf("Enter the 1st string : \n");
    scanf("%s",a);

    char b[20];
    
    int length1=0;
    for(int i=0;a[i]!='\0';i++){
        length1++;
    }
    
    for(int i=0;i<length1;i++){
            b[i]=a[i];
        }

    printf("content in 2nd string is : %s\n",b);

    }
