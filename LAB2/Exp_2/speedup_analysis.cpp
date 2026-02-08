// Ankit Kumar | 102483012 | 3C75
// Exp 2: Measuring speedup & efficiency for vector addition

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

double run_vec_add(long n, int num_threads) {
    double *a = new double[n];
    double *b = new double[n];
    double *c = new double[n];

    for (long i = 0; i < n; i++) {
        a[i] = 1.0;
        b[i] = 2.0;
    }

    double t_start = omp_get_wtime();
    #pragma omp parallel for num_threads(num_threads)
    for (long i = 0; i < n; i++)
        c[i] = a[i] + b[i];
    double elapsed = omp_get_wtime() - t_start;

    delete[] a;
    delete[] b;
    delete[] c;
    return elapsed;
}

int main() {
    long N = 10000000;
    int thread_counts[] = {1, 2, 4, 8, 16};
    int num_tests = 5;

    printf("%-10s %-12s %-10s %-10s\n", "Threads", "Time(s)", "Speedup", "Efficiency");
    printf("-------------------------------------------\n");

    double t_serial = run_vec_add(N, 1);
    printf("%-10d %-12f %-10.2f %-10.2f%%\n", 1, t_serial, 1.0, 100.0);

    for (int k = 1; k < num_tests; k++) {
        int p = thread_counts[k];
        double tp = run_vec_add(N, p);
        double speedup = t_serial / tp;
        double eff = (speedup / p) * 100.0;
        printf("%-10d %-12f %-10.2f %-10.2f%%\n", p, tp, speedup, eff);
    }
    return 0;
}
