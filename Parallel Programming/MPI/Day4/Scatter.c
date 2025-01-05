//Scatter: scatter is used to divide equal amount of data between processes.
//Problem: It will not manage the remainder data. Ex. chunksize = n/size = 10 / 4 remainder = 2, so in scatter it can happer that, it can not include the last two data during distribution 

#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    int size, rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    const int n = 10;
    int chunksize = n / size;
    int* arr;
    int *arr2 = (int*)malloc(sizeof(int) * chunksize);
    if(rank == 0){
        arr = (int*)malloc(sizeof(int) * n);
        for(int i = 0; i < n; i++){
                arr[i] = i + 1;
        }
    }
    MPI_Scatter(arr, chunksize, MPI_INT, arr2, chunksize, MPI_INT, 0, MPI_COMM_WORLD);

    for(int i = 0; i < chunksize; i++){
        printf("%d ", arr2[i]);
    }
    printf("\n");

    free(arr2);
    if(rank == 0) free(arr);

    MPI_Finalize();
    return 0;
}