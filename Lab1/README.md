# 🧪 Lab 1: OpenMP Fundamentals# 🚀 UCS645 - Parallel & Distributed Computing Lab 1# 🚀 UCS645 - Parallel & Distributed Computing Lab 1# 🚀 UCS645 - Parallel & Distributed Computing Lab 1# 🧪 Lab 1: OpenMP Fundamentals



> **Exploring thread-level parallelism with OpenMP**



---> **OpenMP Fundamentals & Performance Analysis**



## 👤 Student Information



| Field | Details |---> **OpenMP Fundamentals & Performance Analysis**

|-------|---------|

| **Name** | Ankit Kumar |

| **Roll No.** | 102483012 |

| **Group** | 3C75 |## 👤 Student Information



---



## 💻 System Specifications| Field | Details |---> **OpenMP Fundamentals & Performance Analysis**> **Exploring thread-level parallelism with OpenMP on AMD Ryzen 5 4600H**



| Component | Specification ||-------|---------|

|-----------|--------------|

| **Processor** | Intel(R) Core(TM) i5-1240P (12th Gen) || **Name** | Ankit Kumar |

| **Physical Cores** | 12 |

| **Logical Processors** | 16 || **Roll No.** | 102483012 |

| **Architecture** | x64 (Hybrid P-cores + E-cores) |

| **OS** | Windows 11 || **Group** | 3C75 |## 👤 Student Information

| **Compiler** | GCC 14.1.0 (MSYS2) |



---

---

## 🧪 Experiments



| Question | Topic | Description |

|:--------:|-------|-------------|## 💻 System Specifications| Field | Details |------

| Q1 | DAXPY | Vector operation X[i] = a*X[i] + Y[i] |

| Q2 | Matrix Multiplication | 1D and 2D parallel strategies |

| Q3 | Pi Calculation | Numerical integration with reduction |

| Component | Specification ||-------|---------|

---

|-----------|--------------|

## 📊 Results Summary

| **Processor** | Intel(R) Core(TM) i5-1240P (12th Gen) || **Name** | Ankit Kumar |

### Speedup Comparison (Relative to Single Thread)

| **Physical Cores** | 12 |

| Threads | Q1 DAXPY | Q2 (1D) | Q2 (2D) | Q3 Pi |

|:-------:|:--------:|:-------:|:-------:|:-----:|| **Logical Processors** | 16 || **Roll No.** | 102483012 |

| 1 | 1.00x | 1.00x | 1.00x | 1.00x |

| 2 | 1.40x | 2.36x | 2.26x | 2.19x || **Architecture** | x64 (Hybrid P-cores + E-cores) |

| 4 | 1.79x | 4.68x | 4.64x | 4.14x |

| 8 | 1.40x | 7.54x | 6.65x | 5.23x || **OS** | Windows 11 || **Group** | 3C75 |## 👤 Student Information## 💻 System Configuration

| 12 | 1.50x | 9.80x | 8.85x | 6.06x |

| 16 | 1.24x | 10.72x | 10.72x | 8.24x || **Compiler** | GCC 14.1.0 (MSYS2) |



---



## 🔍 Key Observations---



### Question 1: DAXPY (Memory-Bound)---

- **Peak Speedup:** 1.79x at 4 threads

- **Bottleneck:** Memory bandwidth limitation## 🧪 Experiments

- **Behavior:** Performance plateaus after 4 threads



### Question 2: Matrix Multiplication (Compute-Bound)

- **Peak Speedup:** 10.72x at 16 threads (both 1D and 2D)| Question | Topic | Description |

- **Best Strategy:** 1D threading slightly better for lower thread counts

- **Scalability:** Near-linear up to 8 threads|:--------:|-------|-------------|## 💻 System Specifications| Field | Details |### Processor Details



### Question 3: Pi Calculation (Reduction-Heavy)| Q1 | DAXPY | Vector operation X[i] = a*X[i] + Y[i] |

- **Peak Speedup:** 8.24x at 16 threads

- **Reduction Overhead:** Noticeable at higher thread counts| Q2 | Matrix Multiplication | 1D and 2D parallel strategies |

- **Efficiency:** ~51.5% parallel efficiency at 16 threads

| Q3 | Pi Calculation | Numerical integration with reduction |

---

| Component | Specification ||-------|---------|

## 📈 Analysis

---

### Thread Scaling Patterns

|-----------|--------------|

1. **Memory-Bound Operations (Q1)**

   - Limited by memory bandwidth, not computation## 📊 Results Summary

   - Adding more threads doesn't improve performance significantly

   - Hardware prefetching and cache effects dominate| **Processor** | Intel(R) Core(TM) i5-1240P (12th Gen) || **Name** | Ankit Kumar || Specification       | Value                                  |



