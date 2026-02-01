# ⚡ Question 1: DAXPY Operation

> **Double precision A*X Plus Y - Memory-Bound Parallel Operation**

---

## � Student Information

| Field | Details |
|-------|---------|
| **Name** | Ankit Kumar |
| **Roll No.** | 102483012 |
| **Group** | 3C75 |

---

## �📝 Problem Statement

Implement the DAXPY operation: `X[i] = a*X[i] + Y[i]`
- **Vector Size:** 2^16 (65,536 elements)
- **Data Type:** Double precision floating-point
- **Objective:** Analyze speedup with increasing thread counts

---

## 🔬 Implementation Details

### Algorithm
```
for i = 0 to N-1:
    X[i] = scalar_a * X[i] + Y[i]
```

### OpenMP Directives Used
- `#pragma omp parallel for` - Distributes loop iterations
- `schedule(static)` - Equal chunk sizes for each thread
- `num_threads(n)` - Controls thread count

### Key Parameters
| Parameter | Value |
|-----------|-------|
| Vector Size | 65,536 |
| Iterations | 10,000 |
| Scalar (a) | 2.5 |

---

## 📊 Experimental Results

**Test Environment:** Intel Core i5-1240P (12 cores, 16 threads)

| Threads | Time (sec) | Speedup |
|:-------:|:----------:|:-------:|
| 1 | 1.381 | 1.00x |
| 2 | 0.984 | 1.40x |
| 4 | 0.773 | **1.79x** |
| 6 | 0.862 | 1.60x |
| 8 | 0.983 | 1.40x |
| 10 | 0.974 | 1.42x |
| 12 | 0.922 | 1.50x |
| 14 | 0.964 | 1.43x |
| 16 | 1.116 | 1.24x |

![Speedup vs Threads](./speedup_graph.png)

---

## 💡 Analysis

### Peak Performance
- **Optimal Threads:** 4
- **Maximum Speedup:** 1.79x

### Why Limited Scalability?

1. **Memory Bandwidth Bottleneck**
   - DAXPY is memory-bound (low arithmetic intensity)
   - Only 3 memory ops per 2 FLOPs
   - Memory bus saturates quickly

2. **Cache Thrashing**
   - Multiple threads compete for cache lines
   - Increased cache misses with more threads

3. **Thread Overhead**
   - Fork-join overhead exceeds computation benefit
   - Short-lived parallel regions

### What Happens Beyond 4 Threads?

Performance **degrades** due to:
- Memory bandwidth saturation
- NUMA effects on hybrid architecture
- Context switching overhead

---

## 🔧 Build & Execute

```bash
# Compile
gcc -fopenmp Q1.c -o Q1.exe -O0

# Run with N threads
./Q1.exe <num_threads>
```

---

## 📁 Files

| File | Description |
|------|-------------|
| `Q1.c` | Source code with OpenMP parallelization |
| `Q1.exe` | Compiled executable |
| `README.md` | This documentation |

---

**Ankit Kumar** | 102483012 | 3C75
