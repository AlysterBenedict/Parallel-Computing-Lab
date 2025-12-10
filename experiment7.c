//Write an MPI program to demonstrate the Broadcast operation

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, number;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        number = 50;
        printf("Process 0 broadcasting number %d\n", number);
    }

    // Root (0) broadcasts to all
    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank != 0) {
        printf("Process %d received number %d\n", rank, number);
    }

    MPI_Finalize();
    return 0;
}