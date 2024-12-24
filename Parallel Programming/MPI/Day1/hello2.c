#include<stdio.h>
#include<mpi.h>

int main(){
    int rank, size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Hello from process/rank %d of %d\n", rank, size);

    MPI_Finalize();

    return 0;
}

//MPI_COMM_WORLD = Communicator
//rank = process
//size = size of the communicator group (Total Processes)





