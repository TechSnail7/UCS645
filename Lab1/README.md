# 🚀 UCS645 - Parallel & Distributed Computing Lab 1# 🚀 UCS645 - Parallel & Distributed Computing Lab 1# 🚀 UCS645 - Parallel & Distributed Computing Lab 1# 🧪 Lab 1: OpenMP Fundamentals



> **OpenMP Fundamentals & Performance Analysis**



---> **OpenMP Fundamentals & Performance Analysis**



## 👤 Student Information



| Field | Details |---> **OpenMP Fundamentals & Performance Analysis**> **Exploring thread-level parallelism with OpenMP on AMD Ryzen 5 4600H**

|-------|---------|

| **Name** | Ankit Kumar |

| **Roll No.** | 102483012 |

| **Group** | 3C75 |## 👤 Student Information



---



## 💻 System Specifications| Field | Details |------



| Component | Specification ||-------|---------|

|-----------|--------------|

| **Processor** | Intel(R) Core(TM) i5-1240P (12th Gen) || **Name** | Ankit Kumar |

| **Physical Cores** | 12 |

| **Logical Processors** | 16 || **Roll No.** | 102483012 |

| **Architecture** | x64 (Hybrid P-cores + E-cores) |

| **OS** | Windows 11 || **Group** | 3C75 |## 👤 Student Information## 💻 System Configuration

| **Compiler** | GCC 14.1.0 (MSYS2) |



---

---

## 🧪 Experiments



| Question | Topic | Description |

|:--------:|-------|-------------|## 💻 System Specifications| Field | Details |### Processor Details

| Q1 | DAXPY | Vector operation X[i] = a*X[i] + Y[i] |

| Q2 | Matrix Multiplication | 1D and 2D parallel strategies |

| Q3 | Pi Calculation | Numerical integration with reduction |

| Component | Specification ||-------|---------|

---

|-----------|--------------|

## 📊 Results Summary

| **Processor** | Intel(R) Core(TM) i5-1240P (12th Gen) || **Name** | Ankit Kumar || Specification       | Value                                  |

| Threads | Q1 DAXPY | Q2 (1D) | Q2 (2D) | Q3 Pi |

|:-------:|:--------:|:-------:|:-------:|:-----:|| **Physical Cores** | 12 |

| 1 | 1.00x | 1.00x | 1.00x | 1.00x |

| 2 | 1.40x | 2.36x | 2.26x | 2.19x || **Logical Processors** | 16 || **Roll Number** | Ankit Kumar || ------------------- | -------------------------------------- |

| 4 | 1.79x | 4.68x | 4.64x | 4.14x |

| 8 | 1.40x | 7.54x | 6.65x | 5.23x || **Architecture** | x64 (Hybrid P-cores + E-cores) |

| 12 | 1.50x | 9.80x | 8.85x | 6.06x |

| 16 | 1.24x | 10.72x | 10.72x | 8.24x || **OS** | Windows 11 || **Group** | 3C75 || **CPU**             | AMD Ryzen 5 4600H with Radeon Graphics |



---| **Compiler** | GCC 14.1.0 (MSYS2) |



## 🔧 Build Instructions| **Course** | UCS645 - Parallel and Distributed Computing || **Architecture**    | x86_64 (Zen 2)                         |



```bash---

gcc -fopenmp <source>.c -o <output> -O0

./<output> <num_threads>| **Physical Cores**  | 6                                      |

```

## 🧪 Experiments

---

---| **Logical Threads** | 12                                     |

## 📂 Structure

| Question | Topic | Description |

```

Lab1/|:--------:|-------|-------------|| **SMT**             | 2 threads per core                     |

├── README.md

├── Question_1/   (DAXPY + graph)| Q1 | DAXPY | Vector operation X[i] = a*X[i] + Y[i] |

├── Question_2/   (Matrix Multiplication + graph)

│   ├── Part_1/   (1D Threading)| Q2 | Matrix Multiplication | 1D and 2D parallel strategies |## 💻 System Specifications| **Base Clock**      | ~3.0 GHz                               |

│   └── Part_2/   (2D Threading)

└── Question_3/   (Pi Calculation + graph)| Q3 | Pi Calculation | Numerical integration with reduction |

```

| **Boost Clock**     | Up to 4.0 GHz                          |

---

---

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
