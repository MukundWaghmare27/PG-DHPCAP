//Sum of All Ranks on process 0, and broadcast it to all other processes using Bcast

#include <stdio.h>
#include <mpi.h>

int main(){
    int rank, size, sum =0;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank != 0){
        MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    else{
        int rank1;
        sum = rank;
        for(int i=1; i<size; i++){
            MPI_Recv(&rank1, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            sum += rank1;
        }
        //printf("sum = %d\n", sum);
        //MPI_Bcast(&sum, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    MPI_Bcast(&sum, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("on rank %d, Total Sum of rank = %d\n", rank, sum);
    
    MPI_Finalize();
}