2. **Compute-Bound Operations (Q2)**| Threads | Q1 DAXPY | Q2 (1D) | Q2 (2D) | Q3 Pi |

   - Excellent scalability with thread count

   - Work distribution is balanced|:-------:|:--------:|:-------:|:-------:|:-----:|| **Physical Cores** | 12 |

   - Cache locality benefits from static scheduling

| 1 | 1.00x | 1.00x | 1.00x | 1.00x |

3. **Reduction Operations (Q3)**

   - Good scalability but with overhead| 2 | 1.40x | 2.36x | 2.26x | 2.19x || **Logical Processors** | 16 || **Roll Number** | Ankit Kumar || ------------------- | -------------------------------------- |

   - Thread synchronization costs increase

   - Private variable management impacts performance| 4 | 1.79x | 4.68x | 4.64x | 4.14x |



### Hybrid Architecture Insights| 8 | 1.40x | 7.54x | 6.65x | 5.23x || **Architecture** | x64 (Hybrid P-cores + E-cores) |



The Intel Core i5-1240P's hybrid P-core + E-core design affects performance:| 12 | 1.50x | 9.80x | 8.85x | 6.06x |

- **P-cores:** High performance for parallel workloads

- **E-cores:** Energy efficient but slower| 16 | 1.24x | 10.72x | 10.72x | 8.24x || **OS** | Windows 11 || **Group** | 3C75 || **CPU**             | AMD Ryzen 5 4600H with Radeon Graphics |

- **Thread Assignment:** OS scheduler affects which cores execute threads



---

---| **Compiler** | GCC 14.1.0 (MSYS2) |

## 🛠️ Compilation & Execution



### Compilation

```bash## 🔧 Build Instructions| **Course** | UCS645 - Parallel and Distributed Computing || **Architecture**    | x86_64 (Zen 2)                         |

# Question 1

gcc -fopenmp Q1.c -o Q1



# Question 2 - Part 1```bash---

gcc -fopenmp Q2.c -o Q2

gcc -fopenmp <source>.c -o <output> -O0

# Question 2 - Part 2

gcc -fopenmp Q2b.c -o Q2b./<output> <num_threads>| **Physical Cores**  | 6                                      |



# Question 3```

gcc -fopenmp Q3.c -o Q3

```## 🧪 Experiments



### Execution---

```bash

# Run with different thread counts---| **Logical Threads** | 12                                     |

./Q1  # Tests 1, 2, 4, 6, 8, 10, 12 threads

./Q2  # Tests 1, 2, 4, 8, 12, 16 threads## 📂 Structure

./Q2b # Tests 1, 2, 4, 8, 12, 16 threads

./Q3  # Tests 1, 2, 4, 8, 12, 16 threads| Question | Topic | Description |

```

```

---

Lab1/|:--------:|-------|-------------|| **SMT**             | 2 threads per core                     |

## 📚 References

├── README.md

- OpenMP 5.0 Specification

- Intel Threading Building Blocks Documentation├── Question_1/   (DAXPY + graph)| Q1 | DAXPY | Vector operation X[i] = a*X[i] + Y[i] |

- "Parallel Programming in OpenMP" - Rohit Chandra et al.

├── Question_2/   (Matrix Multiplication + graph)

---

│   ├── Part_1/   (1D Threading)| Q2 | Matrix Multiplication | 1D and 2D parallel strategies |## 💻 System Specifications| **Base Clock**      | ~3.0 GHz                               |

## 📝 Notes

│   └── Part_2/   (2D Threading)

- All experiments run on Windows 11 with GCC 14.1.0

- Timing measured using `omp_get_wtime()`└── Question_3/   (Pi Calculation + graph)| Q3 | Pi Calculation | Numerical integration with reduction |

- Results averaged over multiple runs for consistency

- System load minimized during testing```



---| **Boost Clock**     | Up to 4.0 GHz                          |



**Author:** Ankit Kumar (102483012)  ---

**Course:** UCS645 - Parallel & Distributed Computing  

**Group:** 3C75---


**Ankit Kumar** | 102483012 | 3C75

| Component | Specification |

## 📊 Results Summary

|-----------|--------------|### Cache Hierarchy

![Overall Comparison](./graphs/overall_comparison.png)

| **Processor** | Intel(R) Core(TM) i5-1240P (12th Gen) |

| Threads | Q1 DAXPY | Q2 (1D) | Q2 (2D) | Q3 Pi |

|:-------:|:--------:|:-------:|:-------:|:-----:|| **Physical Cores** | 12 || Level              | Size    | Instances |

| 1 | 1.00x | 1.00x | 1.00x | 1.00x |

| 2 | 1.40x | 2.36x | 2.26x | 2.19x || **Logical Processors** | 16 || ------------------ | ------- | --------- |

| 4 | 1.79x | 4.68x | 4.64x | 4.14x |

| 8 | 1.40x | 7.54x | 6.65x | 5.23x || **Architecture** | x64 (Hybrid - P-cores + E-cores) || **L1 Data**        | 192 KiB | 6         |

| 12 | 1.50x | 9.80x | 8.85x | 6.06x |

| 16 | 1.24x | 10.72x | 10.72x | 8.24x || **Operating System** | Windows 11 || **L1 Instruction** | 192 KiB | 6         |



---| **Compiler** | GCC 14.1.0 (MSYS2) || **L2**             | 3 MiB   | 6         |



## 🔧 Build Instructions| **L3**             | 8 MiB   | 2         |



```bash---

