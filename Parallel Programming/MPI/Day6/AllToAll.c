//Alltoall: All processes will share their own data to all other processes
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(){
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *send_data = malloc(sizeof(int) * size);
    int *recv_data = malloc(sizeof(int) * size);
  
    for(int i=0; i<size; i++){
        send_data[i] = i+1;
    }

    printf("process %d send data: ", rank);
    for(int i=0; i<size; i++){
        printf("%d ", send_data[i]);
    }
    printf("\n");

    MPI_Alltoall(send_data, 1, MPI_INT, recv_data, 1, MPI_INT, MPI_COMM_WORLD);
    printf("process %d received data: ", rank);
    for(int i=0; i<size; i++){
        printf("%d ", recv_data[i]);
    }
    printf("\n");

    free(send_data);
    free(recv_data);
    MPI_Finalize();

    return 0;
}

                 //After AllToall --> It is transposing the data             
//0 --> 1 2 3        0 --> 1 4 7
//1 --> 4 5 6        1 --> 2 5 6
//2 --> 7 8 9        2 --> 3 6 9
