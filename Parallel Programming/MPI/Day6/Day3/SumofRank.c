//Sum of All Ranks

#include <stdio.h>
#include <mpi.h>

int main(){

    int rank, size, sum = 0;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank != 0){
        MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    else{
        sum = rank;
        for(int i=1; i<size; i++){
            MPI_Recv(&rank, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            sum += rank;
        }
        printf("sum = %d\n", sum);
    }
    
    MPI_Finalize();
}