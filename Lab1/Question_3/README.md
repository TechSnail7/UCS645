# 🥧 Question 3: Pi (π) Calculation

> **Numerical Integration with OpenMP Reduction**

---

## 📝 Problem Statement

Approximate the value of π using numerical integration:

$$\pi = \int_0^1 \frac{4}{1 + x^2} dx$$

This is approximated as a sum of rectangle areas using the midpoint rule.

---

## 🔬 Implementation Details

### Mathematical Basis

The function $f(x) = \frac{4}{1+x^2}$ integrated from 0 to 1 equals π.

Using midpoint rule with N rectangles:
$$\pi \approx \sum_{i=0}^{N-1} f(x_i) \cdot \Delta x$$

where $x_i = (i + 0.5) \cdot \Delta x$ and $\Delta x = \frac{1}{N}$

### OpenMP Implementation

```c
#pragma omp parallel for reduction(+:sum) num_threads(n) schedule(static)
for (long i = 0; i < NUM_STEPS; i++) {
    double x = (i + 0.5) * step;
    sum += 4.0 / (1.0 + x * x);
}
pi = step * sum;
```

### Key Features
- **Reduction Clause:** Safely accumulates partial sums
- **No Race Conditions:** Each thread maintains private sum
- **High Precision:** 500 million integration steps

---

## 📊 Experimental Results

**Test Environment:** Intel Core i5-1240P (12 cores, 16 threads)

| Threads | Time (sec) | Speedup | Computed π |
|:-------:|:----------:|:-------:|:----------:|
| 1 | 0.758 | 1.00x | 3.141592653589814 |
| 2 | 0.346 | 2.19x | 3.141592653589770 |
| 4 | 0.183 | 4.14x | 3.141592653589861 |
| 6 | 0.154 | 4.92x | 3.141592653589641 |
| 8 | 0.145 | 5.23x | 3.141592653589968 |
| 10 | 0.118 | 6.42x | 3.141592653589968 |
| 12 | 0.125 | 6.06x | 3.141592653589798 |
| 14 | 0.112 | 6.77x | 3.141592653589800 |
| 16 | 0.092 | **8.24x** | 3.141592653589879 |

**Reference:** π = 3.141592653589793...

![Speedup vs Threads](./speedup_graph.png)

---

## 💡 Analysis

### Accuracy
- **Error:** < 10^-12 (excellent precision)
- **500M steps** ensure high numerical accuracy
- Consistent results across all thread counts

### Performance Characteristics

| Aspect | Observation |
|--------|-------------|
| **Scalability** | Good up to 16 threads |
| **Max Speedup** | 8.24x with 16 threads |
| **Efficiency** | ~51.5% parallel efficiency |

### Why Not Linear Speedup?

1. **Reduction Overhead**
   - Combining partial sums at thread join
   - Synchronization cost increases with threads

2. **Memory Bandwidth**
   - Still some memory contention
   - Though mostly compute-bound

3. **Thread Management**
   - Fork-join overhead per parallel region
   - Scheduling and synchronization costs

### Comparison: Serial vs Parallel

```
Serial (1 thread):   0.758 seconds
Parallel (16 threads): 0.092 seconds
                      ─────────────────
Speedup:             8.24x faster! 🚀
```

---

## 🔧 Build & Execute

```bash
# Compile
gcc -fopenmp Q3.c -o Q3.exe -O2

# Run with N threads
./Q3.exe <num_threads>

# Example
./Q3.exe 8
```

---

## 📁 Files

| File | Description |
|------|-------------|
| `Q3.c` | Source with OpenMP reduction |
| `Q3.exe` | Compiled executable |
| `README.md` | This documentation |

---

## 🎯 Key Takeaways

1. **Reduction** is essential for parallel summation
2. Numerical integration is **embarrassingly parallel**
3. OpenMP handles partial sum combination automatically
4. Good speedup achieved with minimal code changes

---

**Ankit Kumar** | 102483012 | 3C75
