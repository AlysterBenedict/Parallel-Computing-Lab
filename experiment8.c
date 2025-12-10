//Write an MPI program to demonstrate MPI_Scatter and MPI_Gather.

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, size, recv_val;
    int send_data[4] = {10, 20, 30, 40}; // Assuming 4 processes
    int gathered_data[4];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Scatter: Root distributes 1 integer to each process
    MPI_Scatter(send_data, 1, MPI_INT, &recv_val, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    // Modify: Add rank to received value
    recv_val += rank;

    // Gather: Root collects modified values
    MPI_Gather(&recv_val, 1, MPI_INT, gathered_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Gathered data in root:\n");
        for (int i = 0; i < size; i++) {
            printf("Data[%d] = %d\n", i, gathered_data[i]);
        }
    }

    MPI_Finalize();
    return 0;
}