#include <stdio.h>
#include <mpi.h>
#define N 5

int main(){
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int mat[N][N];
    //int count = 5;
    MPI_Datatype Cont_type_mat;

    MPI_Type_contiguous(N*N, MPI_INT, &Cont_type_mat);
    MPI_Type_commit(&Cont_type_mat);

    if(rank == 0){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                mat[i][j] = rank*1+i;
            }
        }
        MPI_Send(mat, 1, Cont_type_mat, 1, 0, MPI_COMM_WORLD);
    }
    else if(rank == 1){
        MPI_Recv(mat, 1, Cont_type_mat, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }else{

    }

    MPI_Type_free(&Cont_type_mat);
    MPI_Finalize();
    return 0;

}