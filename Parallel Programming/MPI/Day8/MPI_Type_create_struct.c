#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

typedef struct{
    int a;
    float b;
    char c;
}my_struct;

int main(){
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    my_struct data;
    MPI_Datatype struct_type;

    int blocklengths[3] = {1,1,1};
    MPI_Aint displacement[3];
    MPI_Datatype types[3] = {MPI_INT, MPI_DOUBLE, MPI_CHAR};

    displacement[0] = offsetof(my_struct,  a);
    displacement[1] = offsetof(my_struct,  b);
    displacement[2] = offsetof(my_struct,  c);

    MPI_Type_create_struct(3, blocklengths, displacement, types, &struct_type);
    MPI_Type_commit(&struct_type);

    if(rank == 0){
        data.a = 786;
        data.b = 786.0;
        data.c = 'A';

        MPI_Send(&data, 1, struct_type, 1, 0, MPI_COMM_WORLD);
        printf("process %d send struct: {a= %d, b= %.2f, c=%c}\n", rank, data.a, data.b, data.c);
    }else if(rank ==1){
        MPI_Recv(&data, 1, struct_type, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("process %d received struct: {a= %d, b= %.2f, c=%c}\n", rank, data.a, data.b, data.c);
    }

    MPI_Type_free(&struct_type);
    MPI_Finalize();

    return 0;

}