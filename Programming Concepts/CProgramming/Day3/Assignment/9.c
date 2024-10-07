#include<stdio.h>

int main(){

    for (int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            int table = i*j;
            printf("%d\n",table);
        }
        printf("\n");
    }
    return 0;
}
