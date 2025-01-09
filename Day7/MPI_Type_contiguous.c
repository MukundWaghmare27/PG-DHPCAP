#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define N 20

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        fprintf(stderr, "World size must be greater than 1 for this example\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    const int count = 5;
    int arr[N];
    MPI_Datatype cont_type_arr;
    
    MPI_Type_contiguous(count, MPI_INT, &cont_type_arr);
    MPI_Type_commit(&cont_type_arr);

    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            arr[i] = i + 1;
        }

        MPI_Send(arr, 4, cont_type_arr, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent data: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else if (rank == 1) {
        MPI_Recv(arr, 4, cont_type_arr, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received data: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    MPI_Type_free(&cont_type_arr);

    MPI_Finalize();
    return 0;
}