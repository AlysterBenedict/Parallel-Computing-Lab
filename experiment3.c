//Write an OpenMP program to calculate Fibonacci numbers using tasks/sections.

#include <stdio.h>
#include <omp.h>

int fib(int n) {
    int x, y;
    if (n < 2) return n;

    #pragma omp task shared(x)
    x = fib(n - 1);
    
    #pragma omp task shared(y)
    y = fib(n - 2);
    
    #pragma omp taskwait
    return x + y;
}

int main() {
    int n, result;
    printf("Enter no. of Fibonacci Terms: ");
    scanf("%d", &n);

    #pragma omp parallel
    {
        #pragma omp single
        result = fib(n);
    }

    printf("Fibonacci Result (%dth term): %d\n", n, result);
    // Note: To print series, you loop this call.
    return 0;
}