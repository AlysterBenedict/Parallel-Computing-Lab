//Write an OpenMP program with OMP_SCHEDULE static that divides iterations into chunks. 
//Show which thread executes which iteration.

#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    printf("Enter number of iterations: ");
    scanf("%d", &n);

    // Schedule static with chunk size 2
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < n; i++) {
        int id = omp_get_thread_num();
        printf("Thread %d executing iteration %d\n", id, i);
    }
    return 0;
}