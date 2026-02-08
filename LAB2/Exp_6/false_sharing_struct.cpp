// Ankit Kumar | 102483012 | 3C75
// Exp 6a: False sharing demo - struct-based approach

#include <cstdio>
#include <vector>
#include <omp.h>

using namespace std;

const int PAD = 8;  // 64 bytes / 8 bytes per double

struct Plain {
    double val;
};

struct Spaced {
    double val;
    double _gap[PAD];
};

int main() {
    const long long reps = 100000000;
    int nt = omp_get_max_threads();
    
    vector<Plain> arr_plain(nt);
    vector<Spaced> arr_spaced(nt);
    for (int i = 0; i < nt; i++) { arr_plain[i].val = 0.0; arr_spaced[i].val = 0.0; }

    printf("%-20s %s\n", "Configuration", "Time (s)");
    printf("----------------------------------------\n");

    // without padding - cache lines shared between threads
    double t0 = omp_get_wtime();
    #pragma omp parallel num_threads(nt)
    {
        int id = omp_get_thread_num();
        for (long long i = 0; i < reps; i++)
            arr_plain[id].val += 1.0;
    }
    printf("%-20s %fs\n", "False Sharing:", omp_get_wtime() - t0);

    // with padding - each thread on separate cache line
    t0 = omp_get_wtime();
    #pragma omp parallel num_threads(nt)
    {
        int id = omp_get_thread_num();
        for (long long i = 0; i < reps; i++)
            arr_spaced[id].val += 1.0;
    }
    printf("%-20s %fs\n", "Padded (Fixed):", omp_get_wtime() - t0);

    return 0;
}