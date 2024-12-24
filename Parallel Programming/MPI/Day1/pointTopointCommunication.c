#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

int main(){
    int myval, rank, size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0){
        myval=786;
        printf("rank %d, myval = %d\n", rank, myval);
        MPI_Send(&myval, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("rank %d, shared myval = %d to rank 1\n", rank, myval);
        MPI_Send(&myval, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        printf("rank %d, shared myval = %d to rank 2\n", rank, myval);
        MPI_Send(&myval, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        printf("rank %d, shared myval = %d to rank 3\n", rank, myval);
    }
    else if(rank == 1){
        myval = 100;
        MPI_Recv(&myval, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("on rank %d, received myval = %d from rank 0\n", rank, myval);
    }
    else if(rank == 2){
        myval = 100;
        MPI_Recv(&myval, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("on rank %d, received myval = %d from rank 0\n", rank, myval);
    }
    else if(rank == 3){
        myval = 100;
        MPI_Recv(&myval, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("on rank %d, received myval = %d from rank 0\n", rank, myval);
    }

    MPI_Finalize();

    return 0;
}





