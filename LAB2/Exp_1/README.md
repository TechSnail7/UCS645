## Experiment 1 — Execution Time Measurement

Ran `vec_add.cpp` (parallel vector addition, N=10M) with different OMP_NUM_THREADS values.

| Threads | Time (seconds) |
|---------|----------------|
| 1       | 0.032000       |
| 2       | 0.020000       |
| 4       | 0.015000       |
| 8       | 0.014000       |
| 16      | 0.012000       |

Time drops sharply going from 1 to 4 threads, then the gains flatten out. This makes sense since the vector add is memory-bound — once we saturate the memory bus there's no point adding more threads.
