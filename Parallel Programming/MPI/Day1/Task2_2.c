//Rank 0: Initialize the array data, and Send data to Rank 1
//Rank 1: Receive the data from Rank 0 

#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

#define N 100

int main(){
    int rank, size;
    int a[N] = {0};
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0){
        for(int i=0; i<N; i++){
            a[i] = i+1;
        }
    }
    for(int i=0; i<N; i++){
        if(rank == 0){
            MPI_Send(&a[i], N, MPI_INT, 1, 0, MPI_COMM_WORLD);
        }
        else if(rank == 1){
            MPI_Recv(&a[i], N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
    for(int i=0; i<N; i++){
        if(rank == 0){
            printf("%d ", a[i]);
        }
    }
    printf("\n");
    for(int i=0; i<N; i++){
        if(rank == 1){
            printf("%d ", a[i]);
        }
    }

    MPI_Finalize();

    return 0;
}





