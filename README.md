# UCS645 - Parallel & Distributed Computing

> Exploration of parallel programming concepts using OpenMP

---

## 👤 Student Information

| Field | Details |
|-------|---------|
| **Name** | Ankit Kumar |
| **Roll No.** | 102483012 |
| **Group** | 3C75 |

---

## 📋 Repository Overview

This repository contains lab assignments for the **UCS645: Parallel and Distributed Computing** course, focusing on OpenMP-based parallel programming with performance analysis.

---

## 🧪 Lab Contents

### Lab 1: OpenMP Fundamentals

| Question | Topic | Description |
|:--------:|-------|-------------|
| Q1 | DAXPY Operation | Vector operation: X[i] = a*X[i] + Y[i] |
| Q2 | Matrix Multiplication | 1D and 2D parallel strategies (1000×1000) |
| Q3 | Pi Calculation | Numerical integration with reduction (500M steps) |

---

## 🛠️ Setup & Requirements

### Prerequisites
- **Compiler:** GCC with OpenMP support (`-fopenmp`)
- **OS:** Windows 11 / Linux / macOS
- **Architecture:** Multi-core processor (tested on Intel i5-1240P)

### Compilation
```bash
# Navigate to specific question directory
cd Lab1/Question_X/

# Compile with OpenMP
gcc -fopenmp source.c -o output

# Run
./output
```

---

## 📊 Performance Summary

All experiments conducted on Intel Core i5-1240P (12 cores, 16 threads).

| Question | Peak Speedup | Optimal Threads | Characteristics |
|:--------:|:------------:|:---------------:|-----------------|
| Q1 DAXPY | 1.79x | 4 | Memory-bound, limited scalability |
| Q2 MatMul (1D) | 10.72x | 16 | Compute-bound, excellent scaling |
| Q2 MatMul (2D) | 10.72x | 16 | Similar to 1D, finer granularity |
| Q3 Pi | 8.24x | 16 | Reduction overhead, good scaling |

---

## 📚 Key Learnings

1. **Memory-bound vs Compute-bound**
   - Memory-bound operations (DAXPY) see limited speedup due to bandwidth saturation
   - Compute-bound operations (Matrix Multiplication) scale well with thread count

2. **Threading Strategies**
   - 1D threading: Simpler, good for row-wise operations
   - 2D threading: Finer granularity, better load balancing for irregular workloads

3. **Reduction Operations**
   - Efficient parallel accumulation with OpenMP reduction clause
   - Some overhead from thread synchronization

4. **Hybrid Architecture**
   - Intel's P-core + E-core design affects performance
   - Thread assignment by OS scheduler impacts results

---

## 📁 Repository Structure

```
UCS645-Assignment-1/
├── README.md                 # This file
└── Lab1/
    ├── README.md             # Lab 1 overview
    ├── Question_1/
    │   ├── Q1.c
    │   └── README.md
    ├── Question_2/
    │   ├── README.md
    │   ├── Part_1/
    │   │   └── Q2.c
    │   └── Part_2/
    │       ├── Q2b.c
    │       └── Q2b
    └── Question_3/
        ├── Q3.c
        └── README.md
```

---

## 📞 Contact

**Ankit Kumar**  
Roll No: 102483012  
Group: 3C75  
Course: UCS645 - Parallel & Distributed Computing
