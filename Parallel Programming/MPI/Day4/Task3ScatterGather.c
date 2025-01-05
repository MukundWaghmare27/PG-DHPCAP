
#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    int size, rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    const int n = 1000;
    int chunksize = n / size;
    int *arr;
    int arr2[chunksize];
    if(rank == 0){
        arr = (int*)malloc(sizeof(int) * n);
        for(int i = 0; i < n; i++) arr[i] = i + 1;
    }
    MPI_Scatter(arr, chunksize, MPI_INT, arr2, chunksize, MPI_INT, 0, MPI_COMM_WORLD);

    int localsum = 0;
    for(int i = 0; i < chunksize; i++){
        localsum += arr2[i];
    }

    int *all_localsum = NULL;
    if(rank == 0){
        all_localsum = malloc(sizeof(int) * size);
    }

    MPI_Gather(&localsum, 1, MPI_INT, all_localsum, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank == 0){
        int totalsum = 0;
        for(int i=0; i<size; i++){
            totalsum += all_localsum[i];
        }
        printf("totalsum = %d\n", totalsum);
        free(arr);
        free(all_localsum);
    }

    MPI_Finalize();
    return 0;
}


