#include <stdio.h>

int main(){
    int a[5] = {5, 4, 3, 2, 1};  
    int c[5] = {1, 2, 3, 4, 5};  
   
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            if(c[i] < c[j]) {
                int t = c[i];
                c[i] = c[j];
                c[j] = t;
            }
        }
        
        printf("%d ", c[i]);
    }
}
