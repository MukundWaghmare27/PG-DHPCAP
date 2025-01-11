#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 1000000

int main(int argc, char **argv) {
    int i, j;
    int count, flag;
    double exe_time;
    double stop_time, start_time;

    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunksize = N / size;
    int start = rank * chunksize;
    int end = start + chunksize;
    if (rank == size - 1) {
        end = N;
    }
    if(rank == 0){
        start_time = MPI_Wtime();
    }

    count = 0; 
    for (i = start; i < end; i++) {
        if (i < 2) continue; 
        flag = 0;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            count++;
        }
    }    

    int *global_count = NULL; 
    if (rank == 0) {
        global_count = (int *)malloc(sizeof(int) * size);
    }
    MPI_Gather(&count, 1, MPI_INT, global_count, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        int total_count = 0;
        for (int i = 0; i < size; i++) {
            total_count += global_count[i];
        }
        stop_time = MPI_Wtime();
        exe_time = stop_time - start_time;
        printf("\n Number of prime numbers = %d \n Execution time is = %lf seconds\n", total_count, exe_time);
        free(global_count); 
    }

    MPI_Finalize();
    return 0;
}
