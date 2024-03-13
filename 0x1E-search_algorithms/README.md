# 0x1E. C - Search Algorithms

This project is part of the Alx - SE curriculum of software engineering. The main objective is to understand and implement the concepts of search algorithms in C.

## Learning Objectives

- Understand the concept and purpose of search algorithms.
- Implement linear search and understand its use cases.
- Implement and utilize binary search.
- Understand how to choose the most efficient search algorithm based on the task at hand.
- Understand the differences between linear search and binary search.
- Learn about the time and space complexity of different search algorithms.
- Understand when and why to use a specific search algorithm.

## Project Structure

The project directory contains the following files:

- `0-linear.c`: Implementation of linear search.
- `1-binary.c`: Implementation of binary search.
- `100-jump.c`: Implementation of jump search.
- `102-interpolation.c`: Implementation of interpolation search.
- `103-exponential.c`: Implementation of exponential search.
- `104-advanced_binary.c`: Implementation of advanced binary search.
- `105-jump_list.c`: Implementation of jump search in a singly linked list.
- `106-linear_skip.c`: Implementation of linear search in a skip list.
- `search_algos.h`: Header file containing the function prototypes for all the search algorithms implemented.
- `2-O`: Contains the worst-case time complexity of a linear search in an array of size `n`.
- `3-O`: Contains the worst-case space complexity of an iterative linear search algorithm in an array of size `n`.
- `4-O`: Contains the worst-case time complexity of a binary search in an array of size `n`.
- `5-O`: Contains the worst-case space complexity of a binary search in an array of size `n`.
- `6-O`: Contains the space complexity of the following function:

```c
int **allocate_map(int n, int m)
{
     int **map;

     map = malloc(sizeof(int *) * n);
     for (size_t i = 0; i < n; i++)
     {
          map[i] = malloc(sizeof(int) * m);
     }
     return (map);
}
```

- `101-O`: Contains the average-case time complexity of a jump search in an array of size `n`, using step = $$\sqrt{n}$$.
- `107-O`: Contains the average-case time complexity of a jump search in a singly linked list of size `n`, using step = $$\sqrt{n}$$.
- `108-O`: Contains the average-case time complexity of a jump search in a skip list of size `n`, with an express lane using step = $$\sqrt{n}$$.
