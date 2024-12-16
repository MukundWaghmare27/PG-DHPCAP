#include <stdio.h>
#include <omp.h>

int main(){
	omp_set_num_threads(4);   //threads=4  this is usually use for all the parallel region defined

	#pragma omp parallel num_threads(6)   //num_threads clause will have preference- threads=6 (used for specific parallel region)
	{
		printf("Hello Shavak from Parallel Region: 1 \n");
	}

    #pragma omp parallel              //Second parallel region (Clause num_thread not specified, So it will run on threads=4)
    {
        printf("Hello shavak from Par Region: 2\n");
    }

	return 0;
}

////////////Preferences/////////////
//num_threads > omp_set_num_threads > export OMP_NUM_THREADS




