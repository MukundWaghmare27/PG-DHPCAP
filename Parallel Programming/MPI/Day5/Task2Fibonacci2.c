#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int fibo = 0, RecvFibo1 = 0, RecvFibo2 = 0;

    if (rank == 0) {
        fibo = 0;
        MPI_Send(&fibo, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&RecvFibo1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        fibo = 1;
        MPI_Send(&RecvFibo1, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&fibo, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
    } else {
        MPI_Recv(&RecvFibo1, 1, MPI_INT, rank - 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&RecvFibo2, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        fibo = RecvFibo1 + RecvFibo2;

        if (rank < size - 1) {
            MPI_Send(&RecvFibo2, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
            MPI_Send(&fibo, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
        }
    }

    int *allFibo = NULL;
    if (rank == 0) {
        allFibo = malloc(sizeof(int) * size);
    }
    MPI_Gather(&fibo, 1, MPI_INT, allFibo, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Fibonacci series till rank %d:\n", size - 1);
        for (int i = 0; i < size; i++) {
            printf("%d ", allFibo[i]);
        }
        printf("\n");
        free(allFibo);
    }

    MPI_Finalize();
    return 0;
}
