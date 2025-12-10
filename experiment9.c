//Write an MPI program to demonstrate MPI_Reduce and MPI_Allreduce (MAX, MIN, SUM, PROD).

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, val, sum, max, all_sum;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    val = rank + 1; // 1, 2, 3...

    // Reduce to Root
    MPI_Reduce(&val, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&val, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Reduce Results: Sum=%d, Max=%d\n", sum, max);
    }

    // AllReduce (Result to everyone)
    MPI_Allreduce(&val, &all_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    printf("Process %d Sees All_Sum=%d\n", rank, all_sum);

    MPI_Finalize();
    return 0;
}

