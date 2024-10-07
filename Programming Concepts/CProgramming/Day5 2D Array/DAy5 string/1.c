#include <stdio.h>
int main(){
    char a[20];
    printf("Enter the string : \n");
    scanf("%s",a);
    int length=0;
    for(int i=0;a[i]!='\0';i++){
        length++;
    }
    printf("%d\n",length);

    for(int i=0;i<length;i++){
        if(a[i]>=65 && a[i]<=90 || a[i]>=97 && a[i]<=122){
            printf("%c is a alphabet \n",a[i]);
        }else if(a[i]>=48 && a[i]<=57){
            printf("%c is a number \n",a[i]);
        }else{
            printf("special character \n");
        }
    }

}