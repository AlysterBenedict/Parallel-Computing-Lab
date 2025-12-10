//Write an OpenMP program to sort an array of elements using Merge Sort. 
//Implement both Sequential and Parallel versions and record the difference in execution time.

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Merging Logic
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// 1. Sequential Sort
void sequentialMergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        sequentialMergeSort(arr, l, m);
        sequentialMergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 2. Parallel Sort
void parallelMergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            parallelMergeSort(arr, l, m);
            #pragma omp section
            parallelMergeSort(arr, m + 1, r);
        }
        merge(arr, l, m, r);
    }
}

int main() {
    int n = 10000;
    int *arr = (int*)malloc(n * sizeof(int));
    int *arr_copy = (int*)malloc(n * sizeof(int));
    
    for(int i=0; i<n; i++) {
        arr[i] = rand() % 1000;
        arr_copy[i] = arr[i];
    }

    double start = omp_get_wtime();
    sequentialMergeSort(arr, 0, n - 1);
    printf("Sequential Time: %f Seconds\n", omp_get_wtime() - start);

    start = omp_get_wtime();
    parallelMergeSort(arr_copy, 0, n - 1);
    printf("Parallel Time: %f Seconds\n", omp_get_wtime() - start);

    return 0;
}