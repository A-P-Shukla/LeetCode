# 3742. Maximum Path Score in a Grid

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Dynamic Programming, Matrix
Date | May 22, 2024
LeetCode Link | [https://leetcode.com/problems/maximum-path-score-in-a-grid/](https://leetcode.com/problems/maximum-path-score-in-a-grid/)

## Intuition

The problem asks for the maximum score along a path from the top-left to the bottom-right of a grid, with a constraint on the total "cost." Moving to a cell with value 1 or 2 incurs a cost of 1, while moving to a cell with value 0 costs 0. The movement is restricted to Right and Down.

This is a variation of the classic "Maximum Path Sum" problem but with an added state: the remaining (or accumulated) cost. Since we need to maximize the score while respecting a constraint $k$, and the movement is monotonic (always increasing row or column indices), Dynamic Programming is the ideal choice.

A state can be defined as `dp[i][j][c]`, representing the maximum score achievable reaching cell `(i, j)` with an accumulated cost of exactly `c`.

## Complexity Analysis

- **Time Complexity:** $O(m \times n \times k)$, where $m$ is the number of rows, $n$ is the number of columns, and $k$ is the maximum allowed cost. We iterate through every cell in the grid, and for each cell, we iterate through all possible costs from $0$ to $k$.
- **Space Complexity:** $O(n \times k)$. While the naive DP uses $O(m \times n \times k)$, we can optimize space because calculating the values for row `i` only requires the values from row `i-1` and the current row `i` (previous column `j-1`).