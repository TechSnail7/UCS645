/*
 * Matrix Multiplication - 2D Threading (Collapsed Loop Parallelization)
 * Name: Ankit Kumar | Roll No: 102483012 | Group: 3C75
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MATRIX_DIM 1000

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

    static double mat_A[MATRIX_DIM][MATRIX_DIM];
    static double mat_B[MATRIX_DIM][MATRIX_DIM];
    static double mat_C[MATRIX_DIM][MATRIX_DIM];

    for (int i = 0; i < MATRIX_DIM; i++) {
        for (int j = 0; j < MATRIX_DIM; j++) {
            mat_A[i][j] = (double)((i + j) % 10) / 10.0;
            mat_B[i][j] = (double)((i * j) % 10) / 10.0;
            mat_C[i][j] = 0.0;
        }
    }

    double time_start = omp_get_wtime();

    #pragma omp parallel for collapse(2) num_threads(num_threads) schedule(static)
    for (int i = 0; i < MATRIX_DIM; i++) {
        for (int j = 0; j < MATRIX_DIM; j++) {
            double sum = 0.0;
            for (int k = 0; k < MATRIX_DIM; k++) {
                sum += mat_A[i][k] * mat_B[k][j];
            }
            mat_C[i][j] = sum;
        }
    }

    double time_end = omp_get_wtime();
    double elapsed = time_end - time_start;

    printf("[2D Threading] Threads: %2d | Execution Time: %.6f seconds\n", 
           num_threads, elapsed);

    return EXIT_SUCCESS;
}
