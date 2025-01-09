//Reduction (MPI_Allreduce): Reduction will gather the all specified Data(localsum) from all processes to all processes and perform arithmatic operation (+, *) and broadcast to the variable (totalsum) of the all processes
//while using Reduction, no need to use Gather function separately, MPI_Reduce/MPI_Allreduce will do it by itself

#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    int size, rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    const int n = 100000000;
    int chunksize = n / size;
    long long *arr;
    long long *arr2 = malloc(sizeof(long long)*chunksize);
    if(rank == 0){
        arr = (long long*)malloc(sizeof(long long) * n);
        for(int i = 0; i < n; i++) arr[i] = i + 1;
    }

    double startTime, endTime;
    if(rank ==0) startTime = MPI_Wtime();
    MPI_Scatter(arr, chunksize, MPI_LONG_LONG, arr2, chunksize, MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    long long localsum = 0;
    for(int i = 0; i < chunksize; i++){
        localsum += arr2[i];
    }
    long long totalsum;     //all process have reference of this variable

    MPI_Allreduce(&localsum, &totalsum, 1, MPI_LONG_LONG, MPI_SUM, MPI_COMM_WORLD);  //all processes will collect the all data (localsum), perform addition operation and store it in variable (totalsum)

    printf("on rank: %d, total sum: %lld\n", rank, totalsum);

    if(rank == 0){
        endTime = MPI_Wtime();
        printf("Time Taken: %lf\n", endTime - startTime);
        free(arr);
    }

    MPI_Finalize();
    return 0;
}


