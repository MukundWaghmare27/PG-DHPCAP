#include <stdio.h>
#include <omp.h>

#define Arr_Size 1000

int main(){
    int i;
    int array[Arr_Size];
    int sum = 0, max_val = 0;

    for(i=0; i<Arr_Size; i++){
        array[i] = i+1;
    }

    #pragma omp parallel for reduction(+:sum) reduction(max:max_val)
    for(i=0; i<Arr_Size; i++){
        //printf("%d\n",i);
        sum += array[i];
        if (array[i]> max_val){
            max_val = array[i];
        }
    }

    double average = (double)sum / Arr_Size;

    printf("sum : %d\n", sum);
    printf("max : %d\n", max_val);
    printf("average : %f\n", average);
    return 0;

}