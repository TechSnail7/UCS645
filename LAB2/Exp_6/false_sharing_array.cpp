// Ankit Kumar | 102483012 | 3C75
// Exp 6b: False sharing with raw arrays - int version

#include <iostream>
#include <omp.h>

using namespace std;

const int NTHREADS = 8;
const int LOOP_COUNT = 100000000;
const int CACHELINE_INTS = 64 / sizeof(int);  // ints per cache line

int main() {
    volatile int sums_packed[NTHREADS];
    for (int i = 0; i < NTHREADS; i++) sums_packed[i] = 0;

    volatile int sums_spread[NTHREADS][CACHELINE_INTS];
    for (int i = 0; i < NTHREADS; i++) sums_spread[i][0] = 0;

    // packed array - all values on same/adjacent cache lines
    double t0 = omp_get_wtime();
    #pragma omp parallel num_threads(NTHREADS)
    {
        int id = omp_get_thread_num();
        for (int i = 0; i < LOOP_COUNT; i++)
            sums_packed[id]++;
    }
    double time_packed = omp_get_wtime() - t0;

    // spread array - each value on its own cache line
    t0 = omp_get_wtime();
    #pragma omp parallel num_threads(NTHREADS)
    {
        int id = omp_get_thread_num();
        for (int i = 0; i < LOOP_COUNT; i++)
            sums_spread[id][0]++;
    }
    double time_spread = omp_get_wtime() - t0;

    cout << "Unpadded Time: " << time_packed << "s" << endl;
    cout << "Padded Time:   " << time_spread << "s" << endl;

    return 0;
}