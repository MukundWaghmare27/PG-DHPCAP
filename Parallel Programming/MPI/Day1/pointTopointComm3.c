#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

int main(){
    int myval, rank, size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank == 0){
        for(int i=1; i<size; i++){
        myval=786;
        MPI_Send(&myval, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        printf("rank %d, sending myval = %d to rank %d\n", rank, myval, i);
        }
    }
    else{
        myval = 100;
        MPI_Recv(&myval, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("on rank %d, received myval = %d from rank 0\n", rank, myval);
    }
    
    MPI_Finalize();

    return 0;
}





