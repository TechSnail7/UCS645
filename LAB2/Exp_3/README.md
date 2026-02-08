## Experiment 3 — Strong & Weak Scaling

Numerical integration for pi is used to test two types of scaling:

- **Strong scaling** — fixed problem size (100M steps), add more threads.
- **Weak scaling** — keep work-per-thread constant (100M steps each), increase threads.

---

### Strong Scaling

| Threads | Time (s) | Speedup |
|---------|----------|---------|
| 1       | 9.8370   | 1.00x   |
| 4       | 2.2490   | 4.37x   |
| 8       | 1.1700   | 8.41x   |
| 12      | 0.7860   | 12.52x  |
| 16      | 0.6380   | 15.42x  |
| 20      | 0.6250   | 15.74x  |

Scales pretty well up to 16 threads (15.42x out of 16x ideal). After that it flattens — going from 16 to 20 threads barely helps (15.42→15.74). Probably hitting scheduling overhead and memory contention at that point.

![Execution Time v/s Threads](./Graph1.png)
![Speedup v/s Threads](./Graph2.png)

---

### Weak Scaling

| Threads | Total Work  | Time (s) | Efficiency |
|---------|-------------|----------|------------|
| 1       | 100000000   | 2.0040   | 100%       |
| 4       | 400000000   | 1.7820   | 112.46%    |
| 8       | 800000000   | 1.8530   | 108.15%    |
| 12      | 1200000000  | 1.9080   | 105.03%    |
| 16      | 1600000000  | 2.0390   | 98.28%     |
| 20      | 2000000000  | 2.5820   | 77.61%     |

Efficiency is actually above 100% at low thread counts — probably cache warming effects. Stays flat until 16 threads, then at 20 it drops to ~78%. The extra threads start fighting over memory bandwidth.

![Execution Time v/s Threads](./Graph3.png)
![Efficiency v/s Threads](./Graph4.png)

---

### Summary

Strong scaling is great here — nearly linear up to the core count. Weak scaling holds up until memory pressure becomes an issue at 20 threads. Overall the integration workload scales well because each thread does independent work with no shared writes.
