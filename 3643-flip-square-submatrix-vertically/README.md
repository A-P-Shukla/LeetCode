# 3643. Flip Square Submatrix Vertically

Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Two Pointers, Matrix
Date | March 21, 2026
LeetCode Link | [https://leetcode.com/problems/flip-square-submatrix-vertically/](https://leetcode.com/problems/flip-square-submatrix-vertically/)

### Intuition
The problem asks us to perform a vertical flip on a specific square submatrix defined by a top-left corner $(x, y)$ and a side length $k$. A vertical flip involves reversing the order of the rows within that specific subregion while keeping the columns consistent.

To achieve this, we can use a two-pointer approach targeting the rows of the submatrix. We initialize one pointer at the first row of the submatrix ($x$) and another at the last row ($x + k - 1$). For each pair of rows, we swap the elements specifically within the column range $[y, y + k - 1]$. We then move the pointers toward each other until they meet or cross. Since the operation is performed in-place, the memory footprint remains minimal.

### Complexity Analysis
- **Time Complexity:** $O(k^2)$, where $k$ is the side length of the square submatrix. In the worst case, $k$ could be $\min(m, n)$, but we only visit each element within the submatrix once to perform the swap.
- **Space Complexity:** $O(1)$, as the transformation is performed directly on the input matrix without requiring additional data structures proportional to the input size.