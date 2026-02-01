/*
 * DAXPY Operation - Double precision A*X Plus Y
 * Name: Ankit Kumar | Roll No: 102483012 | Group: 3C75
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define VECTOR_SIZE (1 << 16)
#define SCALAR_A 2.5
#define NUM_ITERATIONS 10000

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num_threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_threads = atoi(argv[1]);
    if (num_threads < 1) {
        fprintf(stderr, "Error: Thread count must be positive\n");
        return EXIT_FAILURE;
    }
    
    double *vec_X = (double*)malloc(VECTOR_SIZE * sizeof(double));
    double *vec_Y = (double*)malloc(VECTOR_SIZE * sizeof(double));
    
    if (vec_X == NULL || vec_Y == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < VECTOR_SIZE; i++) {
        vec_X[i] = (double)(i % 100) / 100.0;
        vec_Y[i] = (double)(i % 50) / 50.0;
    }

    double time_start = omp_get_wtime();

    for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
        #pragma omp parallel for num_threads(num_threads) schedule(static)
        for (int i = 0; i < VECTOR_SIZE; i++) {
            vec_X[i] = SCALAR_A * vec_X[i] + vec_Y[i];
        }
    }

    double time_end = omp_get_wtime();
    double elapsed = time_end - time_start;

    printf("Threads: %2d | Execution Time: %.6f seconds\n", num_threads, elapsed);

    free(vec_X);
    free(vec_Y);

    return EXIT_SUCCESS;
}


