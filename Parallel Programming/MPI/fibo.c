#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(){
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int fibo =0, RecvFibo1=0, RecvFibo2=0;

    for(int i=0; i<size; i++){
        if(rank == 0 && rank == 1){
            fibo = rank;
            MPI_Send(&fibo, 1, MPI_INT, 2, rank, MPI_COMM_WORLD);
        }
        else if(rank == 2){
            MPI_Recv(&RecvFibo1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&RecvFibo2, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            fibo = RecvFibo1 + RecvFibo2;
            MPI_Send(&fibo, 1, MPI_INT, 3, 2, MPI_COMM_WORLD);
            MPI_Send(&RecvFibo2, 1, MPI_INT, 3, 2, MPI_COMM_WORLD);
        }else{
            for(int i=3; i<size; i++){
                if(rank == 3){
                    MPI_Recv(&RecvFibo1, 1, MPI_INT, 2, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    MPI_Recv(&RecvFibo2, 1, MPI_INT, 2, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    fibo = RecvFibo1 + RecvFibo2;
                    MPI_Send(&fibo, 1, MPI_INT, 4, 3, MPI_COMM_WORLD);
                    MPI_Send(&RecvFibo2, 1, MPI_INT, 4, 3, MPI_COMM_WORLD);
                }else{
                    if(rank == size) exit;
                    MPI_Recv(&RecvFibo1, 1, MPI_INT, rank-1, rank-1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    MPI_Recv(&RecvFibo2, 1, MPI_INT, rank-1, rank-1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    fibo = RecvFibo1 + RecvFibo2;
                    MPI_Send(&fibo, 1, MPI_INT, rank+1, rank, MPI_COMM_WORLD);
                    MPI_Send(&RecvFibo2, 1, MPI_INT, rank+1, rank, MPI_COMM_WORLD); 
                }
            }
        }
    }

    int *allFibo = NULL;
    if(rank==0) allFibo = malloc(sizeof(int)*size);
    MPI_Gather(&fibo, 1, MPI_INT, allFibo, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if(rank ==0){
        for(int i=0; i<size; i++){
        printf("%d ", allFibo[i]);
        }
        free(allFibo);
    }

    MPI_Finalize();

}
