#include <stdio.h>
int main(){
    char a[20];
    printf("Enter the 1st string : \n");
    scanf("%s",a);

    char b[20];
    printf("Enter the 2nd string : \n");
    scanf("%s",b);
  
    int length1=0;
    for(int i=0;a[i]!='\0';i++){
        length1++;
    }
        int length2=0;
    for(int i=0;b[i]!='\0';i++){
        length2++;
    }

    int flag=0;

    if(length1==length2){
        for(int i=0;i<length1;i++){
            if(a[i]!=b[i]){
                flag++;
                break;
            }
        }
    }

    if(flag=0){
        printf("strings are equal \n");
    }else{
        printf("strings are not equal \n");
    }   

}