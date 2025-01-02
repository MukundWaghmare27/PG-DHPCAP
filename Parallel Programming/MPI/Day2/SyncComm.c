//Synchronous Communication: 

#include <stdio.h>
#include <mpi.h>

int main(){
    int rank, size;
    int a = 10;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0){
        a = 786;
        MPI_Ssend(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Rank %d, Send a = %d to Rank 1\n", rank, a);
    }
    else if(rank == 1){
        a = 22;
        MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Rank %d, Received a = %d from Rank 0\n", rank, a);
    }

    MPI_Finalize();

    return 0;
}