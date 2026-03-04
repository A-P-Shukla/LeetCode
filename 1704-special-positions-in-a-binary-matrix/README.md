# 1582. Special Positions in a Binary Matrix

Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Matrix
Date | March 04, 2026
LeetCode Link | [https://leetcode.com/problems/special-positions-in-a-binary-matrix/](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)

## Intuition

A position $(i, j)$ is defined as "special" if `mat[i][j]` is the only `1` in its entire row and the only `1` in its entire column. 

The most efficient way to verify this property for all cells is to pre-calculate the distribution of `1`s across the matrix. By iterating through the matrix once, we can store the total count of `1`s for every row and every column.

1.  **Row Sums:** If a row $i$ has a sum of exactly $1$, it means there is exactly one `1` in that row.
2.  **Column Sums:** If a column $j$ has a sum of exactly $1$, it means there is exactly one `1` in that column.

Once we have these counts stored in two auxiliary arrays, we simply iterate through the matrix a second time. A cell $(i, j)$ is special if and only if `mat[i][j] == 1`, `rowSum[i] == 1`, and `colSum[j] == 1`.

## Complexity Analysis

- **Time Complexity:** $O(m \times n)$, where $m$ is the number of rows and $n$ is the number of columns. We perform two passes over the matrix: one to calculate the sums and one to identify special positions.
- **Space Complexity:** $O(m + n)$ to store the `rowSum` and `colSum` arrays. Given the constraints ($100 \times 100$), this is negligible.