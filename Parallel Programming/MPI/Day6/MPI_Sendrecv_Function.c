//MPI_Sendrecv --> Combination of MPI_Send and MPI_Recv

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(){
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int sendbuf, recvbuff;
    if(rank == 0){
        sendbuf = 786;
        MPI_Sendrecv(&sendbuf, 1, MPI_INT, 1, 0, &recvbuff, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("process 0 sent number %d and recived number %d\n", sendbuf, recvbuff);
    }else if(rank == 1){
        sendbuf = 7;
        MPI_Sendrecv(&sendbuf, 1, MPI_INT, 0, 0, &recvbuff, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("process 0 sent number %d and recived number %d\n", sendbuf, recvbuff);
    }else{
        printf("I am process %d and have nothing to do\n", rank);
    }

    MPI_Finalize();
    return 0;
}



