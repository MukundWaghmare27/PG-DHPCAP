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


    int start;
    printf("Enter the start position : \n");
    scanf("%d",&start);

    int end;
    printf("Enter the end position : \n");
    scanf("%d",&end);

    int j=0;
    for(int i=start;i<end;i++){
        b[j]=a[i];
        j++;
    }

    printf("%s \n",b);

    return 0;

}