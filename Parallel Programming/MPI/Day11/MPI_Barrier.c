
#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
 
int main(int argc, char **argv){
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0){
        printf("process %d preparing data\n", rank);
        sleep(2);
    }

    printf("process %d waiting at barrier\n", rank);
    MPI_Barrier(MPI_COMM_WORLD);

    printf("process %d, proceeeding to next phase\n", rank);

    MPI_Finalize();

    return 0;
}