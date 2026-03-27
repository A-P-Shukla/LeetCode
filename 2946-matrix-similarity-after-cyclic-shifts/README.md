# 2946. Matrix Similarity After Cyclic Shifts

Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Math, Matrix, Simulation
Date | March 27, 2026
LeetCode Link | [https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/)

## Intuition

The problem asks whether a matrix remains identical to its original state after performing $k$ cyclic shifts on its rows (left for even indices, right for odd indices). 

A key observation is that a cyclic shift of a row by $k$ positions results in the same row if and only if the element at any index $j$ is equal to the element at the position it is being shifted from.
1. For a **left shift** of $k$ positions, the element that ends up at index $j$ was originally at index $(j + k) \pmod n$.
2. For a **right shift** of $k$ positions, the element that ends up at index $j$ was originally at index $(j - k \pmod n + n) \pmod n$.

Crucially, if a row is identical after a cyclic shift of $k$ in one direction, it is also identical after a cyclic shift of $k$ in the opposite direction. This is because both conditions imply that the row has a periodicity that divides $k \pmod n$. Specifically, if $mat[i][j] = mat[i][(j + k) \pmod n]$ for all $j$, then the row is invariant under a shift of $k$.

Therefore, we do not need to perform any actual shifting or separate logic for even/odd rows. We simply check if $mat[i][j] == mat[i][(j + k) \pmod n]$ for every element in the matrix.

## Complexity Analysis

- **Time Complexity**: $O(m \times n)$, where $m$ is the number of rows and $n$ is the number of columns. we iterate through every element of the matrix exactly once.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for loop variables and the remainder calculation.