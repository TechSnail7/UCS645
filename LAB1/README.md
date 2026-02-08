# Lab 1: OpenMP Fundamentals

> Exploring thread-level parallelism with OpenMP

---

## 👤 Student Information

| Field | Details |
|-------|---------|
| **Name** | Ankit Kumar |
| **Roll No.** | 102483012 |
| **Group** | 3C75 |

---

## 💻 System Specifications

| Component | Specification |
|-----------|--------------|
| **Processor** | Intel Core i5-1240P (12th Gen) |
| **Physical Cores** | 12 |
| **Logical Processors** | 16 |
| **Architecture** | Hybrid (P-cores + E-cores) |
| **OS** | Windows 11 |
| **Compiler** | GCC 14.1.0 (MSYS2) |

---

## 🧪 Experiments Overview

| Question | Topic | Key Concept | Matrix/Vector Size |
|:--------:|-------|-------------|:------------------:|
| **Q1** | DAXPY Operation | Memory-bound parallelism | 65,536 elements |
| **Q2** | Matrix Multiplication | Compute-bound parallelism | 1000 × 1000 |
| **Q3** | Pi Calculation | Reduction operations | 500M steps |

---

## 📊 Performance Results

### Speedup Comparison (vs Single Thread)

| Threads | Q1 DAXPY | Q2 (1D) | Q2 (2D) | Q3 Pi |
|:-------:|:--------:|:-------:|:-------:|:-----:|
| 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| 2 | 1.40x | 2.36x | 2.26x | 2.19x |
| 4 | **1.79x** | 4.68x | 4.64x | 4.14x |
| 8 | 1.40x | 7.54x | 6.65x | 5.23x |
| 12 | 1.50x | 9.80x | 8.85x | 6.06x |
| 16 | 1.24x | **10.72x** | **10.72x** | **8.24x** |

---

## 🔍 Key Findings

### 1. Memory-Bound Operations (Q1: DAXPY)
- **Peak Speedup:** 1.79x at 4 threads
- **Bottleneck:** Memory bandwidth saturation
- **Observation:** Performance plateaus/degrades beyond 4 threads
- **Reason:** Low arithmetic intensity (3 memory ops per 2 FLOPs)

### 2. Compute-Bound Operations (Q2: Matrix Multiplication)
- **Peak Speedup:** 10.72x at 16 threads (both 1D and 2D)
- **Scalability:** Near-linear up to 8-10 threads
- **1D vs 2D:** Similar performance; 1D slightly better at low thread counts
- **Reason:** High arithmetic intensity (O(N³) computation)

### 3. Reduction Operations (Q3: Pi Calculation)
- **Peak Speedup:** 8.24x at 16 threads
- **Efficiency:** ~51.5% parallel efficiency
- **Overhead:** Thread synchronization and reduction combining
- **Accuracy:** < 10⁻¹² error with 500M integration steps

---

## 📈 Analysis Summary

### Performance Characteristics

| Operation Type | Example | Scalability | Key Factor |
|---------------|---------|:-----------:|------------|
| Memory-bound | DAXPY | Poor | Memory bandwidth |
| Compute-bound | Matrix Mult | Excellent | Arithmetic intensity |
| Reduction | Pi Calc | Good | Synchronization overhead |

### Thread Scaling Patterns

- **Up to 4 threads:** All operations show good speedup
- **4-8 threads:** Compute-bound operations continue scaling
- **8-16 threads:** Only compute-intensive tasks benefit significantly
- **Beyond optimal:** Overhead exceeds benefits for memory-bound tasks

---

## 🛠️ Compilation & Execution

### Quick Start

```bash
# Question 1: DAXPY
cd Question_1
gcc -fopenmp Q1.c -o Q1
./Q1

# Question 2 Part 1: Matrix Multiplication (1D)
cd Question_2/Part_1
gcc -fopenmp Q2.c -o Q2
./Q2

# Question 2 Part 2: Matrix Multiplication (2D)
cd Question_2/Part_2
gcc -fopenmp Q2b.c -o Q2b
./Q2b

# Question 3: Pi Calculation
cd Question_3
gcc -fopenmp Q3.c -o Q3
./Q3
```

### Compiler Flags

- `-fopenmp` - Enable OpenMP support
- `-O0` to `-O3` - Optimization level (varies by question)

---

## 📚 OpenMP Concepts Applied

### Directives Used

1. **`#pragma omp parallel for`**
   - Distributes loop iterations among threads
   - Used in all three questions

2. **`schedule(static)`**
   - Equal-sized chunks for each thread
   - Good for balanced workloads

3. **`collapse(2)`**
   - Parallelizes nested loops together
   - Used in Q2 Part 2 (2D threading)

4. **`reduction(+:sum)`**
   - Safe parallel accumulation
   - Used in Q3 (Pi calculation)

5. **`num_threads(n)`**
   - Explicitly control thread count
   - Used for performance testing

---

## 📝 Notes

- All timings measured using `omp_get_wtime()`
- Multiple runs averaged for consistency
- System load minimized during testing
- Results specific to Intel i5-1240P hybrid architecture

---

**Lab 1 Completed by:** Ankit Kumar (102483012) - Group 3C75
