# 3546. Equal Sum Grid Partition I

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Matrix, Enumeration, Prefix Sum
Date | March 25, 2024
LeetCode Link | [Equal Sum Grid Partition I](https://leetcode.com/problems/equal-sum-grid-partition-i/)

### Intuition

The problem asks whether we can split a grid into two equal halves using a single straight cut, either horizontally or vertically. Since the grid contains positive integers, the sum of any non-empty partition will be greater than zero.

The core observation is that for a partition to exist, the total sum of all elements in the grid ($S$) must be even. If $S$ is odd, no two integer-sum partitions can be equal. If $S$ is even, we are looking for a prefix of rows or a prefix of columns that sums exactly to $S/2$.

1.  **Horizontal Cuts:** We calculate the total sum of the grid. Then, we iterate through the rows one by one, accumulating the sum of elements in each row. If at any row $i$ (where $i < m-1$), the cumulative sum equals $S/2$, a horizontal partition is possible.
2.  **Vertical Cuts:** Similarly, we iterate through the columns. We accumulate the sum of elements in each column. If at any column $j$ (where $j < n-1$), the cumulative sum equals $S/2$, a vertical partition is possible.

Given that $m \times n \le 10^5$, a simple linear scan of the grid to calculate total, row, and column sums is efficient. We use `long long` to prevent overflow, as individual elements can be up to $10^5$ and the total number of elements is $10^5$.

### Complexity Analysis

-   **Time Complexity:** $O(m \cdot n)$, where $m$ is the number of rows and $n$ is the number of columns. We visit each cell at most a few times to calculate the total sum, row sums, and column sums.
-   **Space Complexity:** $O(m + n)$ in the worst case to store the sums of rows and columns, although this can be optimized to $O(\max(m, n))$ or even $O(1)$ extra space if we calculate row sums and column sums on the fly. Given the constraints, $O(m+n)$ is well within limits.