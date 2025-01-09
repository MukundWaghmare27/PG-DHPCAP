//Fully Optimized By Manual Method

#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    int size, rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    const int n = 10000;
    int chunksize = n / size;  
    int start = rank * chunksize;
    int end = start + chunksize;
    if(rank == size - 1){
        end = n;
        chunksize += n % size;
    }
    int arr[chunksize];
    int index = 0;
    for(int i=start; i<end; i++){
        arr[index] = i+1;
        index++;
    }
    index = 0;
    int localsum = 0;
    for(int i = start; i < end; i++){
        localsum += arr[index];
        index ++; 
    }

    if(rank != 0){
        MPI_Send(&localsum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } else {
        int totalsum = localsum; 
        int temp_sum;
        for(int i = 1; i < size; i++){
            MPI_Recv(&temp_sum, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            totalsum += temp_sum;
        }
        printf("Total sum = %d\n", totalsum);
    }

    MPI_Finalize();
    return 0;
}




