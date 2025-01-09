
#include <stdio.h>
#include <mpi.h>

int main(){
    MPI_Init(NULL, NULL);      

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int data1, data2;
    if(rank != 0){
        data1 = 100;
        data2 = 200;
        MPI_Request request;
        MPI_Isend(&data1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);  
        MPI_Isend(&data2, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &request);
    }
    else if(rank == 0){
        MPI_Status status;
        MPI_Recv(&data1, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        printf("on process %d, received data = %d\n",rank, data1);
        printf("sender %d\n", status.MPI_SOURCE);
        printf("tag %d\n", status.MPI_TAG);
    }

    MPI_Finalize();

    return 0;
}