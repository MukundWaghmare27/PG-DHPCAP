#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    const int n = 1000; 
    int chunksize = n / size; 
    int *arr = NULL;
    int *arr2 = (int*)malloc(sizeof(int) * chunksize); 
    int *all_sums = NULL;
    if (rank == 0) {
        arr = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        all_sums = (int*)malloc(sizeof(int) * size);
    }
    MPI_Scatter(arr, chunksize, MPI_INT, arr2, chunksize, MPI_INT, 0, MPI_COMM_WORLD);

    int localsum = 0;
    for (int i = 0; i < chunksize; i++) {
        localsum += arr2[i];
    }

    MPI_Gather(&localsum, 1, MPI_INT, all_sums, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        int totalsum = 0;
        for (int i = 0; i < size; i++) {
            totalsum += all_sums[i];
        }
        printf("Total sum = %d\n", totalsum);

        free(arr);
        free(all_sums);
    }

    free(arr2);

    MPI_Finalize();
    return 0;
}
