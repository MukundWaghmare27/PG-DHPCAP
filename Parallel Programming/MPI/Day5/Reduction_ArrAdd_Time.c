//Reduction (MPI_Reduce): Reduction will gather the all specified Data from all processes to a specified process and perform arithmatic operation (+, *) and store it in a variable of that process
//while using Reduction, no need to use Gather function separately, MPI_Reduce will do it by itself
#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    int size, rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    const long long n = 1000000000;
    int chunksize = n / size;
    long long *arr;
    long long *arr2 = malloc(sizeof(long long) * chunksize);
    if(rank == 0){
        arr = (long long*)malloc(sizeof(long long) * n);
        for(int i = 0; i < n; i++) arr[i] = i + 1;
    }
    double startTime, EndTime;
    if(rank==0) startTime = MPI_Wtime();
    MPI_Scatter(arr, chunksize, MPI_LONG_LONG, arr2, chunksize, MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    long long localsum = 0;
    for(int i = 0; i < chunksize; i++){
        localsum += arr2[i];
    }
    long long totalsum = 0;     //all process have reference of this variable

    MPI_Reduce(&localsum, &totalsum, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);  //only process 0 will collect the all data (localsum), perform addition operation and store it in variable named totalsum

    //MPI_Bcast(&totalsum, 1, MPI_INT, 0, MPI_COMM_WORLD);      //this will broadcast the totalsum to all processes
    
    //printf("On rank : %d total sum: %d\n", rank, totalsum);  //only process 0 have calculated total sum, without broadcast
    
    if(rank == 0){

        EndTime = MPI_Wtime();
        printf("Time Taken: %lf\n", EndTime - startTime);

        printf("On rank : %d total sum: %lld\n", rank, totalsum);
        free(arr);
    }

    MPI_Finalize();
    return 0;
}


