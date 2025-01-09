//MPI_Pack --> 

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

typedef struct{
    int a;
    float b;
    char c;
} my_struct;

int main() {
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        fprintf(stderr, "World size must be greater than 1 for this example\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    my_struct data;
    void *buffer;
    int buffer_size, position;

    if (rank == 0) {
        data.a = 786;
        data.b = 786.0;
        data.c = 'A';

        MPI_Pack_size(1, MPI_INT, MPI_COMM_WORLD, &buffer_size);
        buffer_size += sizeof(float) + sizeof(char);  
        buffer = malloc(buffer_size);

        if (buffer == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        position = 0;
        MPI_Pack(&data.a, 1, MPI_INT, b#include <mpi.h>
uffer, buffer_size, &position, MPI_COMM_WORLD);
        MPI_Pack(&data.b, 1, MPI_FLOAT, buffer, buffer_size, &position, MPI_COMM_WORLD);
        MPI_Pack(&data.c, 1, MPI_CHAR, buffer, buffer_size, &position, MPI_COMM_WORLD);

        MPI_Send(buffer, buffer_size, MPI_PACKED, 1, 0, MPI_COMM_WORLD);
        printf("Process %d sent packed data\n", rank);
        
        free(buffer); 
    } else if (rank == 1) {
        MPI_Status status;
        MPI_Probe(0, 0, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_PACKED, &buffer_size);

        buffer = malloc(buffer_size);

        if (buffer == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        MPI_Recv(buffer, buffer_size, MPI_PACKED, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        position = 0;
        MPI_Unpack(buffer, buffer_size, &position, &data.a, 1, MPI_INT, MPI_COMM_WORLD);
        MPI_Unpack(buffer, buffer_size, &position, &data.b, 1, MPI_FLOAT, MPI_COMM_WORLD);
        MPI_Unpack(buffer, buffer_size, &position, &data.c, 1, MPI_CHAR, MPI_COMM_WORLD);
        printf("Process %d received: {a = %d, b = %.2f, c = %c}\n", rank, data.a, data.b, data.c);
        free(buffer);  
    }

    MPI_Finalize();
    return 0;
}
