# 1594. Maximum Non Negative Product in a Matrix

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Dynamic Programming, Matrix
Date | March 23, 2026
LeetCode Link | [https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)

### Intuition
The problem asks for the maximum product along a path from the top-left to the bottom-right of a matrix, restricted to moving only right or down. Because the grid contains both positive and negative integers, a simple "maximum product" dynamic programming approach is insufficient. This is because multiplying a very small negative number by another negative number can result in a very large positive number.

To handle this, we maintain two values for each cell $(i, j)$:
1.  **Max Product**: The largest possible product to reach this cell.
2.  **Min Product**: The smallest possible product to reach this cell.

When moving into a cell $(i, j)$, we compute the potential products by multiplying the current cell's value with the max and min products of its neighbors (top and left). 
- If `grid[i][j]` is positive, the new maximum comes from the previous maximum.
- If `grid[i][j]` is negative, the new maximum comes from the previous minimum.
- If `grid[i][j]` is zero, both max and min products become zero.

By keeping track of both extremes, we capture the potential "flip" caused by negative signs. Since the constraints are small ($m, n \le 15$) and the maximum value is 4, the maximum possible product ($4^{29}$) fits within a 64-bit integer (`long long`), allowing us to perform calculations without intermediate modulo operations.

### Complexity Analysis
- **Time Complexity**: $O(m \times n)$, where $m$ is the number of rows and $n$ is the number of columns. we visit each cell exactly once and perform a constant number of operations.
- **Space Complexity**: $O(m \times n)$ to store the DP tables. This can be optimized to $O(n)$ by only storing the current and previous rows, but given the small constraints, $O(m \times n)$ is acceptable.