//MPI_Sendrecv --> Combination of MPI_Send and MPI_Recv

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(){
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int n = 1000000;

    int *arr1 = malloc(sizeof(int) * n);
    int *arr2 = malloc(sizeof(int) * n);
    
    if(rank == 0){
        //Initializing data for process 0
        for(int i=0; i<n; i++){
            arr1[i] = i+1;
        }
        MPI_Sendrecv(arr1, n, MPI_INT, 1, 0, arr1, n, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received array from process 1: \n");
        for(int i=n-10; i<n; i++){
            printf("%d ", arr1[i]);
        }
        printf("\n");
    }else if(rank == 1){
        //Initializing data for process 1
        for(int i=0; i<n; i++){
            arr1[i] = i*2;
        }
        MPI_Sendrecv(arr1, n, MPI_INT, 0, 0, arr1, n, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received array from process 0: \n");
        for(int i=n-10; i<n; i++){
            printf("%d ", arr1[i]);
        }
        printf("\n");
    }else{
        //printf("I am process %d and have nothing to do\n", rank);
    }

    free(arr1);
    free(arr2);
    MPI_Finalize();
    return 0;
}



