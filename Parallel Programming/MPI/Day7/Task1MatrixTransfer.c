#include <stdio.h>
#include <mpi.h>
#define N 5

int main(){
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int mat[N][N];
    //int *mat = malloc(sizeof(int) * N * N);

    if(rank == 0){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                mat[i][j] = rank*1+i;
            }
        }
        MPI_Send(mat, N*N, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else if(rank == 1){
        MPI_Recv(mat, N*N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }else{

    }
    MPI_Finalize();
    return 0;

}