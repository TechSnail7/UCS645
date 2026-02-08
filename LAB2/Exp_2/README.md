## Experiment 2 — Speedup, Efficiency & Throughput

Taking the times from the vector add runs (`speedup_analysis.cpp`, N=10M), I computed speedup, efficiency and throughput to see how well the parallelism actually helps.

**Formulas:**
- Speedup: S(p) = T₁ / Tₚ
- Efficiency: E(p) = S(p) / p
- Throughput: N / Tₚ


Where T₁ is the single-thread time, Tₚ is time with p threads, N = 10,000,000.

---

### Recorded Times

| Threads | Time (s)      |
|---------|---------------|
| 1       | 0.032000      |
| 2       | 0.020000      |
| 4       | 0.013000      |
| 8       | 0.012000      |
| 16      | 0.013000      |

---

### Speedup

| Threads | Time (s) | Speedup |
|---------|----------|---------|
| 1       | 0.032000 | 1.00    |
| 2       | 0.020000 | 1.60    |
| 4       | 0.013000 | 2.46    |
| 8       | 0.012000 | 2.67    |
| 16      | 0.013000 | 2.46    |

---

### Efficiency

| Threads | Speedup | Efficiency |
|---------|----------|------------|
| 1       | 1.00     | 1.00 (100%) |
| 2       | 1.60     | 0.80 (80%) |
| 4       | 2.46     | 0.62 (62%) |
| 8       | 2.67     | 0.33 (33%) |
| 16      | 2.46     | 0.15 (15%) |

---

### Throughput (N / Tₚ)


| Threads | Time (s) | Throughput (elements/sec) |
|---------|----------|----------------------------|
| 1       | 0.032000 | 312,500,000 |
| 2       | 0.020000 | 500,000,000 |
| 4       | 0.013000 | 769,230,769 |
| 8       | 0.012000 | 833,333,333 |
| 16      | 0.013000 | 769,230,769 |

---

### What I noticed

- Best speedup is 2.67x at 8 threads — far from the ideal 8x. Clearly memory-bound.
- At 16 threads things get slightly *worse* (2.46x) because the thread overhead starts to outweigh the benefit.
- Efficiency drops to 15% at 16 threads — most of the cores are just waiting on memory.
- Throughput peaks at 8 threads (~833M elements/s) then goes back down.

Basically this is a classic memory-wall situation. Vector addition does almost no computation per element so the bottleneck is purely how fast we can read/write RAM.

### Graphs

![Execution Time v/s Threads](./Graph1.png)
![Speedup v/s Threads](./Graph2.png)
![Efficiency v/s Threads](./Graph3.png)

