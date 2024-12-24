#include<stdio.h>
#include<mpi.h>

int main(){
    int rank, size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Hello from process/rank %d of %d\n", rank, size);

    MPI_Finalize();

    //int size2, rank2;
    //MPI_Comm_rank(MPI_COMM_WORLD, &rank2);  //after finalize the mpi related functions will not work, error will occur
    printf("After Finalize rank %d of %d\n", rank, size);  //This will run on all processes
    
    MPI_Init(NULL, NULL);
    int size2, rank2;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank2);
    MPI_Comm_size(MPI_COMM_WORLD, &size2);

    printf("Hello from process/rank %d of %d\n", rank2, size2);

    MPI_Finalize();
    return 0;
}

//MPI_COMM_WORLD = Communicator
//rank = process
//size = size of the communicator group (Total Processes)





