## Experiment 7 — Memory Bandwidth (Triad)

Uses the triad kernel `A[i] = B[i] + s * C[i]` to measure how much memory bandwidth we can actually use as thread count goes up.

Bandwidth formula: `(3 × N × sizeof(double)) / time`
(3 because we read B, read C, write A)

---

### Results

| Cores | Time (s) | BW (GB/s) | Speedup |
|-------|----------|-----------|---------|
| 1     | 0.016    | 15.00     | 1.00x   |
| 2     | 0.010    | 24.00     | 1.60x   |
| 3     | 0.009    | 26.67     | 1.78x   |
| 4     | 0.009    | 26.67     | 1.78x   |
| 5     | 0.008    | 30.00     | 2.00x   |
| 6     | 0.007    | 34.29     | 2.29x   |
| 7     | 0.007    | 34.29     | 2.29x   |
| 8     | 0.007    | 34.29     | 2.29x   |
| 9     | 0.007    | 34.29     | 2.29x   |
| 10    | 0.007    | 34.29     | 2.29x   |
| 11    | 0.008    | 30.00     | 2.00x   |
| 12    | 0.008    | 30.00     | 2.00x   |
| 13    | 0.009    | 26.67     | 1.78x   |
| 14    | 0.007    | 34.29     | 2.29x   |
| 15    | 0.007    | 34.29     | 2.29x   |
| 16    | 0.007    | 34.29     | 2.29x   |

Bandwidth tops out around **34.3 GB/s** starting at 6 cores. Adding more threads after that doesn't help — we've hit the memory wall. Max speedup is only 2.29x even with 16 cores.

Some dips at 11–13 cores are probably due to NUMA effects or OS scheduling noise.

![Execution Time vs Cores](./Graph1.png)
![Bandwidth vs Cores](./Graph2.png)
![Speedup vs Cores](./Graph3.png)

---

### Takeaway

Triad is purely memory-bound. No amount of extra cores can push past the DRAM bandwidth limit. This is why compute-heavy kernels scale much better than memory-heavy ones.

