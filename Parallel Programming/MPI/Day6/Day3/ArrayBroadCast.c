#include <stdio.h>
#include <mpi.h>
#define N 100

int main(){
    MPI_Init(NULL, NULL);      

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int arr[N];

    if(rank == 0){
        for(int i=0; i<N; i++){
            arr[i]= i+1;
        }
    }
    MPI_Bcast(arr, N, MPI_INT, 0, MPI_COMM_WORLD);  //process 0 will broadcast

    for(int i=N-5; i<N; i++){
        printf("%d ", arr[i]);
    }

    MPI_Finalize();

    return 0;
}