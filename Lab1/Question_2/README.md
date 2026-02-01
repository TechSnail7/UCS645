# Question 2: Matrix Multiplication

> Parallel Matrix Multiplication with 1D and 2D Threading Strategies

---

## 👤 Student Information

| Field | Details |
|-------|---------|
| **Name** | Ankit Kumar |
| **Roll No.** | 102483012 |
| **Group** | 3C75 |

---

## 📝 Problem Statement

Implement parallel matrix multiplication **C = A × B** using two approaches:
- **Part 1:** 1D Threading (row-wise parallelization)
- **Part 2:** 2D Threading (collapsed loop parallelization)

### Parameters
- **Matrix Dimensions:** 1000 × 1000
- **Data Type:** Integer
- **Objective:** Compare 1D vs 2D threading strategies

---

## 🔬 Implementation Approaches

### Part 1: 1D Threading (Row-wise)

**Concept:** Parallelize outer loop only

```c
#pragma omp parallel for num_threads(n) schedule(static)
for (int i = 0; i < N; i++) {        // Parallelized
    for (int j = 0; j < N; j++) {    // Sequential
        for (int k = 0; k < N; k++) { // Sequential
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

**Work Distribution:** Each thread computes complete rows of C

**Advantages:**
- Simple implementation
- Good cache locality (row-major access)
- Low overhead

### Part 2: 2D Threading (Collapsed Loops)

**Concept:** Parallelize both outer loops together

```c
#pragma omp parallel for collapse(2) num_threads(n) schedule(static)
for (int i = 0; i < N; i++) {        // Parallelized
    for (int j = 0; j < N; j++) {    // Parallelized
        for (int k = 0; k < N; k++) { // Sequential
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

**Work Distribution:** Each thread computes individual elements of C

**Advantages:**
- Finer granularity
- Better load balancing for non-square matrices
- More parallel work available

---

## 📊 Experimental Results

**Test Environment:** Intel Core i5-1240P (12 cores, 16 threads)

### Part 1: 1D Threading Results

| Threads | Time (sec) | Speedup | Efficiency |
|:-------:|:----------:|:-------:|:----------:|
| 1 | 3.655 | 1.00x | 100.0% |
| 2 | 1.546 | 2.36x | 118.2% |
| 4 | 0.781 | 4.68x | 117.0% |
| 8 | 0.485 | 7.54x | 94.2% |
| 12 | 0.373 | 9.80x | 81.7% |
| 16 | 0.341 | **10.72x** | 67.0% |

### Part 2: 2D Threading Results

| Threads | Time (sec) | Speedup | Efficiency |
|:-------:|:----------:|:-------:|:----------:|
| 1 | 3.559 | 1.00x | 100.0% |
| 2 | 1.577 | 2.26x | 112.9% |
| 4 | 0.767 | 4.64x | 116.0% |
| 8 | 0.535 | 6.65x | 83.1% |
| 12 | 0.402 | 8.85x | 73.8% |
| 16 | 0.332 | **10.72x** | 67.0% |

---

## 💡 Analysis

### Performance Comparison

| Metric | 1D Threading | 2D Threading |
|--------|:------------:|:------------:|
| **Best Time** | 0.341s | 0.332s |
| **Max Speedup** | 10.72x | 10.72x |
| **Efficiency @ 16T** | 67.0% | 67.0% |
| **Scalability** | Excellent | Excellent |

### Key Observations

#### 1. Excellent Scalability
- Matrix multiplication is **compute-bound**
- High arithmetic intensity: O(N³) operations / O(N²) memory
- Near-linear speedup up to 10-12 threads
- Both strategies achieve ~10.72x speedup at 16 threads

#### 2. 1D vs 2D Strategy
- **Performance:** Nearly identical for square matrices
- **1D advantage:** Slightly better at low thread counts (2-4)
- **2D advantage:** Better granularity for load balancing
- **Cache behavior:** 1D has better spatial locality

#### 3. Super-linear Speedup (2-4 threads)
- Efficiency > 100% observed
- Caused by improved cache utilization
- Multiple threads → more cache available
- Better data locality with parallel execution

#### 4. Efficiency Degradation (>8 threads)
- Parallel efficiency drops from ~94% to 67%
- Caused by:
  - Thread synchronization overhead
  - Cache contention
  - Hybrid P-core/E-core performance variance

---

## 🎯 Work Partitioning Strategy

### 1D Threading
- **Granularity:** Coarse (entire rows)
- **Load Balance:** Good for square matrices
- **Best for:** Regular, predictable workloads

### 2D Threading
- **Granularity:** Fine (individual elements)
- **Load Balance:** Better for irregular sizes
- **Best for:** Non-square matrices, dynamic workloads

---

## 🔧 Compilation & Execution

### Part 1: 1D Threading
```bash
cd Part_1
gcc -fopenmp Q2.c -o Q2 -O0
./Q2
```

### Part 2: 2D Threading
```bash
cd Part_2
gcc -fopenmp Q2b.c -o Q2b -O0
./Q2b
```

---

## 📁 Directory Structure

```
Question_2/
├── README.md        # This file
├── Part_1/
│   └── Q2.c         # 1D threading implementation
└── Part_2/
    ├── Q2b.c        # 2D threading implementation
    └── Q2b          # Compiled executable
```

---

## 🎯 Key Takeaways

1. **Compute-bound operations scale excellently** with thread count
2. **1D and 2D threading** perform similarly for square matrices
3. **Cache effects** can produce super-linear speedup initially
4. **Arithmetic intensity** determines parallel scalability
5. **Static scheduling** works well for balanced workloads

---

## 📚 Concepts Demonstrated

- OpenMP parallel for with 1D and 2D strategies
- Loop collapse directive (`collapse(2)`)
- Compute-bound vs memory-bound operations
- Cache locality and spatial/temporal locality
- Work distribution and load balancing
- Static scheduling for regular workloads

---

**Completed by:** Ankit Kumar (102483012) - Group 3C75
