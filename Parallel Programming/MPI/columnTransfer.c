//MPI_Type_vector: This is a derived data type of MPI
//Use Case: -- > 1) to transfer columns of the matrix

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int count = 3;
    const int blocklength = 2;
    const int stride = 6;
    int arr[N][N];
    MPI_Datatype vector_type;
    MPI_Type_vector(count, blocklength, stride, MPI_INT, &vector_type);
    MPI_Type_commit(&vector_type);
    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            for(int j=0; j<N; j++){
                arr[i][j] = i + j + 1;
            }
        }
        MPI_Send(arr, 1, vector_type, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent data: \n");
        for (int i = 0; i < N; i++) {
            for(int j=0; j<N; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    } else if (rank == 1) {
        MPI_Recv(arr, count * blocklength, vector_type, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);  
        printf("Process 1 received data: \n");
        for (int i = 0; i < N; i++) {
            for(int j=0; j<N; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    MPI_Type_free(&vector_type);

    MPI_Finalize();
    return 0;
}

