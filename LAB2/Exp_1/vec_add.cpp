// Ankit Kumar | 102483012 | 3C75
// Exp 1: Basic parallel vector addition timing

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const long SIZE = 10000000;

    double *x = new double[SIZE];
    double *y = new double[SIZE];
    double *result = new double[SIZE];

    for (long i = 0; i < SIZE; i++) {
        x[i] = 1.0;
        y[i] = 1.0;
    }

    int nthreads = omp_get_max_threads();
    printf("Threads: %d\n", nthreads);

    double t1 = omp_get_wtime();
    #pragma omp parallel for
    for (long i = 0; i < SIZE; i++)
        result[i] = x[i] + y[i];
    double t2 = omp_get_wtime();

    printf("Time = %f seconds\n", t2 - t1);

    delete[] x;
    delete[] y;
    delete[] result;
    return 0;
}
