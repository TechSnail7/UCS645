// Ankit Kumar | 102483012 | 3C75
// Exp 4: Comparing scheduling strategies under uneven workload

#include <iostream>
#include <vector>
#include <omp.h>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

void do_work(int idx) {
    volatile double val = 0;
    long long iters = (idx + 1) * 10000LL;
    for (long long j = 0; j < iters; ++j)
        val += sin((double)j) * cos((double)j);
}

void measure_imbalance(string sched_name, int n_threads, int N) {
    vector<double> thread_times(n_threads, 0.0);
    double wall_start = omp_get_wtime();

    #pragma omp parallel num_threads(n_threads)
    {
        int tid = omp_get_thread_num();
        double t0 = omp_get_wtime();

        if (sched_name == "static") {
            #pragma omp for schedule(static)
            for (int i = 0; i < N; i++) do_work(i);
        } else if (sched_name == "dynamic,4") {
            #pragma omp for schedule(dynamic, 4)
            for (int i = 0; i < N; i++) do_work(i);
        } else if (sched_name == "guided") {
            #pragma omp for schedule(guided)
            for (int i = 0; i < N; i++) do_work(i);
        }

        thread_times[tid] = omp_get_wtime() - t0;
    }
    double end_wall = omp_get_wtime();
    double t_max = *max_element(thread_times.begin(), thread_times.end());
    double t_sum = accumulate(thread_times.begin(), thread_times.end(), 0.0);
    double t_avg = t_sum / n_threads;
    double imb = (t_max - t_avg) / t_avg;

    cout << left << setw(15) << sched_name 
         << setw(18) << t_max
         << setw(18) << t_avg
         << fixed << setprecision(2) << (imb * 100) << "%" << endl;
}
int main() {
    int N = 200; // Total iterations
    int n_threads = omp_get_max_threads();
    cout << "Running on " << n_threads << " threads...\n";
    cout << fixed << setprecision(6);
    cout << left << setw(15) << "Schedule" 
         << setw(18) << "T_max (s)" 
         << setw(18) << "T_avg (s)" 
         << "Imbalance (%)" << endl;
    cout << string(55, '-') << endl;
    measure_imbalance("static", n_threads, N);
    measure_imbalance("dynamic,4", n_threads, N);
    measure_imbalance("guided", n_threads, N);
    return 0;
}