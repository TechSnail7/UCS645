// Ankit Kumar | 102483012 | 3C75
// Exp 5: Critical section vs reduction - measuring sync cost

#include <iostream>
#include <omp.h>
#include <iomanip>
using namespace std;

void compare_sync(long long n) {
    double sum_crit = 0.0, sum_red = 0.0;

    // critical section approach
    double t0 = omp_get_wtime();
    #pragma omp parallel for
    for (long long i = 0; i < n; i++) {
        #pragma omp critical
        { sum_crit += 1.0; }
    }
    double time_crit = omp_get_wtime() - t0;

    // reduction approach
    t0 = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum_red)
    for (long long i = 0; i < n; i++)
        sum_red += 1.0;
    double time_red = omp_get_wtime() - t0;

    cout << left << setw(20) << "Method" << "Time (s)" << endl;
    cout << "------------------------------------" << endl;
    cout << setw(20) << "Critical Section" << time_crit << "s" << endl;
    cout << setw(20) << "Reduction" << time_red << "s" << endl;
    if (time_red > 0)
        cout << "\nOverhead Factor: " << (time_crit / time_red) << "x slower" << endl;
}
int main() {
    compare_sync(10000000);
    return 0;
}