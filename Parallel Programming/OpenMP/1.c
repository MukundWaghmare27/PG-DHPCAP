#include <stdio.h>
#include <omp.h>

#define Array_size 1000

int main(){
	int i;
	int array[Array_size];
	int sum = 0;

	for(i=0; i< Array_size; i++){
		array[i]=i+1;

	}

	#pragma omp parallel for reduction(+:sum)
	for(i=0; i<Array_size; i++){
		sum += array[i];
	}

	printf("The sum of the elements in array is %d\n", sum);
}
