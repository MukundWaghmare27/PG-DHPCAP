#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

typedef struct{
    char *name;
    long prnNo;
    int age;
    char *email;
    double salary;
    int *marks;
}my_struct;

int main(){
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    my_struct data;
    MPI_Datatype struct_type;

    int blocklengths[6] = {1,1,1,1,1,1};
    MPI_Aint displacement[6];
    MPI_Datatype types[6] = {MPI_CHAR, MPI_LONG, MPI_INT, MPI_STRING, MPI_DOUBLE, MPI_INT};

    displacement[0] = offsetof(my_struct,  name);
    displacement[1] = offsetof(my_struct,  prnNo);
    displacement[2] = offsetof(my_struct,  age);
    displacement[3] = offsetof(my_struct,  email);
    displacement[4] = offsetof(my_struct,  salary);
    displacement[5] = offsetof(my_struct,  marks);

    MPI_Type_create_struct(6, blocklengths, displacement, types, &struct_type);
    MPI_Type_commit(&struct_type);

    if(rank == 0){
        data.name = "Mac";
        data.prnNo = 026;
        data.age = 24;
        //data.email = malloc(sizeof(char))
        data.email = "mac@gmail.com";
        data.salary = 5800000;
        marks = malloc(sizeof(int) * 4);
        data.marks = [40, 20, 88, 66];

        MPI_Send(&data, 1, struct_type, 1, 0, MPI_COMM_WORLD);
        printf("process %d send struct: {name= %c, PRN_No= %ld, age=%d, email: %s, salary: %lf, marks: %d}\n", rank, data.name, data.prnNo, data.age, data.email, data.salary, data.marks);
    }else if(rank ==1){
        MPI_Recv(&data, 1, struct_type, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("process %d received struct: {name= %c, PRN_No= %ld, age=%d, email: %s, salary: %lf, marks: %d}\n", rank, data.name, data.prnNo, data.age, data.email, data.salary, data.marks);
    }

    MPI_Type_free(&struct_type);
    MPI_Finalize();

    return 0;
}