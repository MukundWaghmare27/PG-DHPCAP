#include <stdio.h>
#include<string.h>
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
    // printf("%d",length1);
        int length2=0;
    for(int i=0;b[i]!='\0';i++){
        length2++;
    }
    // printf("%d",length2);

    int length3 = 20;
    char c[length3];
    int j=0;
    for(int i=0;i<length3;i++){
        if(i<length1){
            c[i]=a[i];
        }else if(i==length1){
            c[i]=' ';
        }else if(i>length1){
            c[i]=b[j];
            j++;
        }
    }

    printf("combined string is : %s\n",c);
    

    return 0;
}