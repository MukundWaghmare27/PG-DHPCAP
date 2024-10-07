#include <stdio.h>
int main(){
  char a[20];
    printf("Enter the string : \n");
    scanf("%s",a);
    int length=0;
    for(int i=0;a[i]!='\0';i++){
        length++;
    }
    printf("length of the string : %d  \n",length);
    

}