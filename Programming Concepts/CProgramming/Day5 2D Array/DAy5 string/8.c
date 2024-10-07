// palindrome

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

    int j=0;

    for(int i=length1-1;i>=0;i--){
        b[j]=a[i];
        j++;
    }

    // printf("%s \n",b);

    int flag=0;

    for(int i=0;i<length1;i++){
        if(a[i]!=b[i]){
            flag++;
            break;
        }
    }

 

    if(flag==0){
        printf("palindrome \n");
    }else{
        printf(" not a palindrome \n");
    }   
}