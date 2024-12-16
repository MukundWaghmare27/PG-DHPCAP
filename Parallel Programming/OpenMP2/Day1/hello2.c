#include <stdio.h>
#include <omp.h>

int main(){
	omp_set_num_threads(4);   //threads=4  this is usually use for all the parallel region defined

	#pragma omp parallel num_threads(6)   //num_threads will have preference- threads=6 (used for specific parallel region)
	{
		printf("Hello Shavak omp\n");
	}

	return 0;
}




