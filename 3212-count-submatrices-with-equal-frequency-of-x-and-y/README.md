# 3212. Count Submatrices With Equal Frequency of X and Y

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Matrix, Prefix Sum
Date | March 19, 2026
LeetCode Link | [https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/](https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/)

## Intuition

The problem asks us to count submatrices starting at the origin `(0, 0)` and ending at any coordinate `(i, j)` that satisfy two conditions: an equal count of 'X' and 'Y', and at least one 'X'. 

Since every submatrix must include the top-left corner `(0, 0)`, a submatrix is uniquely defined by its bottom-right corner `(i, j)`. To efficiently calculate the frequency of characters within these submatrices, we use the concept of **2D Prefix Sums**.

Instead of recalculating the count for each possible bottom-right corner (which would result in a naive $O(R^2 \cdot C^2)$ or $O(R \cdot C \cdot \min(R, C))$ approach), we can compute the cumulative counts of 'X' and 'Y' in $O(1)$ time per cell by building upon previous results. 

Specifically, the number of 'X's in a submatrix ending at `(i, j)` is:
`Count(i, j) = current_cell_is_X + Count(i-1, j) + Count(i, j-1) - Count(i-1, j-1)`

To optimize space, we can reduce the 2D prefix sum to a 1D array by processing the grid row by row. We maintain a running sum of character counts for each column up to the current row, and then aggregate these column sums horizontally to get the submatrix total.

## Complexity Analysis

- **Time Complexity:** $O(R \times C)$, where $R$ is the number of rows and $C$ is the number of columns. we visit each cell exactly once to update the prefix counts.
- **Space Complexity:** $O(C)$. By using a 1D array to store the cumulative column sums, we reduce the space requirement from $O(R \times C)$ to $O(C)$.