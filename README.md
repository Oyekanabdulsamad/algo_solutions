# Algorithms Checkpoint - Solutions

This folder contains the solutions to the two problems.

## Files

| File | Description |
|------|-------------|
| `pseudocode.txt` | Language-independent pseudocode for both problems (the "algorithm" answers). |
| `problem1_sum_distinct.c` | Problem 1 - sum of distinct elements of two sets, implemented with arrays. |
| `problem2_dot_product.c` | Problem 2 - dot product (procedure + function) and orthogonality test. |

## Problem 1 - Sum of distinct elements

Given two sets, add up the elements that appear in **only one** of them
(symmetric difference).

- Initialize `sum = 0`.
- For each element of set 1, if it is **not** present in set 2, add it to `sum`.
- Do the same the other way around for set 2.

Example: `[3,1,7,9]` and `[2,4,1,9,3]` -> distinct elements `7, 2, 4` -> **13**.

## Problem 2 - Dot product & orthogonality

Vectors are represented as arrays.

1. `dot_product` as a **procedure**: the result `ps` is returned through an
   output parameter (pass by reference / pointer).
2. For `n` pairs of vectors, two vectors are **orthogonal** when their dot
   product equals zero. A nested loop reads/processes each pair.
3. Same algorithm rewritten with a `dot_product` **function** that returns the
   value directly.

The C version shows different parameter-passing styles:
arrays by reference, dimension by value, and the result either by reference
(procedure) or as a return value (function).

## How to compile & run

```bash
gcc problem1_sum_distinct.c -o problem1 && ./problem1
gcc problem2_dot_product.c -o problem2 && ./problem2
```
