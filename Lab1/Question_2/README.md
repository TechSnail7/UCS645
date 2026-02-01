# 🧮 Question 2: Matrix Multiplication

> **Parallel Matrix Multiplication with 1D and 2D Threading Strategies**

---

## � Student Information

| Field | Details |
|-------|---------|
| **Name** | Ankit Kumar |
| **Roll No.** | 102483012 |
| **Group** | 3C75 |

---

## �📝 Problem Statement

Implement parallel matrix multiplication `C = A × B` using two approaches:
- **Part 1:** 1D Threading (row-wise parallelization)
- **Part 2:** 2D Threading (collapsed loop parallelization)

Matrix Dimensions: **1000 × 1000**

---

## 🔬 Implementation Approaches

### Part 1: 1D Threading (Row-wise)

```c
#pragma omp parallel for num_threads(n) schedule(static)
for (int i = 0; i < N; i++) {        // Parallelized
    for (int j = 0; j < N; j++) {    // Sequential
        for (int k = 0; k < N; k++) {// Sequential
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

**Work Distribution:** Each thread computes complete rows of C

### Part 2: 2D Threading (Collapsed Loops)

```c
#pragma omp parallel for collapse(2) num_threads(n) schedule(static)
for (int i = 0; i < N; i++) {        // Parallelized
    for (int j = 0; j < N; j++) {    // Parallelized
        for (int k = 0; k < N; k++) {// Sequential
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

**Work Distribution:** Each thread computes individual elements of C

---

## 📊 Experimental Results

**Test Environment:** Intel Core i5-1240P (12 cores, 16 threads)

### Part 1: 1D Threading Results

| Threads | Time (sec) | Speedup |
|:-------:|:----------:|:-------:|
| 1 | 3.655 | 1.00x |
| 2 | 1.546 | 2.36x |
| 4 | 0.781 | 4.68x |
| 6 | 0.599 | 6.10x |
| 8 | 0.485 | 7.54x |
| 10 | 0.418 | 8.74x |
| 12 | 0.373 | 9.80x |
| 14 | 0.359 | 10.18x |
| 16 | 0.341 | **10.72x** |

![1D Threading Speedup](./Part_1/speedup_graph.png)

### Part 2: 2D Threading Results

| Threads | Time (sec) | Speedup |
|:-------:|:----------:|:-------:|
| 1 | 3.559 | 1.00x |
| 2 | 1.577 | 2.26x |
| 4 | 0.767 | 4.64x |
| 6 | 0.581 | 6.13x |
| 8 | 0.535 | 6.65x |
| 10 | 0.406 | 8.77x |
| 12 | 0.402 | 8.85x |
| 14 | 0.349 | 10.20x |
| 16 | 0.332 | **10.72x** |

![2D Threading Speedup](./Part_2/speedup_graph.png)

---

## 💡 Analysis

### Performance Comparison

| Metric | 1D Threading | 2D Threading |
|--------|:------------:|:------------:|
| Best Time | 0.341s | 0.332s |
| Max Speedup | 10.72x | 10.72x |
| Scalability | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ |

### Key Observations

1. **Excellent Scalability**
   - Matrix multiplication is compute-bound (high arithmetic intensity)
   - O(N³) computations vs O(N²) memory accesses
   - Near-linear speedup up to 10-12 threads

2. **1D vs 2D Comparison**
   - Similar performance for this matrix size
   - 2D threading provides finer granularity
   - 2D may be better for unbalanced workloads

3. **Cache Efficiency**
   - Row-major access pattern benefits cache
   - Static scheduling ensures predictable access

### Work Partitioning

| Approach | Granularity | Load Balance |
|----------|:-----------:|:------------:|
| 1D | Coarse (rows) | Good for square matrices |
| 2D | Fine (elements) | Better for irregular sizes |

---

## 🔧 Build & Execute

```bash
# Part 1: 1D Threading
cd Part_1
gcc -fopenmp Q2.c -o Q2.exe -O0
./Q2.exe <num_threads>

# Part 2: 2D Threading
cd Part_2
gcc -fopenmp Q2b.c -o Q2b.exe -O0
./Q2b.exe <num_threads>
```

---

## 📁 Directory Structure

```
Question_2/
├── README.md        # This file
├── Part_1/
│   ├── Q2.c         # 1D threading implementation
│   └── Q2.exe       # Compiled executable
└── Part_2/
    ├── Q2b.c        # 2D threading implementation
    └── Q2b.exe      # Compiled executable
```

---

**Ankit Kumar** | 102483012 | 3C75
