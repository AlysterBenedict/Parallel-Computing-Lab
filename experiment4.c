//Write an OpenMP program to find prime numbers from 1 to $N$ using the parallel for directive.
//Record both Serial and Parallel execution times.

#include <stdio.h>
#include <math.h>
#include <omp.h>

int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n = 200; // Input size
    double start, end;


    // 1. Serial Execution
    start = omp_get_wtime();
    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) { printf("%d ", i); }
    }
    end = omp_get_wtime();
    printf("Serial Time: %f Seconds\n", end - start);

    // 2. Parallel Execution
    start = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic,4)
    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) { printf("%d ", i); }
    }
    end = omp_get_wtime();
    printf("\nParallel Time: %f Seconds\n", end - start);

    return 0;
}