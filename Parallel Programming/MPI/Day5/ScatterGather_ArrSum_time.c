#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 100000000

int main() {
    int rank, size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long chunksize = N / size;
    long long* global_arr = NULL;
    long long* local_arr = (long long*)malloc(chunksize * sizeof(long long));

    if (rank == 0) {
        global_arr = (long long*)malloc(N * sizeof(long long));
        for (int i = 0; i < N; i++) {
            global_arr[i] = i + 1;
        }
    }
    double StartTime, EndTime;
    if(rank==0) StartTime = MPI_Wtime();

    MPI_Scatter(global_arr, chunksize, MPI_LONG_LONG, local_arr, chunksize, MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    int local_sum = 0;
    for (int i = 0; i < chunksize; i++) {
        local_sum += local_arr[i];
    }

    long long* global_sums = 0;
    if (rank == 0) {
        global_sums = (long long*)malloc(size * sizeof(long long));
    }

    MPI_Gather(&local_sum, 1, MPI_LONG_LONG, global_sums, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        long long total_sum = 0;
        //printf ("Array of local sums: \n");
        for (int i = 0; i < size; i++) {
            //printf("%lld ", global_sums[i]);
            total_sum += global_sums[i];
        }
        EndTime = MPI_Wtime();
        printf("Time Taken: %lf\n", EndTime - StartTime);
        printf("\nTotal sum = %lld\n", total_sum);

        free(global_arr);
        free(global_sums);
    }

    

    free(local_arr);
    MPI_Finalize();
    return 0;
}