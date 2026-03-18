# 3070. Count Submatrices with Top-Left Element and Sum Less Than k

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Matrix, Prefix Sum
Date | March 18, 2026
LeetCode Link | [3070. Count Submatrices with Top-Left Element and Sum Less Than k](https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/)

### Intuition
The problem asks us to count submatrices that include the top-left element $(0, 0)$ and have a sum less than or equal to $k$. A submatrix starting at $(0, 0)$ is uniquely defined by its bottom-right corner $(i, j)$.

To efficiently calculate the sum of every possible submatrix starting at the origin, we can use the **2D Prefix Sum** technique. The prefix sum $P[i][j]$ represents the sum of all elements in the rectangle from $(0, 0)$ to $(i, j)$.

The recurrence relation for 2D prefix sums is:
$P[i][j] = \text{grid}[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]$

Since all elements in the grid are non-negative ($\text{grid}[i][j] \ge 0$), the prefix sums are monotonically non-decreasing as $i$ or $j$ increases. This means if a submatrix sum $P[i][j]$ exceeds $k$, any larger submatrix extending further to the right ($P[i][j+1]$) will also exceed $k$. We can use this property to slightly optimize the traversal, although a simple $O(M \times N)$ pass is sufficient given the constraints.

### Complexity Analysis
- **Time Complexity:** $O(M \times N)$, where $M$ is the number of rows and $N$ is the number of columns. we visit each cell in the grid exactly once to compute its prefix sum and compare it with $k$.
- **Space Complexity:** $O(1)$ if we modify the input matrix in-place, or $O(M \times N)$ if we use an auxiliary matrix for prefix sums. In the provided solution, we use a separate matrix for clarity and to avoid side effects on the input.