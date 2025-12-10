//Write an MPI program to demonstrate MPI_Send and MPI_Recv.



#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, size, number;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        number = 100;
        printf("Process 0 Sending number %d to process 1\n", number);
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received number %d from Process 0\n", number);
    }

    MPI_Finalize();
    return 0;
}