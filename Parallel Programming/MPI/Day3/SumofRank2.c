//Sum of All Ranks and send total rank sum to all processes

#include <stdio.h>
#include <mpi.h>

int main(){
    int rank, size, sum =0;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank != 0){
        MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Recv(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("on rank %d, Total Sum of rank = %d\n", rank, sum);
    }
    else{
        sum = rank;
        for(int i=1; i<size; i++){
            MPI_Recv(&rank, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            sum += rank;
        }
        printf("sum = %d\n", sum);
        for(int i=1; i<size; i++){
            MPI_Send(&sum, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    }
    //if(rank != 0){
      //  MPI_Recv(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        //printf("on rank %d, Total Sum of rank = %d\n", rank, sum);
    //}
    
    MPI_Finalize();
}

