//Array Swapping between processes using MPI_Send and MPI_Recv

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
        MPI_Send(arr1, n, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(arr2, n, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        //replace the arr2 with arr1
        for(int i = 0; i < n; i++){
            arr1[i] = arr2[i];
        }
        free(arr2);    //free unusable data
        printf("Received array from process 1: \n");
        for(int i=n-10; i<n; i++){
            printf("%d ", arr1[i]);
        }
        printf("\n");
    }else if(rank == 1){
        MPI_Recv(arr2, n, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        //Initializing data for process 1
        for(int i=0; i<n; i++){
            arr1[i] = i*2;
        }
        MPI_Send(arr1, n, MPI_INT, 0, 0, MPI_COMM_WORLD);
        //replace the arr2 with arr1
        for(int i = 0; i < n; i++){
            arr1[i] = arr2[i];
        }
        free(arr2);     //free unusable data
        printf("Received array from process 0: \n");
        for(int i=n-10; i<n; i++){
            printf("%d ", arr1[i]);
        }
        printf("\n");
    }else{
        free(arr2);
        //printf("I am process %d and have nothing to do\n", rank);
    }

    free(arr1);
    MPI_Finalize();
    return 0;
}



