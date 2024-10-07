#include <stdio.h>

int main(){
    int a[4] = {1,2,3,4,5};
    int min, max;
    min = max = a[0];

    for(int i=1; i<5; i++){
        if(a[i] < min){
            min = a[i];
        }
        if(a[i] > max){
            max = a[i];
        }
    }
     
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
}


   
