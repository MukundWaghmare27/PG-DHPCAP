#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

#define N 1000

int main(){

    int *arr = malloc(sizeof(int) * N);
    int rank, size;
    long localSum=0, finalSum = 0;

    MPI_Init(NULL, NULL);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int chunksize = N / size;
    int start = chunksize * rank;
    int end = start + chunksize;
    if(rank = size -1) end = N;
    
    if(rank == 0){
        for(int i=0; i<N; i++){
            arr[i] += i+1;
        }
        for(int i=N-10; i<N; i++){
            printf("%d ", arr[i]);
        }
        for(int i=1; i<size; i++){
            for(int i=start; i<end; i++){
                MPI_Send(&arr, N, MPI_INT, i, 0, MPI_COMM_WORLD);
                printf("Rank %d, Sending data to Rank %d\n", rank, i);
            }
        }
        for(int i=start; i<end; i++){
            localSum += arr[i];
        }
        printf("on Rank %d, localSum is %ld\n", rank, localSum);

        //for(int i=1; i<size; i++){
          //  MPI_Recv(&localSum, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
           // printf("On Rank 0, Receiving localSum = %ld from Rank %d\n", localSum, i);
       // }
       
    }
    for(int i=1; i<size; i++){
        if(rank == i){
            MPI_Recv(&arr, N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            for(int i=start; i<end; i++){
                localSum += arr[i];
            }
            //MPI_Send(&localSum, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD);
            //printf("Rank %d, send localsum = %ld to Rank 0\n", i, localSum);
        }
    }

    free(arr);
    MPI_Finalize();

    return 0;
}