#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){

	int x=25, y=5, product;
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank==0){
		
		product = x + y;
		printf("rank %d x + y = %d\n", rank, product);
	}
	if(rank==1){
		product = x * y;
		printf("on rank %d x * y = %d\n", rank, product);
	}

	MPI_Finalize();
	return 0;

}
