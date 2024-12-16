#include <stdio.h>
#include <omp.h>

int main(){

    printf("Total num of threads before Parallel region: %d\n", omp_get_num_threads());  //only master thread=1

	omp_set_num_threads(10);   //threads=10  this is usually use for all the parallel region defined

	#pragma omp parallel num_threads(4)   //num_threads clause will have preference- threads=4 (used for specific parallel region)
	{
		printf("Hello Shavak from Parallel Region: 1 total threads: %d\n", omp_get_num_threads());  //threads=4
	}

    #pragma omp parallel              //Second parallel region (Clause num_thread not specified, So it will run on threads=10)
    {
        printf("Hello shavak from Par Region: 2  total threads: %d\n", omp_get_num_threads());  //threads=10
    }

    printf("Total num of threads after Parallel region: %d\n", omp_get_num_threads());  //only master thread=1

	return 0;
}

////////////Preferences/////////////
//num_threads > omp_set_num_threads > export OMP_NUM_THREADS




