#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]){

	int x=30, y=15, result, mul;
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0){
		result = x + y;
		MPI_Send(&result, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("process 0 shared the sum: %d to process 1\n", result);
	}
	else if(rank == 1){
		MPI_Recv(&result, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		mul = x*y;
		printf("process 1: recv addition result %d from process 0\n", result);
		printf("mult: %d\n", mul);		
	}

	MPI_Finalize();

	return 0;
}
