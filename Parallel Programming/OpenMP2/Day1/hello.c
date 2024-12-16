#include <stdio.h>
//#include <omp.h>

int main(){
	omp_set_num_threads(0);   //OpenMP routine call
	#pragma omp parallel      //directive
	{
		printf("Hello Shavak omp\n");
	}

	return 0;
}


