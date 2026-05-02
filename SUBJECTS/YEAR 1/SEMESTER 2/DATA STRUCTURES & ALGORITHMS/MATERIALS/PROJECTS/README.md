# Fibonacci Heap: Implementation and Performance Analysis

## Project Overview

This project focuses on the **Fibonacci Heap**, an advanced priority
queue data structure known for its superior amortized time complexity.
While standard heaps like the Binary Heap are efficient for basic
operations, the Fibonacci Heap is specifically designed to excel in
*mergeable* scenarios and graph algorithms (like Dijkstra's) where
**Merge** and **Decrease Key** operations are frequent.

The goal of this study is to implement the Fibonacci Heap from scratch
and compare its empirical performance against **Binary** and
**Binomial** Heaps.

------------------------------------------------------------------------

## File Structure

  -----------------------------------------------------------------------
  File                                Description
  ----------------------------------- -----------------------------------
  `Fibonacci_Heap.pdf`                           **The Final Project Report**
                                      (Theory, Design, and Analysis).

  `FibHeap.h / .cpp`                  **Primary Implementation:**
                                      Fibonacci Heap logic.

  `BinomialHeap.h / .cpp`             Secondary comparison heap
                                      (Binomial).

  `BinaryHeap.h / .cpp`               Baseline comparison heap (Binary).

  `main.cpp`                          Benchmark suite for performance
                                      measurement.

  `README.md`                         Documentation and setup guide.
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## Compilation and Execution (via CMD)

This project requires the **g++ compiler (MinGW)**. Follow these steps
to compile and run the benchmarks manually via the Command Prompt.

### 1. Open CMD and navigate to the project directory

### 2. Compile using g++

``` 
g++ -O3 main.cpp FibHeap.cpp BinomialHeap.cpp BinaryHeap.cpp -o heap_benchmark
```

### 3. Run the executable

``` 
heap_benchmark.exe
```
