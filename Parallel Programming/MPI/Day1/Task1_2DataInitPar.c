#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

#define N 100

int main(){
    int rank, size;
    int *a = malloc(sizeof(int)*N);;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunksize = N / size;
    int start = chunksize * rank;
    int end = start + chunksize;
    if(rank == size - 1) end = N;

    for(int i=start; i<end; i++){
        a[i] = i+1;
    }
    
    if(rank == 0){
        for (int i=0; i<N; i++){
            printf("%d ", a[i]);
        }
    }

    MPI_Finalize();

    return 0;
}





