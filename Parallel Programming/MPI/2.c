#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

typedef struct {
    char name[50];
    long prnNo;
    int age;
    char email[50];
    double salary;
    int marks[4];
} my_struct;

int main() {
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    my_struct data;
    MPI_Datatype struct_type;

    int blocklengths[6] = {50, 1, 1, 50, 1, 4};
    MPI_Aint displacements[6];
    MPI_Datatype types[6] = {MPI_CHAR, MPI_LONG, MPI_INT, MPI_CHAR, MPI_DOUBLE, MPI_INT};

    displacements[0] = offsetof(my_struct, name);
    displacements[1] = offsetof(my_struct, prnNo);
    displacements[2] = offsetof(my_struct, age);
    displacements[3] = offsetof(my_struct, email);
    displacements[4] = offsetof(my_struct, salary);
    displacements[5] = offsetof(my_struct, marks);

    MPI_Type_create_struct(6, blocklengths, displacements, types, &struct_type);
    MPI_Type_commit(&struct_type);

    if (rank == 0) {
        // Initialize struct data
        strcpy(data.name, "Mac");
        data.prnNo = 12345;
        data.age = 24;
        strcpy(data.email, "mac@gmail.com");
        data.salary = 5800000.0;
        data.marks[0] = 40;
        data.marks[1] = 20;
        data.marks[2] = 88;
        data.marks[3] = 66;

        MPI_Send(&data, 1, struct_type, 1, 0, MPI_COMM_WORLD);
        printf("Process %d sent struct: {name=%s, PRN_No=%ld, age=%d, email=%s, salary=%lf, marks=[%d, %d, %d, %d]}\n",
               rank, data.name, data.prnNo, data.age, data.email, data.salary,
               data.marks[0], data.marks[1], data.marks[2], data.marks[3]);
    } else if (rank == 1) {
        MPI_Recv(&data, 1, struct_type, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received struct: {name=%s, PRN_No=%ld, age=%d, email=%s, salary=%lf, marks=[%d, %d, %d, %d]}\n",
               rank, data.name, data.prnNo, data.age, data.email, data.salary,
               data.marks[0], data.marks[1], data.marks[2], data.marks[3]);
    }

    MPI_Type_free(&struct_type);
    MPI_Finalize();

    return 0;
}
