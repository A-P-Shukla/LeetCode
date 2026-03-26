# 3548. Equal Sum Grid Partition II

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Hash Table, Matrix, Enumeration, Prefix Sum
Date | March 26, 2026
LeetCode Link | [https://leetcode.com/problems/equal-sum-grid-partition-ii/](https://leetcode.com/problems/equal-sum-grid-partition-ii/)

## Intuition

The problem asks if we can split an $M \times N$ grid into two non-empty sections using a single horizontal or vertical cut such that their sums are equal, either immediately or after discounting at most one cell. A key constraint is that if a cell is discounted, the remaining portion of that section must stay connected.

### Key Insights:
1.  **Cut Enumeration**: Since the grid size $M \times N \le 10^5$, there are at most $10^5$ possible cuts (horizontal or vertical). We can iterate through every possible cut position.
2.  **Connectivity Constraint**: A rectangular section of dimensions $H \times W$ remains connected after removing a single cell if:
    *   $H > 1$ and $W > 1$: Any cell can be removed, and the remaining cells will stay connected because there are always multiple paths around any single cell in a 2D grid block.
    *   $H = 1, W > 1$: Only the two endpoints (leftmost or rightmost) can be removed.
    *   $H > 1, W = 1$: Only the two endpoints (topmost or bottommost) can be removed.
    *   $H = 1, W = 1$: Removing the only cell leaves an empty set. Since grid values are positive, discounting the only cell would leave a sum of 0, which can never equal the sum of the other (non-empty) section.
3.  **Efficiency**: We use prefix sums (or a running total) and frequency maps to keep track of the available cell values in the current sections. By maintaining these counts as we "sweep" through the rows or columns, we can achieve $O(M \times N)$ time complexity.

## Complexity Analysis

*   **Time Complexity**: $O(M \times N)$. We iterate through the grid once to build a total frequency map, once for horizontal cuts, and once for vertical cuts. Inside the loops, map updates and lookups take $O(1)$ average time (using `unordered_map`) or $O(\log(MN))$ (using `map`).
*   **Space Complexity**: $O(M \times N)$ to store the grid and the frequency maps of elements.