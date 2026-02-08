// Ankit Kumar | 102483012 | 3C75
// Exp 3: Strong vs weak scaling using pi estimation

#include <iostream>
#include <omp.h>
#include <vector>
#include <iomanip>
using namespace std;

// returns the wall time for computing pi with given steps and threads
double pi_time(long long steps, int nthreads) {
    double h = 1.0 / (double)steps;
    double total = 0.0;
    double t0 = omp_get_wtime();

    #pragma omp parallel num_threads(nthreads)
    {
        double x, partial = 0.0;
        #pragma omp for
        for (long long i = 0; i < steps; i++) {
            x = (i + 0.5) * h;
            partial += 4.0 / (1.0 + x * x);
        }
        #pragma omp atomic
        total += partial;
    }
    return omp_get_wtime() - t0;
}

int main() {
    int max_cores = 16;
    long long work_per_thread = 50000000;  // base work for weak scaling
    long long fixed_steps = 100000000;     // total work for strong scaling

    cout << fixed << setprecision(4);

    // ---- strong scaling: same total work, more threads ----
    cout << "--- STRONG SCALING ---" << endl;
    cout << left << setw(12) << "Cores" << setw(15) << "Time (s)" << "Speedup" << endl;

    double t1 = pi_time(fixed_steps, 1);
    cout << setw(12) << "1 (Serial)" << setw(15) << t1 << "1.00x" << endl;

    for (int n = 4; n <= max_cores; n += 4) {
        double tp = pi_time(fixed_steps, n);
        cout << setw(4) << n << " Cores" << "   "
             << setw(15) << tp << (t1 / tp) << "x" << endl;
    }

    // ---- weak scaling: work grows with thread count ----
    cout << "\n--- WEAK SCALING ---" << endl;
    cout << left << setw(12) << "Cores" << setw(15) << "Total Work"
         << setw(15) << "Time (s)" << "Efficiency" << endl;

    double t_base = pi_time(work_per_thread, 1);
    cout << setw(12) << "1 (Serial)" << setw(15) << work_per_thread
         << setw(15) << t_base << "100%" << endl;

    for (int n = 4; n <= max_cores; n += 4) {
        long long total_work = work_per_thread * n;
        double tp = pi_time(total_work, n);
        double eff = (t_base / tp) * 100.0;
        cout << setw(4) << n << " Cores" << "   "
             << setw(15) << total_work
             << setw(15) << tp
             << eff << "%" << endl;
    }

    return 0;
}
