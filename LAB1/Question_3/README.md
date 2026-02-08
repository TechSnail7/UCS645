# Question 3: Pi (π) Calculation

> Numerical Integration with OpenMP Reduction

---

## 👤 Student Information

| Field | Details |
|-------|---------|
| **Name** | Ankit Kumar |
| **Roll No.** | 102483012 |
| **Group** | 3C75 |

---

## 📝 Problem Statement

Approximate the value of π using numerical integration:

$$\pi = \int_0^1 \frac{4}{1 + x^2} dx$$

### Parameters
- **Integration Method:** Midpoint rule (Riemann sum)
- **Number of Steps:** 500,000,000 (500M)
- **Objective:** Parallel computation with reduction

---

## 🔬 Mathematical Background

### Derivation

The function $f(x) = \frac{4}{1+x^2}$ integrated from 0 to 1 equals π.

**Why?** Consider the derivative of $\arctan(x)$:

$$\frac{d}{dx}\arctan(x) = \frac{1}{1+x^2}$$

Therefore:
$$\int_0^1 \frac{4}{1+x^2}dx = 4[\arctan(x)]_0^1 = 4\left(\frac{\pi}{4} - 0\right) = \pi$$

### Numerical Approximation

Using midpoint rule with N rectangles:

$$\pi \approx \sum_{i=0}^{N-1} f(x_i) \cdot \Delta x$$

where:
- $x_i = (i + 0.5) \cdot \Delta x$ (midpoint of rectangle)
- $\Delta x = \frac{1}{N}$ (width of each rectangle)

---

## 🔬 Implementation

### OpenMP Parallelization

```c
double step = 1.0 / NUM_STEPS;
double sum = 0.0;

#pragma omp parallel for reduction(+:sum) num_threads(n) schedule(static)
for (long i = 0; i < NUM_STEPS; i++) {
    double x = (i + 0.5) * step;
    sum += 4.0 / (1.0 + x * x);
}

double pi = step * sum;
```

### Key Features

- **`reduction(+:sum)`** - Each thread maintains private sum, combined at end
- **Race-condition free** - No explicit locks needed
- **Automatic synchronization** - OpenMP handles thread coordination
- **High precision** - 500M steps ensure accuracy < 10⁻¹²

---

## 📊 Experimental Results

**Test Environment:** Intel Core i5-1240P (12 cores, 16 threads)  
**Reference Value:** π = 3.141592653589793...

| Threads | Time (sec) | Speedup | Efficiency | Computed π | Error |
|:-------:|:----------:|:-------:|:----------:|:----------:|:-----:|
| 1 | 0.758 | 1.00x | 100.0% | 3.141592653589814 | 2.1e-14 |
| 2 | 0.346 | 2.19x | 109.5% | 3.141592653589770 | 2.3e-14 |
| 4 | 0.183 | 4.14x | 103.6% | 3.141592653589861 | 6.8e-14 |
| 8 | 0.145 | 5.23x | 65.4% | 3.141592653589968 | 1.8e-13 |
| 12 | 0.125 | 6.06x | 50.5% | 3.141592653589798 | 4.4e-15 |
| 16 | 0.092 | **8.24x** | 51.5% | 3.141592653589879 | 8.7e-14 |

**All computed values accurate to 12+ decimal places** ✓

---

## 💡 Analysis

### Performance Characteristics

**Peak Performance:**
- Maximum speedup: **8.24x** at 16 threads
- Parallel efficiency: **51.5%** at 16 threads
- Good scalability compared to memory-bound operations

### Why Not Linear Speedup?

#### 1. Reduction Overhead
- Each thread maintains private `sum` variable
- At barrier, all partial sums must be combined
- Synchronization cost increases with thread count
- Binary tree reduction: O(log n) overhead

#### 2. Memory Bandwidth
- Still some memory contention for loop variables
- Though mostly compute-bound (better than DAXPY)

#### 3. Thread Management
- Fork-join overhead per parallel region
- Thread creation and synchronization costs
- OS scheduling on hybrid P-core/E-core architecture

### Accuracy Analysis

All results maintain **< 10⁻¹² absolute error**:
- 500M steps provide excellent numerical precision
- Parallel execution doesn't affect accuracy
- IEEE 754 double precision sufficient
- Order of summation slightly affects floating-point rounding

---

## 📈 Speedup Visualization

```
Serial (1 thread):     ████████████████ 0.758s
Parallel (16 threads): ██ 0.092s

Speedup: 8.24x faster! 🚀
Time Saved: 87.9%
```

---

## 🔧 Compilation & Execution

```bash
# Compile with optimization
gcc -fopenmp Q3.c -o Q3 -O2

# Run (tests multiple thread counts automatically)
./Q3

# Or specify thread count
OMP_NUM_THREADS=8 ./Q3
```

---

## 📁 Files

| File | Description |
|------|-------------|
| `Q3.c` | Source code with OpenMP reduction |
| `README.md` | This documentation |

---

## 🎯 Key Takeaways

1. **Reduction clause** provides safe parallel accumulation
2. **Good scalability** for compute-intensive reduction operations
3. **Synchronization overhead** limits efficiency at high thread counts
4. **Numerical accuracy** maintained in parallel execution
5. **Better than memory-bound** but not as good as pure compute-bound

---

## 📚 Concepts Demonstrated

- OpenMP reduction clause
- Numerical integration (Riemann sum/midpoint rule)
- Thread synchronization and barriers
- Floating-point accuracy in parallel computing
- Compute-bound operations with some overhead
- Performance vs accuracy tradeoffs

---

## 🔍 Comparison with Other Questions

| Question | Type | Peak Speedup | Efficiency |
|----------|------|:------------:|:----------:|
| Q1 DAXPY | Memory-bound | 1.79x | 44.7% |
| Q2 MatMul | Compute-bound | 10.72x | 67.0% |
| **Q3 Pi** | **Reduction** | **8.24x** | **51.5%** |

Pi calculation falls between memory-bound and pure compute-bound operations due to reduction overhead.

---

**Completed by:** Ankit Kumar (102483012) - Group 3C75