gcc -fopenmp <source>.c -o <output> -O0

./<output> <num_threads>### Development Environment

```

## 📋 Lab Objectives

---

| Component    | Version       |

## 📂 Structure

This lab explores parallel programming fundamentals using OpenMP with focus on:| ------------ | ------------- |

```

Lab1/| **OS**       | Arch Linux    |

├── README.md

├── graphs/- ✅ Understanding the Fork-Join execution model| **Kernel**   | Native Linux  |

├── Question_1/   (DAXPY)

├── Question_2/   (Matrix Multiplication)- ✅ Thread management and synchronization| **Compiler** | GCC 15.2.1    |

│   ├── Part_1/   (1D Threading)

│   └── Part_2/   (2D Threading)- ✅ Performance analysis and speedup measurement| **OpenMP**   | libgomp (GCC) |

└── Question_3/   (Pi Calculation)

```- ✅ Identifying scalability limits



---```bash



**Ankit Kumar** | 102483012 | 3C75---$ gcc --version


gcc (GCC) 15.2.1 20260103

## 🧪 Experiments OverviewCopyright (C) 2025 Free Software Foundation, Inc.

```

### Question 1: DAXPY Operation

Vector operation `X[i] = a*X[i] + Y[i]` with 2^16 elements---



📁 **Location:** [`Question_1/`](./Question_1/)## 📁 Lab Contents



### Question 2: Matrix Multiplication| Question | Topic                 | Description                          |

Parallel matrix multiplication (1000×1000) using two approaches| -------- | --------------------- | ------------------------------------ |

| Q1       | DAXPY                 | Vector operation parallelization     |

📁 **Location:** [`Question_2/`](./Question_2/)| Q2       | Matrix Multiplication | 1D and 2D parallel strategies        |

- Part 1: 1D Threading (Row-wise parallelization)| Q3       | Pi Approximation      | Numerical integration with reduction |

- Part 2: 2D Threading (Collapsed loops with `collapse(2)`)

### Question 3: Pi (π) Calculation
Numerical integration to approximate π using the midpoint rule

📁 **Location:** [`Question_3/`](./Question_3/)

---

## 📊 Results Summary

### Speedup Comparison

![Overall Comparison](./graphs/overall_comparison.png)

| Threads | Q1 DAXPY | Q2 (1D) | Q2 (2D) | Q3 Pi |
|:-------:|:--------:|:-------:|:-------:|:-----:|
| 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| 2 | 1.40x | 2.36x | 2.26x | 2.19x |
| 4 | 1.79x | 4.68x | 4.64x | 4.14x |
| 8 | 1.40x | 7.54x | 6.65x | 5.23x |
| 12 | 1.50x | 9.80x | 8.85x | 6.06x |
| 16 | 1.24x | 10.72x | 10.72x | 8.24x |

### Key Observations

1. **DAXPY (Memory-Bound):** Limited scalability due to memory bandwidth constraints
2. **Matrix Multiplication (Compute-Bound):** Excellent scalability up to 16 threads
3. **Pi Calculation:** Good speedup with diminishing returns beyond 12 threads

---

## 🔧 Build & Run Instructions

### Prerequisites
```bash
# Windows with MSYS2
pacman -S mingw-w64-ucrt-x86_64-gcc

# Linux/WSL
sudo apt install build-essential
```

### Compilation
```bash
gcc -fopenmp <source>.c -o <output> -O0
```

### Execution
```bash
./<output> <num_threads>
```

---

## 📂 Directory Structure

```
Lab1/
├── README.md              # This file
├── graphs/                # Performance visualization
│   ├── q1_daxpy_performance.png
│   ├── q2_matrix_multiplication.png
│   ├── q3_pi_calculation.png
│   └── overall_comparison.png
├── Question_1/            # DAXPY experiment
├── Question_2/            # Matrix multiplication
│   ├── Part_1/            # 1D threading
│   └── Part_2/            # 2D threading
└── Question_3/            # Pi calculation
```

---

<div align="center">

**UCS645 Lab 1** | Ankit Kumar | Group 3C75

</div>
