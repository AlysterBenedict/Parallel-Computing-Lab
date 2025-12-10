//Write an MPI program to demonstrate deadlock in point-to-point communication and avoid it by changing the call sequence

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, n = 123;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Deadlock Avoidance Sequence
    if (rank == 0) {
        MPI_Send(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 0 got %d\n", n);
    } else if (rank == 1) {
        // Safe Order: Recv first, then Send
        MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process 1 got %d\n", n);
    }

    MPI_Finalize();
    return 0;
}