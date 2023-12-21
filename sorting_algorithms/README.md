# 0x1B. C - Sorting Algorithms & Big O

This project is a part of the Alx - SE curriculum of software engineering. The primary objective is to understand and implement the concepts of sorting algorithms and Big O notation.

## Team Members

- Abdallah Abdelrahman
- Mohannad Babeker

## Learning Objectives

- Understand the concept of Big O notation and how to evaluate the time complexity of an algorithm.
- Learn the workings of the following sorting algorithms:
    - Bubble sort
    - Insertion sort
    - Selection sort
    - Quick sort
    - Shell sort - Knuth Sequence
    - Cocktail shaker sort
    - Counting sort
    - Merge sort
    - Heap sort
    - Radix sort
    - Bitonic sort
    - Quick Sort - Hoare Partition scheme
- Understand how to select the most efficient sorting algorithm for a given input.
- Learn the concept of a stable sorting algorithm.

## More Information

For this project, we are provided with the following functions:

- print_array.c
- print_list.c

Our header file, sort.h, will contain all the function prototypes and data structures.

## Implemented Algorithms

The following table provides an overview of the algorithms implemented during this project:

| Algorithm | Real World Applications | Time Complexity | Space Complexity | Comparison-Based | Stability |
|:---------:|:-----------------------:|:---------------:|:----------------:|:----------------:|:---------:|
| **Quick Sort** | Used in various programming languages’ sort functions | Average and Best: $$\theta(N \log N)$$, Worst: $$O(N^2)$$ | $$O(\log N)$$ | Yes | No |
| **Merge Sort** | Used in external sorting, where large amounts of data need to be sorted | $$\theta(N \log N)$$, $$\Omega(N \log N)$$, $$O(N \log N)$$ | $$O(N)$$ | Yes | Yes |
| **Shell Sort** | Used in systems with limited resources | Best: $$\Omega(N \log N)$$, Worst: $$O(N^2)$$ or $$O\left(\frac{(N \log N)^2}{\log \log N}\right)$$ | $$O(1)$$ | Yes | No |
| **Cocktail Shaker/Bubble Sort** | Used in education for its simplicity | $$O(N^2)$$ | $$O(1)$$ | Yes | Yes |
| **Insertion Sort** | Used in online transaction processing and small dataset sorting | Best: $$\Omega(N)$$, Average and Worst: $$\theta(N^2)$$, $$O(N^2)$$ | $$O(1)$$ | Yes | Yes |
| **Selection Sort** | Used in education for its simplicity | $$O(N^2)$$ | $$O(1)$$ | Yes | No |
| **Count Sort** | Used when the range of potential items is known | $$O(N+K)$$ where K is the range of input | $$O(N+K)$$ where K is the range of input | No | Yes |
| **Radix Sort** | Used in data processing such as sorting large integers or strings | $$O(NK)$$ where K is the number of digits | $$O(N+K)$$ where K is the number of digits | No | Yes |
| **Bitonic Sort** | Used as consturction method for building a sorting network | Best, Average and worst case: $$O(log^2(n))$$ for parallel. non-parallel: $$O(n log^2 (n))$$ , where n is a power of 2 | $$O(nlogn)$$ due to stack frames from recursive call | Yes | No
| **Heap Sort** | Used in priority queues and scheduling algorithms | $$O(N \log N)$$ | $$O(1)$$ | Yes | No |
| **Bucket Sort** | Used in computer graphics to sort pixels based on colors | Average and Best: $$\theta(N+K)$$, $$\Omega(N+K)$$, Worst: $$O(N^2)$$ | $$O(NK)$$ where K is the number of buckets | No | Yes |
