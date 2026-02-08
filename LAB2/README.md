# UCS645 — Parallel and Distributed Computing
**Ankit Kumar | 102483012 | 3C75**

## Lab 2 — OpenMP Experiments

Seven experiments covering the main performance aspects of OpenMP programs:

| # | Topic | File |
|---|-------|------|
| 1 | Basic parallel vector add timing | `vec_add.cpp` |
| 2 | Speedup, efficiency, throughput | `speedup_analysis.cpp` |
| 3 | Strong & weak scaling (pi integration) | `scaling_test.cpp` |
| 4 | Scheduling policies & load imbalance | `sched_imbalance.cpp` |
| 5 | Critical vs reduction overhead | `sync_overhead.cpp` |
| 6 | False sharing with structs & arrays | `false_sharing_struct.cpp`, `false_sharing_array.cpp` |
| 7 | Memory bandwidth saturation (triad) | `triad_bandwidth.cpp` |

Each experiment folder has the source code, a README with results/graphs, and the generated plots.

### How to compile

```
g++ -O3 -fopenmp filename.cpp -o output
```

Some files need `-std=c++0x` if using older GCC.

### How to run

Most programs sweep through thread counts automatically. For manual control:
```
set OMP_NUM_THREADS=8
output.exe
```
