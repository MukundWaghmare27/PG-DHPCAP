////Tag should be same for source and destination
//Here in this example, process 0 sending 2 data's to process 1, if we are using same tag for the both, then at destination can be receive wrong data, so the tags should be different

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);       //can use NULL

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int data1, data2;
    if(rank == 0){
        data1 = 100;
        data2 = 200;
        MPI_Send(&data1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);  
        MPI_Send(&data2, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
    }
    else if(rank == 1){
        MPI_Recv(&data1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&data2, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("on process %d, received data = %d & data2 = %d\n",rank, data1, data2);
    }

    MPI_Finalize();

    return 0;
}