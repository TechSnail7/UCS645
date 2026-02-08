// Ankit Kumar | 102483012 | 3C75
// Exp 7: Triad kernel (A = B + s*C) to measure memory bandwidth saturation

#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    long long N = 10000000;
    vector<double> A(N, 0.0), B(N, 1.1), C(N, 2.2);
    double s = 3.3;

    int max_threads = omp_get_max_threads();
    
    printf("Memory Bandwidth & Scalability Test (Triad Kernel)\n");
    printf("%-10s %-15s %-15s %s\n", "Cores", "Time (s)", "BW (GB/s)", "Speedup");
    printf("-------------------------------------------------------\n");

    double t_serial = 0;

    for (int threads = 1; threads <= max_threads; threads++) {
        double start = omp_get_wtime();

        // A = B + s*C
        #pragma omp parallel for num_threads(threads)
        for (long long i = 0; i < N; i++) {
            A[i] = B[i] + s * C[i];
        }

        double end = omp_get_wtime();
        double Tp = end - start;

        if (threads == 1) t_serial = Tp;

        // 3 arrays x N elements x 8 bytes each
        double data_gb = (3.0 * N * sizeof(double)) / 1e9;
        double BW = data_gb / Tp;

        printf("%-10d %-15.6f %-15.4f %.2fx\n", threads, Tp, BW, t_serial / Tp);
    }

    return 0;
}