/*
 * Pi Calculation using Numerical Integration (Midpoint Rule)
 * Name: Ankit Kumar | Roll No: 102483012 | Group: 3C75
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_STEPS 500000000

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

    double step_size = 1.0 / (double)NUM_STEPS;
    double partial_sum = 0.0;

    double time_start = omp_get_wtime();

    #pragma omp parallel for num_threads(num_threads) reduction(+:partial_sum) schedule(static)
    for (long i = 0; i < NUM_STEPS; i++) {
        double x_midpoint = (i + 0.5) * step_size;
        double rectangle_height = 4.0 / (1.0 + x_midpoint * x_midpoint);
        partial_sum += rectangle_height;
    }

    double computed_pi = step_size * partial_sum;
    double time_end = omp_get_wtime();
    double elapsed = time_end - time_start;

    printf("Threads: %2d | Computed pi: %.15f | Execution Time: %.6f seconds\n", 
           num_threads, computed_pi, elapsed);

    return EXIT_SUCCESS;
}
