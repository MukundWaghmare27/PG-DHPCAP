//MPI_Type_indexed: this is a derived data type of MPI

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define N 15

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int count = 3;
    int blocklength[3] = {1, 2, 1};
    int displacement[3] = {0, 3, 7};
    int arr[N];
    MPI_Datatype indexed_type;
    MPI_Type_indexed(count, blocklength, displacement, MPI_INT, &indexed_type);
    MPI_Type_commit(&indexed_type);

    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            arr[i] = i + 1;
        }
        MPI_Send(arr, 1, indexed_type, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent data: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else if (rank == 1) {
        for (int i = 0; i<N; i++) {
                arr[i] = 0;
        }
        MPI_Recv(arr, 1, indexed_type, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received data: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    MPI_Type_free(&indexed_type);

    MPI_Finalize();
    return 0;
}