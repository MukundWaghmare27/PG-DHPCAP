//Array Swapping between processes using MPI_Bsend

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(){
    int rank, size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int n = 10000;

    int *arr1 = malloc(sizeof(int) * n);
    //int *arr2 = malloc(sizeof(int) * n);
    
    if(rank == 0){
        for(int i=0; i<n; i++){
            arr1[i] = i+1;
        }
        int buffer_size = MPI_BSEND_OVERHEAD + n * sizeof(int);
        void *buffer = malloc(sizeof(buffer_size));
        MPI_Buffer_attach(buffer, buffer_size);

        MPI_Bsend(arr1, n, MPI_INT, 1, 0, MPI_COMM_WORLD);

        MPI_Buffer_detach(&buffer, &buffer_size);

        MPI_Recv(arr1, n, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received array from process 1: \n");
        for(int i=n-10; i<n; i++){
            printf("%d ", arr1[i]);
        }
        printf("\n");
    }else if(rank == 1){
        for(int i=0; i<n; i++){
            arr1[i] = i*2;
        }
        int buffer_size = MPI_BSEND_OVERHEAD + n * sizeof(int);
        void *buffer = malloc(sizeof(buffer_size));
        MPI_Buffer_attach(buffer, buffer_size);
        
        MPI_Bsend(arr1, n, MPI_INT, 0, 0, MPI_COMM_WORLD);

        MPI_Buffer_detach(&buffer, &buffer_size);

        MPI_Recv(arr1, n, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received array from process 0: \n");
        for(int i=n-10; i<n; i++){
            printf("%d ", arr1[i]);
        }
        printf("\n");
    }else{
        //printf("I am process %d and have nothing to do\n", rank);
    }

    free(arr1);
    MPI_Finalize();
    return 0;
}



