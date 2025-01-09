//MPI_Sendrecv --> Combination of MPI_Send and MPI_Recv

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(){
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int buffer;
    if(rank == 0){
        buffer = 786;
        MPI_Sendrecv_replace(&buffer, 1, MPI_INT, 1, 0, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("on process 0 received number %d\n", buffer);
    }else if(rank == 1){
        buffer = 7;
        MPI_Sendrecv_replace(&buffer, 1, MPI_INT, 0, 0, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("on process 1 recived number %d\n", buffer);
    }else{
        //printf("I am process %d and have nothing to do\n", rank);
    }

    MPI_Finalize();
    return 0;
}



