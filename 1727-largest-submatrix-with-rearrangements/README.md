# 1727. Largest Submatrix With Rearrangements

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Greedy, Sorting, Matrix
Date | March 17, 2026
LeetCode Link | [https://leetcode.com/problems/largest-submatrix-with-rearrangements/](https://leetcode.com/problems/largest-submatrix-with-rearrangements/)

### Intuition
The core challenge is that we are allowed to rearrange the **columns** of the matrix. This flexibility suggests that for any given row, if we know how many consecutive '1's exist above each cell (the "height" of a vertical bar of 1s), we can simply group the tallest bars together to form the largest possible rectangle ending at that row.

The algorithm follows these steps:
1.  **Height Precomputation**: Iterate through the matrix row by row. For each cell `(i, j)`, if the value is `1`, calculate the number of consecutive `1`s ending at this cell. This is done by taking the value of the cell above `(i-1, j)` and adding 1. If the cell is `0`, the height is simply 0.
2.  **Greedy Arrangement**: For each row, once we have the heights of all vertical bars ending there, we want to arrange the columns to maximize the area. To do this, sort the heights of the current row in descending order. 
3.  **Area Calculation**: After sorting, for a height at index `k` (0-indexed), we can form a rectangle of height `heights[k]` and width `k + 1`. The area is `heights[k] * (k + 1)`. We track the maximum area found across all rows and all column combinations.

This approach is efficient because sorting allows us to greedily pick the widest possible base for any given height.

### Complexity Analysis
**Time Complexity**: O(M * N log N), where M is the number of rows and N is the number of columns. We iterate through the matrix once to update heights (O(M * N)), and for each of the M rows, we perform a sort (O(N log N)).

**Space Complexity**: O(N) or O(M * N). If we modify the input matrix in place to store heights, we only need O(N) extra space for sorting each row. If we create a separate height matrix, it is O(M * N).