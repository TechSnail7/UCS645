# Question 1: DAXPY Operation

> **D**ouble precision **A**·**X** **P**lus **Y** - Memory-Bound Parallel Operation

---

## 👤 Student Information

| Field | Details |
|-------|---------|
| **Name** | Ankit Kumar |
| **Roll No.** | 102483012 |
| **Group** | 3C75 |

---

## 📝 Problem Statement

Implement the DAXPY operation: **X[i] = a·X[i] + Y[i]**

### Parameters
- **Vector Size:** 2¹⁶ = 65,536 elements
- **Data Type:** Double precision (64-bit)
- **Iterations:** 10,000
- **Scalar (a):** 2.5
- **Objective:** Analyze speedup with varying thread counts

---

## 🔬 Implementation

### Algorithm
```c
for (i = 0 to N-1):
    X[i] = a * X[i] + Y[i]
```

### OpenMP Parallelization
```c
#pragma omp parallel for num_threads(n) schedule(static)
for (int i = 0; i < N; i++) {
    X[i] = a * X[i] + Y[i];
}
```

### Key Directives
- `parallel for` - Distributes iterations across threads
- `schedule(static)` - Equal chunks per thread
- `num_threads(n)` - Explicit thread count control

---

## 📊 Experimental Results

**Test Environment:** Intel Core i5-1240P (12 cores, 16 threads)

| Threads | Time (sec) | Speedup | Efficiency |
|:-------:|:----------:|:-------:|:----------:|
| 1 | 1.381 | 1.00x | 100.0% |
| 2 | 0.984 | 1.40x | 70.2% |
| 4 | 0.773 | **1.79x** | 44.7% |
| 6 | 0.862 | 1.60x | 26.7% |
| 8 | 0.983 | 1.40x | 17.6% |
| 10 | 0.974 | 1.42x | 14.2% |
| 12 | 0.922 | 1.50x | 12.5% |
| 16 | 1.116 | 1.24x | 7.7% |

---

## 💡 Analysis

### Performance Characteristics

**Peak Performance:**
- Optimal threads: **4**
- Maximum speedup: **1.79x**
- Parallel efficiency drops significantly beyond 4 threads

### Why Limited Scalability?

#### 1. Memory Bandwidth Bottleneck
- DAXPY is **memory-bound** (low arithmetic intensity)
- Arithmetic Intensity = 2 FLOPs / 3 memory operations ≈ 0.67
- Memory bus saturates quickly with multiple threads
- All threads compete for same memory bandwidth

#### 2. Cache Effects
- Multiple threads accessing vectors causes:
  - Cache line contention
  - False sharing between cores
  - Increased cache misses
- Cache thrashing degrades performance

#### 3. Thread Overhead
- Fork-join overhead per iteration set
- Context switching costs
- Thread management overhead exceeds computation benefit

### Performance Degradation Beyond 4 Threads

Adding more threads causes:
- **Memory bandwidth saturation** - No more bandwidth available
- **NUMA effects** - Hybrid P-core/E-core architecture
- **Synchronization overhead** - Thread coordination costs
- **Cache pollution** - More threads = worse cache utilization

---

## 🔧 Compilation & Execution

```bash
# Compile
gcc -fopenmp Q1.c -o Q1 -O0

# Run (tests multiple thread counts automatically)
./Q1

# Or specify thread count
OMP_NUM_THREADS=4 ./Q1
```

---

## 📁 Files

| File | Description |
|------|-------------|
| `Q1.c` | Source code with OpenMP |
| `README.md` | This documentation |

---

## 🎯 Key Takeaways

1. **Memory-bound operations don't scale well** with thread count
2. **Optimal thread count** is often much lower than available cores
3. **Adding more threads** can hurt performance due to contention
4. **Arithmetic intensity** is crucial for parallel scalability
5. **Cache effects** significantly impact memory-intensive operations

---

## 📚 Concepts Demonstrated

- OpenMP parallel for directive
- Static work scheduling
- Memory-bound vs compute-bound operations
- Amdahl's Law limitations
- Cache coherency effects in parallel code

---

**Completed by:** Ankit Kumar (102483012) - Group 3C75
