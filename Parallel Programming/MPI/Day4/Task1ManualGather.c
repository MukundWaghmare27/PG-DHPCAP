
#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    int size, rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n = 10;
    int chunksize = n / size;
    int start = rank * chunksize;
    int end = start + chunksize;
    if(rank == size - 1){
        end = n;
    }
    
    int *arr2 = malloc(sizeof(int) * chunksize);

    for(int i=0; i<n; i++){
        arr2[i-start] = i+1;
    }
    
    if(rank == 0){
        int *arr1 = malloc(sizeof(int) * n);
        for (int i = 0; i < end; i++) {
            arr1[i] = arr2[i];
        }
        for(int i=1; i<size; i++){
            MPI_Recv(&arr1[i*chunksize], chunksize, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        for(int i=0; i<n; i++){
            printf("%d ", arr1[i]);
        }
    }else{
        MPI_Send(arr2, chunksize, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    
    MPI_Finalize();
    return 0;
}


